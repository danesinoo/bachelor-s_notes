#include <iostream>
#include "conta.h"
#include <cmath>
//da rivedere


double devianza(const double& elm, const double& media) {
    return (media - elm) * (media - elm);
}


void print(const double& elm) {
    std::cout << elm << std::endl;
}

int main() {
    const unsigned int size = 10;
    double tmp[size];
    for (int i=0; i<10; i++)
        tmp[i] = i* 3.14563;
    double media = iter<double>(size, tmp).count() / size;
    double dev = iter<double>(size, tmp).map(devianza, media).mapRef(print).count();
    std::cout << "media: " << media << std::endl;
    std::cout << "varianza: " << sqrt(dev) << std::endl;
    return 0;
}

// se utilizzo mapRef, al momento della deallocazione, dealloca una volta di
// troppo. Per quale motivo?
