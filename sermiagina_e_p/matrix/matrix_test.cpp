//
// Created by Елена Сермягина on 02.11.2017.
//
#include "matrixU.h"
#include "matrixR.h"
#include <iostream>
#include <iomanip>

using namespace std;


void test(const int rowNumber, const int colNumber) {

    cout << endl << endl << "Once upon a time there were two different matrices' realizations." << endl <<
         "First one I'll call MatrixU while the second one MatrixR." << endl <<
         "It means that in each section there will be 2 matrices. " << endl << endl;

    MatrixR matrixR;
    MatrixU matrixU;
    cout << "Here comes an empty one:" << endl << endl << matrixU << endl << matrixR << endl;

    MatrixR matrixR1(rowNumber, colNumber);
    MatrixU matrixU1(rowNumber, colNumber);
    cout << "Here comes the constructor with columns and rows: " << endl << endl << matrixU1 << endl << matrixR1
         << endl;

    MatrixR matrixCopyR(matrixR1);
    MatrixU matrixCopyU(matrixU1);
    cout << "Welcome copy constructor: " << endl << endl << matrixCopyU << endl << matrixCopyR << endl;

    MatrixU matrixEqualU = matrixCopyU;
    MatrixR matrixEqualR = matrixCopyR;
    cout << "Finally, take a look at assignment operator: " << endl << endl << matrixEqualU << endl << matrixEqualR
         << endl;


    MatrixU matrixTestU(rowNumber, colNumber);
    for (ptrdiff_t i(0); i < rowNumber; ++i) {
        for (ptrdiff_t j(0); j < colNumber; ++j) {
            matrixTestU.at(i, j) = i + j + 10000;
        }
    }

    MatrixR matrixTestR(rowNumber, colNumber);
    for (ptrdiff_t i(0); i < rowNumber; ++i) {
        for (ptrdiff_t j(0); j < colNumber; ++j) {
            matrixTestR.at(i, j) = i + j + 20000;
        }
    }
    cout << "And now let's look at some custom numbers where MatrixU will take row + column index + 10000 and "
            " MatrixR + 20000 :" << endl << endl << matrixTestU << endl << matrixTestR << endl;


    MatrixU matrixNewU(rowNumber, colNumber);
    for (ptrdiff_t i(0); i < rowNumber; ++i) {
        for (ptrdiff_t j(0); j < colNumber; ++j) {
            matrixNewU.at(i, j) = i + j + 5000;
        }
    }

    MatrixR matrixNewR(rowNumber, colNumber);
    for (ptrdiff_t i(0); i < rowNumber; ++i) {
        for (ptrdiff_t j(0); j < colNumber; ++j) {
            matrixNewR.at(i, j) = i + j + 15000;
        }
    }
    cout << "Matrices feel lonely without any friends, so, now we'll make two new matrices: one U and one R:"
         << endl << endl << matrixNewU << endl << matrixNewR << endl;
    cout << endl << "And now we'll make them live together: " << endl << endl;
    matrixNewU += matrixTestU;
    cout << matrixNewU << endl << endl;


    cout << "Matrices' values at row #" << rowNumber << " and column #" << colNumber << " is " <<
         matrixTestU.at(rowNumber - 1, colNumber - 1) << " and " << matrixTestR.at(rowNumber - 1, colNumber - 1) << endl
         << endl;

    cout << "Let's try some interesting things. I'll try to get matrix' value at index #" << 5 <<
         " than is more than #" << colNumber << ". And it says: " << endl;
    try {
        matrixTestR.at(5, 5);
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }
    try {
        matrixTestU.at(5, 5);
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }


}


int main() {
    test(3, 3);


    try {

        MatrixR badMatrixR(-2, 3);

    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }

    try {

        MatrixU badMatrixU(-2, 3);

    } catch (invalid_argument &a) {
        cout << a.what() << endl;
    }


    return 0;
}

