//
// Created by Aviad Benita on 14/03/2024.
//

#include "SquareMat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor

SquareMat::SquareMat(int dim) : ndim(dim) {
    data = new int*[ndim];
    for (int i=0; i<ndim; i++) {
        data[i] = new int[ndim];
        for (int j=0; j<ndim; j++) {
            data[i][j] = rand() % 900 + 100; // random value in [100,999]
        }
    }
    std::cout << "C'tor" << std::endl;
}

// Copy Constructor

SquareMat::SquareMat(const SquareMat &other) : ndim(other.ndim) {
    data = new int*[ndim];
    for (int i = 0; i < ndim; ++i) {
        data[i] = new int[ndim];
        for (int j = 0; j<ndim; ++j){
            data[i][j] = other.data[i][j];
        }
    }
    std::cout << "Copy C'tor" << std::endl;
}

// Destructor
SquareMat::~SquareMat() {
    for (int i=0; i<ndim; ++i){
        delete[] data[i];
    }
    delete[] data;
}


// Assignment Operator
SquareMat &SquareMat::operator=(const SquareMat &other) {
    if(this == &other){ // Self-assignment check
        return *this;
    }

    // Deallocate existing memory
    for (int i = 0; i < ndim; ++i){
        delete[] data[i];
    }
    delete[] data;

    // Allocate new memory and copy data
    ndim = other.ndim;
    data = new int*[ndim];
    for (int i=0; i<ndim; ++i){
        data[i] = new int[ndim];
        for (int j=0; j<ndim; ++j) {
            data[i][j] = other.data[i][j];
        }
    }

    std::cout << "operator=" << std::endl;
    return *this;
}

// Return the size dimension of the Matrix
int SquareMat::size() const {
    return ndim;
}

int SquareMat::at(int row, int col) {
    if (row>=0 && row<ndim && col>=0 && col<ndim){
        return data[row][col];
    }
    return -1;
}

void SquareMat::print() const {
    for (int i=0; i<ndim; ++i){
        for (int j=0; j<ndim; ++j){
            std::cout << data[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool SquareMat::compare(const SquareMat &other) const {
    int cntMat1 = 0;
    for (int i=0; i<ndim; ++i){
        for (int j=0; j<ndim; ++j){
            cntMat1 += data[i][j];
        }
    }
    int cntMat2 = 0;
    for (int i=0; i<other.ndim; ++i){
        for (int j=0; j<other.ndim; ++j){
            cntMat2 += other.data[i][j];
        }
    }
    return (cntMat1 < cntMat2);
}





























