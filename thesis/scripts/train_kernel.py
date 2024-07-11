import subprocess
import os
from concurrent.futures import ThreadPoolExecutor, as_completed

def run_command(command):
    try:
        result = subprocess.run(command, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        print(f"Command executed successfully: {command}")
        print("Output:\n", result.stdout.decode())
        if result.stderr:
            print("Error:\n", result.stderr.decode())
    except subprocess.CalledProcessError as e:
        print(f"Command failed with error code {e.returncode}. Command: {command}")
        print("Error:\n", e.stderr.decode())

def train_kernel(train_set):
    cmd = f'./models/SVM-Light-TK-1.5/svm_learn -t 5 datasets/{train_set}.txt models/kernels/{train_set}.model'
    run_command(cmd)

def main():
    directory = 'datasets'
    entries = os.listdir(directory)
    entries = list(filter(lambda x: x.endswith('.txt') and "train" in x, entries))

    with ThreadPoolExecutor(max_workers=os.cpu_count()) as executor:
        futures = [executor.submit(train_kernel, e.replace('.txt', '')) for e in entries]
        for future in as_completed(futures):
            try:
                future.result()
            except Exception as e:
                print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
