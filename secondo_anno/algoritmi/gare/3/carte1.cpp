#include <vector>
#include <iostream>
#include <unordered_map>

std::vector<std::vector<int> > permut;
unsigned int n, k, t, ans=0;


using namespace std;
template <class T>
std::ostream& operator<<(ostream& os, const vector<T>& v) {
    for (unsigned int i=0; i<v.size(); i++)
        os << v[i] << " ";
    return os;
}

int fact(unsigned int n) {
    if (n<2) return 1;
    return n * fact(n-1);
}


void init(int n, int k, int t, std::vector<int>& tmp) {
    for (int i = 0; i<n; i++) {
        tmp.push_back(1);
        if (t>k) {
            tmp[i] += k;
            t-= k;
        }
        else if (t>0) {
            tmp[i] += t;
            t=0;
        }
    }
}

bool livella(std::vector<int>& tmp, unsigned int i) {
    tmp[i]--;
    int aux = 1;
    for (unsigned int j=i+1; j<tmp.size(); j++) {
        while (aux && tmp[j] < tmp[i]) tmp[j]++, aux--;
        while (tmp[j] > tmp[i]) tmp[j]--, aux++;
    }
    return !aux;
}

void conta(const vector<int>& t) {
    unordered_map<unsigned int, unsigned int> freq;
    unsigned int prod = 1;
    for (unsigned int i=0; i<t.size(); i++)
        freq[t[i]] += 1;
    for (auto p:freq)
        prod *= fact(p.second);
    ans += n/prod;
}

void metodo(std::vector<int> tmp, unsigned int i) {
    if (1 == tmp.size() - i)
        conta(tmp);
    else {
        metodo(tmp, i+1);
        while (livella(tmp, i)) {
            metodo(tmp, i+1);
        }
    }
}


bool cond(std::vector<int>& t, int l, int r) {
    return t[l] > t[r];
}

void metodo(std::vector<int> t) {
    int l=0, r; 
    for (unsigned short int i = 1; i<t.size()-1; i++) {
        l=0, r= l+i;
        while(l>-1) {
            while (r< t.size()) {
                while (cond(t, l, r)) {
                    permut.push_back(t);
                    t[l]--, t[r]++;
                }
                l++, r++;
            }
            l--;r--;
            while (l>-1 && !cond(t, l, r)) {
                l--, r--;
            }
        }
    }
}

    
int main() {
    std::cin >> n >> k >> t;
    std::vector<int> tmp;
    t -= n, k--;
    init(n, k, t, tmp);
    n = fact(n);
    metodo(tmp, 0);
    cout << ans << endl;
    return 0;
}


