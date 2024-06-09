#include <iostream>
#include <vector>
#include <algorithm>

bool isLim(std::vector<int>& arr, int i) {
    return (arr[i] >= arr.size() - i);
}

int hRef(std::vector<int>& p, int l, int r) {
    if (l > r)
        return 0;
    else {
//        std::cout << p[l] << " " << p[r] << std::endl;
        int mid = (l + r)/2;
        bool tmp1 = isLim(p, mid);
        bool tmp2 = isLim(p, mid-1);
        std::cout << p[mid] << " " << tmp1 << " " << tmp2 << std::endl;
        if (tmp1 && !tmp2)
            return p.size() - mid;
        if (tmp2)
            return hRef(p, l, mid-1);
        else
            return hRef(p, mid+1, r);
    }
}
        
int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i=0; i<n; i++)
        std::cin >> p[i];
    std::sort(p.begin(), p.end());
    for (int i= 0; i < p.size(); i++)
        std::cout << p[i] << " ";
    std::cout << std::endl;
    std::cout << hRef(p, 0, p.size()-1);

    return -1;
}

/* 
 * 5
7
1
2
1
5
*/
