from kernel import kernel

import os
from concurrent.futures import ThreadPoolExecutor, as_completed

from multiprocessing import Process, Manager
import json

def train_kernel(kernel_type, kernel_fn, decay_factor, normalization,
                 forest_sum, shared_dict):
    model = kernel(kernel_type, kernel_fn, decay_factor, normalization,
                   forest_sum)
    shared_dict[model.name()] = model.test_model()


kernel_types = [-1, 0, 1, 2, 4]

kernel_fns = [
    (0, ""),
    (1, "-d 3 -s 1 -r 1"),
    (2, "-g 1"),
    (3, "-d 3 -s 1 -r 1"),
    (11, ""),
]

decay_factors = [0.2, 0.3, 0.35, 0.4, 0.45, 0.5]
normalizations = [0, 1]
forest_sums = ['A']

if __name__ == '__main__':
    for f in kernel_types:
        manager = Manager()
        results = manager.dict()

        model = kernel(f, kernel_fns[0], 0.4, 0, 'A')
        results[model.name()] = model.test_model()
        model = kernel(f, kernel_fns[1], 0.4, 0, 'A')
        results[model.name()] = model.test_model()
        model = kernel(f, kernel_fns[2], 0.4, 0, 'A')
        results[model.name()] = model.test_model()
        model = kernel(f, kernel_fns[3], 0.4, 0, 'A')
        results[model.name()] = model.test_model()

        with ThreadPoolExecutor(max_workers=os.cpu_count()) as executor:
            futures = [executor.submit(train_kernel, f, (11, ""), d, n, s, results)
                       for d in decay_factors for n in normalizations for s in forest_sums]

            for future in as_completed(futures):
                try:
                    future.result()
                except Exception as e:
                    print(e)

        result = json.dumps(results)
        print(result)

        with open(f"models/{f}_results.txt", "w") as f:
            f.write(result)
