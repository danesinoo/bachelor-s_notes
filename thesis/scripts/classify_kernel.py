import subprocess
import os
from concurrent.futures import ThreadPoolExecutor, as_completed

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

def classify_kernel(test_path, model_name, output_path):
    cmd = f'./models/SVM-Light-TK-1.5/svm_classify datasets/{test_path}.txt models/kernels/{model_name}.model models/kernels/predictions/{output_path}.results'
    run_command(cmd)

classify_kernel("multiclass_test.merged_2", "multiclass_train.merged_2", "classification")

# def main():
#     directory = 'models/kernels'
#     entries = os.listdir(directory)
#     entries = list(filter(lambda x: x.endswith('.model') and "train" in x, entries))
# 
#     params = []
#     for i in entries:
#         model_name = i.replace('.model', '')
#         root_path = model_name.replace('train', 'test')
#         root_path = root_path.replace('_subtree', '')
#         root_path = root_path.replace('subtree_', '')
#         root_output_path = model_name + '_root'
#         params.append((root_path, model_name, root_output_path))
#         label_path = root_path.replace('test', 'subtree_test')
#         label_path = label_path.replace('merged', 'sentiment')
#         label_path = label_path.replace('syntax', 'sentiment')
#         label_output_path = model_name + '_label'
#         params.append((label_path, model_name, label_output_path))
# 
#     classify_kernel(params[0][0], params[0][1], params[0][2])
# 
#     # with ThreadPoolExecutor(max_workers=os.cpu_count()) as executor:
#     #     futures = [executor.submit(classify_kernel, e[0], e[1], e[2]) for e in
#     #                params]
#     #     for future in as_completed(futures):
#     #         try:
#     #             future.result()
#     #         except Exception as e:
#     #             print(f"An error occurred: {e}")
# 
# if __name__ == "__main__":
#     main()

