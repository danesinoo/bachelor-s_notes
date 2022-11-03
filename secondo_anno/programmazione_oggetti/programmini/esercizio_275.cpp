#include <iostream>
#include <cmath>

class Point {
    private:
        int x;
        int y;
        int z;
    public: 
        Point(int =0, int =0, int =0);
        Point negate() const;
        int norm() const;
        void print() const;
};

Point::Point(int i, int j, int k) {
    x = i;
    y = j;
    z = k;
}

Point Point::negate() const {
    Point tmp(this->x * -1, this->y * -1, this->z * -1);
    return tmp;
}

int Point::norm() const {
    int tmp = x * x + y * y + z * z;
    return sqrt(tmp);
}

void Point::print() const {
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
}

int main() {
    Point tmp(1, 2, 3);
    std::cout << "modulo: " << tmp.norm() << std::endl;
    tmp.print();
    tmp = Point(1);
    std::cout << "modulo: " << tmp.norm() << std::endl;
    tmp.print();
    return 0;
}
