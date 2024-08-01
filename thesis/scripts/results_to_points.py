import json
import re

MODEL = 'models/'

def get_results(kernel_type):
    """
        Get the results from the file, the file is a json
    """
    with open(kernel_type + '/results.json') as f:
        data = json.load(f)
    return data

results = get_results(MODEL + 'sentiment/moschitti')
for params in results:
    if not 'combination' in params or not 'N1' in params:
        continue

    match = re.search('L(\d+.\d+)', params)
    if match:
        decay_factor = match.group(1)
        accuracy = results[params]["root"]["Accuracy"]
        accuracy = float(accuracy)
        accuracy = accuracy * 100
        point = f'({decay_factor}, {accuracy})'
        print(point)
