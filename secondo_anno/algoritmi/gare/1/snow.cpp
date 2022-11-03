#include <iostream>
#include <unordered_map>

int longest(int *nums, int n) {
    if (n==0) return 0;
    std::unordered_map<int, unsigned int> index;
    unsigned int l = 0, count = 0;
    for (unsigned int r=0; r<n; r++) {
        if (!index[nums[r]] || index[nums[r]] < l) {
            index[nums[r]] = r+1;
            count = count < r - l ? r - l : count;
        }
        else {
            l = index[nums[r]] > l ? index[nums[r]] : l;
            index[nums[r]] = r+1;
        }
    }
    return count +1;
}

int main() {
    int samples;
    std::cin >> samples;
    for (int i=0; i<samples; i++) {
        int n;
        std::cin >> n;
        int* nums= new int[n];
        for (int j=0; j<n; j++) std::cin >> nums[j];
        std::cout << longest(nums, n) << std::endl;
        delete[] nums;
    }
    return 0;
}

