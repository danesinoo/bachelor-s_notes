#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int samples;
    std::cin >> samples;
    for (int i=0; i<samples; i++) {
        int n;
        std::cin >> n;
        int* nums= new int[n];
        for (int j=0; j<n; j++) std::cin >> nums[j];


        std::unordered_map<int, unsigned int> index;
        unsigned int l = 0, r=1, count = 0;
        index[nums[0]]=0;
        index[nums[1]]=1;
        for (; r<n; r++) {
            auto c = nums[r];
            if(index.find(c)==index.end() && c > l ){
                l = index[nums[r]]+1;
            }
            index[c] = r;
            count = count < r - l + 1 ? r - l + 1 : count;
        }


        delete[] nums;
        std::cout << count << std::endl;


    }
    return 0;
}


/*
 *
 * set  = { 1, 2, 3, 4 }
 * dict = { 1 : 23, 4 : 2, 5 : 4 }
 * b = {}
 * s = { i for i range(12) }
 * m = {  }
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
