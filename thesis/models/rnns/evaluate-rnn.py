import subprocess
import re
import os
import csv

def extract_accuracy_from_output(output):
    # Regular expression to find the accuracy line
    accuracy_pattern = re.compile(r'([0-9.]+)\s*accuracy')
    match = accuracy_pattern.search(output)
    # print(output)
    
    if match:
        return float(match.group(1))
    else:
        raise ValueError("Accuracy not found in the output.")

def get_accuracies_from_models(model_files, folder):
    accuracies = []
    for model_file in model_files:
        try:
            # Define the command
            command = f'mvn exec:java -Dexec.mainClass="edu.stanford.nlp.sentiment.Evaluate" -Dexec.args="-model {folder}/{model_file} -treebank ../test.txt"'
            # Execute the command and capture the output
            result = subprocess.run(command, shell=True, capture_output=True, text=True)
            output = result.stdout
            # Extract accuracy from the output
            accuracy = extract_accuracy_from_output(output)
            accuracies.append((folder, model_file, accuracy))
        except Exception as e:
            print(f"Error in processing model {model_file}: {e}")
            accuracies.append(None)
        print(f"Model {model_file} processed.")
    return accuracies

def list_model_files(folder_path):
    # List all files in the given folder
    return sorted([f for f in os.listdir(folder_path) if
                   os.path.isfile(os.path.join(folder_path, f))])

def save_accuracies_to_csv(accuracies, output_file):
    # Save the accuracies to a CSV file
    with open(output_file, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(['Folder', 'Model File', 'Accuracy'])
        for row in accuracies:
            csvwriter.writerow(row)

# Example usage
folders = [
    "../rnn",
    "../rnn-25",
    "../rnn-50",
    "../rnn-75",
]

all_accuracies = []
for folder in folders:
    model_files = list_model_files(folder)
    accuracies = get_accuracies_from_models(model_files, folder)
    all_accuracies.extend(accuracies)

output_file = "accuracies.csv"
save_accuracies_to_csv(all_accuracies, output_file)
