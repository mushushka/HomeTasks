//
// Created by Елена Сермягина on 02.11.2017.
//

#include "matrixU.h"
#include <iostream>
#include <iomanip>

using namespace std;

MatrixU::MatrixU() : pData_{nullptr} {

}

MatrixU::MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol) {
    if (nRow < 0 || nCol < 0) {
        throw invalid_argument("Hey, number of rows/columns can not be less than zero in U!");
    }

    nRow_ = nRow;
    nCol_ = nCol;
    pData_ = new int[nCol * nRow];
}

MatrixU::MatrixU(const MatrixU &copyMatrixU) {
    make(copyMatrixU);
}

MatrixU& MatrixU::operator=(const MatrixU &newMatrix) {

    make(newMatrix);
    return *this;

}

void MatrixU::make(const MatrixU &matrix) {
    nRow_ = matrix.nRow_;
    nCol_ = matrix.nCol_;
    pData_ = new int[nCol_ * nRow_];
    pData_ = matrix.pData_;
}

MatrixU& MatrixU::operator+=(const MatrixU &newMatrix) {

    if (newMatrix.nRow_ != nRow_ || newMatrix.nCol_ != nCol_) {
        throw invalid_argument("You can not sum matrixes with different sizes");
    }
    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        for (ptrdiff_t j(0); j < nCol_; j += 1) {
            at(i, j) += newMatrix.at(i, j);
        }
    }
    return *this;
}

MatrixU& MatrixU::operator-=(const MatrixU &newMatrix) {

    if (newMatrix.nRow_ != nRow_ || newMatrix.nCol_ != nCol_) {
        throw invalid_argument("You can not substract matrixes with different sizes");
    }
    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        for (ptrdiff_t j(0); j < nCol_; j += 1) {
            at(i, j) -= newMatrix.at(i, j);
        }
    }
    return *this;
}

MatrixU& MatrixU::operator*=(const int number) {
    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        for (ptrdiff_t j(0); j < nCol_; j += 1) {
            at(i, j) *= number;
        }
    }
    return *this;
}


MatrixU& MatrixU::operator/=(const int number) {

    if (number == 0) {
        throw invalid_argument("You can not devide by zerooooooo");
    }

    for (ptrdiff_t i(0); i < nRow_; i += 1) {
        for (ptrdiff_t j(0); j < nCol_; j += 1) {
            at(i, j) /= number;
        }
    }
    return *this;
}

bool MatrixU::operator==(const MatrixU &newMatrix) {
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

bool MatrixU::operator!=(const MatrixU &newMatrix) {
    return !operator==(newMatrix);
}


int &MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol) {
    if (iRow < 0 || iCol < 0 || iRow >= nRow_ || iCol >= nCol_) {
        throw out_of_range("Index was out of range in U");
    }
    return pData_[nCol_ * iRow + iCol];
}

const int &MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const {
    if (iRow < 0 || iCol < 0 || iRow >= nRow_ || iCol >= nCol_) {
        throw out_of_range("Index was out of range in U");
    }
    return pData_[nCol_ * iRow + iCol];
}

std::ostream &MatrixU::writeTo(std::ostream &ostrm) const {


    cout.setf(ios::fixed);

    for (int i(0); i < nRow_; i += 1) {
        for (int j(0); j < nCol_; j += 1) {
            ostrm << setw(12) << pData_[nCol_ * i + j] << " ";
        }
        ostrm << endl;
    }
    return ostrm;
}

std::ostream &operator<<(std::ostream &ostr, MatrixU matrix) {
    return matrix.writeTo(ostr);
}

