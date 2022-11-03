#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> get(int size) {
    std::vector<int> tmp(size);
    for (int i=0; i<size; i++)
        std::cin >> tmp[i];
    return tmp;
}

int conta(std::vector<int> N, std::vector<int> M, std::vector<int> K)  {
    if (N.size() < 1 || (M.size() < 1 && K.size() < 1))
        return 0;
    int ans =0;
    if (M.size() > 0 && M[0] < N[0])
        ans++;
    if (K.size()>0 && K[0] <= N[0]) {
        if (M.size() > 0 && K[0] > M[0])
            ans-=2;
        ans+=2;
    }
    if (ans == 1) M.erase(M.begin());
    if (ans > 1) K.erase(K.begin());
    N.erase(N.begin());
    return (ans > 0 ? 1:0) + conta(N, M, K);
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> N= get(n);
    std::vector<int> M= get(m);
    std::vector<int> K= get(k);
    std::sort(M.begin(), M.end());
    std::sort(K.begin(), K.end());
    std::sort(N.begin(), N.end());
    // prendo gli input
    std::cout << conta(N, M, K) << std::endl;
    return 0;
}
