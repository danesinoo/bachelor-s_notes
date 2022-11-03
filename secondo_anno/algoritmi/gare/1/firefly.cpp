#include <iostream>
#include <limits>

int main() {
    int x;
    double y;
    std::cin >> x >> y;
    int n;
    std::cin >> n;
    int tmp1, tmp2;
    double aux, result;
    for (int i=0; i<n; i++) {
        std::cin >> tmp1 >> tmp2 >> aux;
        y -= (tmp2 - tmp1);
        result += (tmp2-tmp1) * aux;
    }   
    std::cout << std::fixed << x/(result + y) << std::endl;
    return 0;
}
