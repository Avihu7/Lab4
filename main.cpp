#include <iostream>
#include "SquareMat.cpp"

int main() {
    SquareMat mat1(3);
    SquareMat mat2(9);
    if (mat1.compare(mat2)){
        return 1;
    };
    return 0;
}
