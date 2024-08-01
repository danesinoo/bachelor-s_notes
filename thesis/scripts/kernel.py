import subprocess
from concurrent.futures import ThreadPoolExecutor, as_completed
from sklearn.metrics import (
    accuracy_score, precision_score, recall_score, f1_score
)
from multiprocessing import Manager
import os
import argparse
import json

kernel_to_string = {
    0: 'linear',
    1: 'polynomial',
    2: 'radial',
    3: 'sigmoid',
    5: 'combination of tree forests',
}

TRAIN_PATH = f"multiclass_train.syntax"
MODEL_NAME = f"multiclass_train.syntax"
TEST_LABEL = f"multiclass_subtree_test.sentiment"
TEST_ROOT = f"multiclass_test.syntax"

def run_command(command):
    try:
        result = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        print("Command executed successfully.")
        print("Output:\n", result.stdout.decode())
        if result.stderr:
            print("Error:\n", result.stderr.decode())
    except subprocess.CalledProcessError as e:
        print(f"Command failed with error code {e.returncode}.")
        print("Error:\n", e.stderr.decode())

def train_kernel(train_set, model_name, params):
    cmd = f'../../SVM-Light-TK-1.5/svm_learn -F {KERNEL_TYPE} {params} ../../../datasets/{train_set}.txt {model_name}.model'
    run_command(cmd)

def classify(test_path, model_name, output_path):
    cmd = f'../../SVM-Light-TK-1.5/svm_classify ../../../datasets/{test_path}.txt {model_name}.model {output_path}.results'
    run_command(cmd)

def softmax(x):
    largest = max(x)
    return x.index(largest)

def classify_multiclass(predictions_path, output_path):
    predictions = [[], [], [], [], []]
    for i, p in enumerate(predictions_path):
        with open(f'{p}') as f:
            predictions[i] = list(map(lambda line: float(line),
                                      f.readlines()))
    prediction = list(map(softmax, zip(*predictions)))
    with open(f'{output_path}', 'w') as f:
        f.write('\n'.join(map(str, prediction)))

def get_predictions(predict_file):
    with open(f"{predict_file}.results") as f:
        predictions = list(map(lambda line: float(line), f.readlines()))
    return predictions

def get_targets(target_file):
    with open(f"../../../datasets/{target_file}.txt") as f:
        targets = list(map(lambda line: float(line.split()[0]), f.readlines()))
    return targets

def evaluate_multiclass(y_true, y_pred):
    accuracy = accuracy_score(y_true, y_pred)
    precision = precision_score(y_true, y_pred, average='macro')
    recall = recall_score(y_true, y_pred, average='macro')
    f1 = f1_score(y_true, y_pred, average='macro')
    
    return {
        "Accuracy": accuracy,
        "Precision": precision,
        "Recall": recall,
        "F1-Score": f1
    }

def build_model(kernel_type, decay_factor, normalization, forest_sum, res):
    kernel_type_str = kernel_to_string[kernel_type[0]] + kernel_type[1]
    decay_factor = "-L " + str(decay_factor)
    normalization = "-N " + str(normalization)
    forest_sum = "-W " + str(forest_sum)
    dir = f"{kernel_type_str}_{decay_factor}_{normalization}_{forest_sum}"
    dir = dir.replace(" ", "")
    params = f"-t {kernel_type[0]} {kernel_type[1]} {decay_factor} {normalization} {forest_sum}"

    # Create directory
    os.makedirs(f"{dir}", exist_ok=True)

    # Train and classify
    for i in range(5):
        train_path = TRAIN_PATH + f"_{i}"
        model_name = MODEL_NAME + f"_{i}"
        test_label = TEST_LABEL + f"_{i}"
        test_root = TEST_ROOT + f"_{i}"

        train_kernel(f"{train_path}", f"{dir}/{model_name}", params)
        classify(f"{test_label}", f"{dir}/{model_name}", f"{dir}/{test_label}")
        classify(f"{test_root}", f"{dir}/{model_name}", f"{dir}/{test_root}")

    # Classify multiclass
    predictions_label_paths = [f"{dir}/{TEST_LABEL}_{i}.results" for i in range(5)]
    predictions_root_paths = [f"{dir}/{TEST_ROOT}_{i}.results" for i in range(5)]
    classify_multiclass(predictions_label_paths, f"{dir}/label.results")
    classify_multiclass(predictions_root_paths, f"{dir}/root.results")

    # Evaluate multiclass
    y_true_label = get_targets("subtree_test.sentiment")
    y_true_root = get_targets("test.sentiment")
    y_pred_label = get_predictions(f"{dir}/label")
    y_pred_root = get_predictions(f"{dir}/root")

    results_label = evaluate_multiclass(y_true_label, y_pred_label)
    results_root = evaluate_multiclass(y_true_root, y_pred_root)
    res[dir] = {"label": results_label, "root": results_root}


kernel_types = [
    (0, ""),
    (1, "-d 3 -s 1 -r 1"),
    (2, "-g 1"),
    (3, "-d 3 -s 1 -r 1"),
    (5, ""),
]

decay_factors = [0.2, 0.3, 0.35, 0.4, 0.45, 0.5]
normalizations = [0, 1]
forest_sums = ['A']

iperparams = [(k, decay_factors[3], normalizations[0], forest_sums[0]) for k in kernel_types]

iperparams.extend([(kernel_types[4], d, n, f) 
                   for d in decay_factors 
                   for n in normalizations 
                   for f in forest_sums])

res = dict()
parsers = argparse.ArgumentParser(description="Run SVM-Light-TK with different hyperparameters.")
parsers.add_argument("--kernel", type=int, default=0, help="Kernel type. Values are -1 (PT), 0 (ST), 1 (SST), 2 (SST-bow), 4 (Something hybrid).")
args = parsers.parse_args()

KERNEL_TYPE = args.kernel

if __name__ == "__main__":
    parsers = argparse.ArgumentParser(description="Run SVM-Light-TK with different hyperparameters.")
    parsers.add_argument("--kernel", type=int, default=0, help="Kernel type. Values are -1 (PT), 0 (ST), 1 (SST), 2 (SST-bow), 4 (Something hybrid).")
    args = parsers.parse_args()

    KERNEL_TYPE = args.kernel

    manager = Manager()
    results = manager.dict()
    with ThreadPoolExecutor(max_workers=os.cpu_count()) as executor:
        futures = [executor.submit(build_model, i[0], i[1], i[2], i[3], results) for i in iperparams]
    
        for future in as_completed(futures):
            try:
                future.result()
            except Exception as e:
                print(f"An error occurred: {e}")
    
    print(results)
    final_dict = dict(results)
    with open("results.json", "w") as f:
        json.dump(final_dict, f, indent=4)
