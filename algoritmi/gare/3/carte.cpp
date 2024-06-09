#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
std::vector<std::vector<int> > permut;
using u32 = size_t;

template <class T>
std::ostream& operator<<(ostream& os, const vector<T>& v) {
    for (u32 i=0; i<v.size(); i++)
        os << v[i] << " ";
    return os;
}

int fact(u32 n) {
    if (n<2) return 1;
    return n * fact(n-1);
}

u32 conta(const vector<int>& t) {
    unordered_map<u32,u32> freq;
    u32 prod = 1;
    for (u32 i=0; i<t.size(); i++){
        freq[t[i]] += 1;
    }
    for (const auto& p:freq){
        prod *= fact(p.second);
    }
    return fact(t.size())/prod; 
}

bool livella(std::vector<int>& tmp, u32 i) {
    tmp[i]--;
    int aux = 1;
    for (u32 j=i+1; j<tmp.size(); j++) {
        while (aux && tmp[j] < tmp[i]) tmp[j]++, aux--;
        while (tmp[j] > tmp[i]) tmp[j]--, aux++;
    }
    return !aux;
}

u32 metodo(std::vector<int> tmp, u32 i) {
    u32 ris = 0;
    if (1 == tmp.size() - i)
        ris += conta(tmp);
    else {
        ris += metodo(tmp, i+1);
        while (livella(tmp, i)) {
            ris += metodo(tmp, i+1);
        }
    }
    return ris;
}

int main() {
    u32 n, k, t;
    std::cin >> n >> k >> t;


    std::vector<int> tmp(n);
    t -= n, k--;
    for (int i = 0; i<n; i++) {
        tmp[i]=1;
        if (t>k) {
            tmp[i] += k;
            t-= k;
        }
        else if (t>0) {
            tmp[i] += t;
            t=0;
        }
    }


    cout << metodo(tmp, 0) % 1000000009 << endl;
    return 0;
}

// hello world
