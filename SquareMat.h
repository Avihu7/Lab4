//
// Created by Aviad Benita on 14/03/2024.
//

#ifndef LAB4_SQUAREMAT_H
#define LAB4_SQUAREMAT_H


class SquareMat {
private:
    int **data;
    int ndim;

public:
    // Constructor
    SquareMat(int dim);

    // Copy Constructor
    SquareMat(const SquareMat &other);

    // Destructor
    ~SquareMat();

    // Assignment Operator
    SquareMat& operator=(const SquareMat &other);

    // Method to return the dimension size of the Matrix
    int size() const;

    // Method to return the value from the indexes.
    int at(int row, int col);

    // Method to print the Matrix
    void print() const;

    // Method to compare - if this-matrix > matrix2 return true
    bool compare(const SquareMat &other) const;



};


#endif //LAB4_SQUAREMAT_H
