//
// Created by Елена Сермягина on 07.11.2017.
//
#include "matrixR.h"
#include <iostream>
#include <iomanip>

using namespace std;

MatrixR::MatrixR() : pRows_{new int *[nRow_]} {

}

MatrixR::MatrixR(const ptrdiff_t nRow, const ptrdiff_t nCol) {
    if (nRow < 0 || nCol < 0) {
        throw invalid_argument("Hey, number of rows/columns can not be less than zero in R!");
    }

    nRow_ = nRow;
    nCol_ = nCol;
    pRows_ = new int *[nRow];
    for (ptrdiff_t i(0); i < nRow; i += 1) {
        pRows_[i] = new int[nCol];
    }
}

MatrixR::~MatrixR() {

    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        delete[] pRows_[i];
    }
    delete[] pRows_;
    pRows_ = nullptr;
    nRow_ = 0;
    nCol_ = 0;

}

MatrixR::MatrixR(const MatrixR &newMatrix) {
    make(newMatrix);
}

MatrixR& MatrixR::operator=(const MatrixR &newMatrix) {
    make(newMatrix);
    //почистить
    return *this;
}

int &MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol) {
    if (iRow < 0 || iCol < 0 || iRow >= nRow_ || iCol >= nCol_) {
        throw out_of_range("Hey, now way it can be less than zero in R");
    } else if (iRow >= nRow_ || iCol >= nCol_) {
        throw out_of_range("Hey, now way ");
    }

    return pRows_[iRow][iCol];

}

const int &MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const {

    if (iRow < 0 || iCol < 0 || iRow >= nRow_ || iCol >= nCol_) {
        throw out_of_range("Index was out of range in R");
    }

    return pRows_[iRow][iCol];

}


void MatrixR::make(const MatrixR &matrix) {
    nRow_ = matrix.nRow_;
    nCol_ = matrix.nCol_;
    pRows_ = new int *[nRow_];
    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        pRows_[i] = new int[nCol_];
        for (ptrdiff_t j(0); j < nCol_; j += 1) {
            pRows_[i][j] = matrix.pRows_[i][j];
        }
    }
}

std::ostream &MatrixR::writeTo(std::ostream &ostrm) const {


    cout.setf(ios::fixed);

    for (int i(0); i < nRow_; i += 1) {
        for (int j(0); j < nCol_; j += 1) {
            ostrm << setw(12) << pRows_[i][j] << " ";
        }
        ostrm << endl;
    }

    return ostrm;
}

bool MatrixR::operator==(const MatrixR &newMatrix) {
    if (newMatrix.nRow_ != nRow_ || newMatrix.nCol_ != nCol_) {
        return false;
    }
    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        for (ptrdiff_t j(0); j < nCol_; j += 1) {

            if (at(i, j) != newMatrix.at(i, j)) {
                return false;
            }
        }
    }

    return true;
}

bool MatrixR::operator!=(const MatrixR &newMatrix) {
    return !operator==(newMatrix);
}


std::ostream &operator<<(std::ostream &ostr, MatrixR matrix) {
    return matrix.writeTo(ostr);
}