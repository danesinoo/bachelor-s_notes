#include <iostream>
#include <string>
#include <vector>

void metodo(const std::vector<int>& V, std::vector<int>& Q, std::vector<int>& P) {
    for (unsigned int i = 1; i<V.size(); i++) {
        for (int j = i-1; j>=0; j--) {
            if (V[j] < V[i] && Q[i] <= Q[j]) {
                Q[i] = Q[j] +1; // qui dobbiamo scrivere il max
                P[i] = j;
            }
        }
    }
}

int main() {
    int size;
    std::cin >> size;
    while (size) {
        std::vector<int> V(size); 
        std::vector<int> Q(size); 
        std::vector<int> P(size); 
        for (unsigned int i=0; i<size; i++) {
            std::cin >> V[i];
            Q[i] = 1;
            P[i] = -1;
        }

        metodo(V, Q, P);
        int id_max=0;
        for (unsigned int i= 0; i<V.size(); i++)
            id_max = Q[id_max] < Q[i] || (Q[id_max] == Q[i] && V[id_max] > V[i]) ? i : id_max;
        std::cout << Q[id_max];

        std::string s= "";
        while (id_max > -1) {
            s = " " + std::to_string(V[id_max]) + s;
            id_max = P[id_max];
        }
        std::cout << s << std::endl;
        std::cin >> size;
    }
}


