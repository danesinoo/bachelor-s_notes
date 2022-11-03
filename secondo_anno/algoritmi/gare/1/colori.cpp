#include <iostream>
#include <string>

int fatt(int n) {
    if (n < 2) 
        return 1;
    else
        return n * fatt(n-1);
}

int permut(std::string* cols, int ncol, std::string* cups[2], int ncup) {
    int tot = fatt(ncol);
    // come tolgo le coppie?
    return tot;
}

std::string& bestPic(std::string* cols, int ncol, std::string* cups[2], int ncup) {
    // to do
}

int main() {
    int samples;
    std::cin >> samples;
    int ncol;
    int ncup;
    for (int i=0; i<samples; i++) {
        std::cin >> ncol;
        std::string *cols = new std::string[ncol];
        for (int j=0; j<ncol; j++)
            std::cin >> cols[j];
        std::cin >> ncup;
        std::string (*cups)[2] = new std::string[ncup][2];
        // ho finito di prendere gli input
        std::cout << permut(cols, ncol, cups, ncup) << std::endl;
        std::cout << bestPic(cols, ncol, cups, ncup) << std::endl;
        // cancello quello che non mi serve più
        delete[] cols;
        delete[] cups;
    }
    return 0;
}
        
