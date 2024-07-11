from sklearn.metrics import (
    accuracy_score, precision_score, recall_score, f1_score,
    mean_absolute_error, mean_squared_error, r2_score,
    ConfusionMatrixDisplay
)
import numpy as np
import os


def get_predictions(predict_file):
    with open(f"models/kernels/predictions/{predict_file}.results") as f:
        predictions = list(map(lambda line: float(line), f.readlines()))
    return predictions

def get_targets(predict_file):
    target_file = predict_file
    target_file = target_file.replace('train', 'test')
    target_file = target_file.replace('_subtree', '')
    target_file = target_file.replace('subtree_', '')
    if 'label' in target_file:
        target_file = target_file.replace('_label', '')
        target_file = target_file.replace('test', 'subtree_test')
        target_file = target_file.replace('merged', 'sentiment')
        target_file = target_file.replace('syntax', 'sentiment')
    elif 'root' in target_file:
        target_file = target_file.replace('_root', '')

    with open(f"datasets/{target_file}.txt") as f:
        targets = list(map(lambda line: float(line.split()[0]), f.readlines()))
    return targets

def evaluate_binary(y_true, y_pred):
    accuracy = accuracy_score(y_true, y_pred)
    precision = precision_score(y_true, y_pred)
    recall = recall_score(y_true, y_pred)
    f1 = f1_score(y_true, y_pred)
    
    return {
        "Accuracy": accuracy,
        "Precision": precision,
        "Recall": recall,
        "F1-Score": f1
    }

def evaluate_regression(y_true, y_pred):
    mae = mean_absolute_error(y_true, y_pred)
    mse = mean_squared_error(y_true, y_pred)
    r2 = r2_score(y_true, y_pred)
    
    return {
        "Mean Absolute Error": mae,
        "Mean Squared Error": mse,
        "R-squared": r2
    }

def evaluate_multiclass(y_true, y_pred):
    accuracy = accuracy_score(y_true, y_pred)
    precision = precision_score(y_true, y_pred, average='macro')
    recall = recall_score(y_true, y_pred, average='macro')
    f1 = f1_score(y_true, y_pred, average='macro')
    _ = ConfusionMatrixDisplay.from_predictions(y_true, y_pred)

    
    return {
        "Accuracy": accuracy,
        "Precision": precision,
        "Recall": recall,
        "F1-Score": f1
    }

def is_binary(y_true):
    return len(np.unique(y_true)) == 2

def evaluate_label(model_name):
    y_true = get_targets(model_name)
    y_pred = get_predictions(model_name)

    if 'regression' in model_name:
        metrics[model_name] = evaluate_regression(y_true, y_pred)
    elif 'binary' in model_name or 'multiclass' in model_name:
        y_true = [1 if x > 0 else 0 for x in y_true]
        y_pred = [1 if x > 0 else 0 for x in y_pred]
        metrics[model_name] = evaluate_binary(y_true, y_pred)
    else:
        metrics[model_name] = evaluate_multiclass(y_true, y_pred)

def evaluate_root(model_name):
    y_true = get_targets(model_name)
    y_pred = get_predictions(model_name)

    if 'regression' in model_name:
        metrics[model_name] = evaluate_regression(y_true, y_pred)
    elif 'binary' in model_name or 'multiclass' in model_name:
        y_true = [1 if x > 0 else 0 for x in y_true]
        y_pred = [1 if x > 0 else 0 for x in y_pred]
        metrics[model_name] = evaluate_binary(y_true, y_pred)
    else:
        metrics[model_name] = evaluate_multiclass(y_true, y_pred)

def evaluate_kernel(model_name):
    y_true = get_targets(model_name)
    y_pred = get_predictions(model_name)

    if 'regression' in model_name:
        metrics[model_name] = evaluate_regression(y_true, y_pred)
    elif 'binary' in model_name or 'multiclass' in model_name:
        y_true = [1 if x > 0 else 0 for x in y_true]
        y_pred = [1 if x > 0 else 0 for x in y_pred]
        metrics[model_name] = evaluate_binary(y_true, y_pred)
    else:
        metrics[model_name] = evaluate_multiclass(y_true, y_pred)

def print_metrics(model_metrics):
# Print the metrics for each model
    for model_name, metrics in model_metrics.items():
        print(f"Metrics for {model_name}:")
        for metric, value in metrics.items():
            print(f"  {metric}: {value:.2f}")
        print()  # Blank line for readability

def write_metrics(model_metrics):
    lst = list(model_metrics.items())
    lst.sort()
    with open("models/kernels/metrics.txt", 'w') as f:
        for model_name, metrics in lst:
            f.write(f"Metrics for {model_name}:\n")
            for metric, value in metrics.items():
                f.write(f"  {metric}: {value:.2f}\n")
            f.write('\n')  # Blank line for readability

if __name__ == "__main__":
    directory = 'models/kernels/predictions'
    entries = os.listdir(directory)
    metrics = {}
    entries.sort()

    for e in entries:
        set_name = e.replace('.results', '')
        evaluate_kernel(set_name)
        write_metrics(metrics)
