#include <iostream>

int main() {
    int n, l;
    std::cin >> n >> l;
    int (*sem)[3]= new int[n][3];
    for (int i=0; i<n; i++)
        std::cin >> sem[i][0] >> sem[i][1] >> sem[i][2];

    int time = 0, distanza = 0;
    for (int i=0; i<n; i++) {
        time += sem[i][0] - distanza;
        distanza = sem[i][0];
        time = time % (sem[i][1] + sem[i][2]) > sem[i][1] ? time : time + sem[i][1] - (time % (sem[i][1] + sem[i][2]));
    }
    std::cout << time + l - distanza << std::endl;
}

