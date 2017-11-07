//
// Created by Елена Сермягина on 02.11.2017.
//

#include "matrixU.h"
#include <iostream>
#include <iomanip>

using  namespace std;

//MatrixU::~MatrixU()  {
//
//    nRow_ = 0;
//    nCol_ = 0;
//    delete pData_;
//    pData_ = nullptr;
//
//
//}

MatrixU::MatrixU(): pData_{nullptr} {

}

MatrixU::MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol): nRow_{nRow},
                                                              nCol_{nCol},
                                                              pData_(new int[nCol * nRow])
{
    if (nRow < 0 || nCol < 0) {
        throw("Hey, number of rows/columns can not be less than zero!");
    }
}

MatrixU::MatrixU(const MatrixU &copyMatrixU): nRow_{copyMatrixU.nRow_},
                                              nCol_{copyMatrixU.nCol_},
                                              pData_(new int[nCol_ * nRow_])
{
   pData_ = copyMatrixU.pData_ ;
}

MatrixU MatrixU::operator=(const MatrixU &newMatrix) {

    nRow_ = newMatrix.nRow_;
    nCol_ = newMatrix.nCol_;
    pData_ = new int[nCol_*nRow_];
    pData_ = newMatrix.pData_;
    return *this;

}

MatrixU MatrixU::operator+=(const MatrixU &newMatrix) {

    if (newMatrix.nRow_ != nRow_ || newMatrix.nCol_ != nCol_) {
        throw invalid_argument("You can not sum matrixes with different sizes");
    }
        for (ptrdiff_t i(0); i < nRow_; ++i) {
            for (ptrdiff_t j(0); j < nCol_; ++j) {
                at(i,j) += newMatrix.at(i,j);
            }
        }
    return *this;
}

MatrixU MatrixU::operator-=(const MatrixU &newMatrix) {

    if (newMatrix.nRow_ != nRow_ || newMatrix.nCol_ != nCol_) {
        throw invalid_argument("You can not sum matrixes with different sizes");
    }
    for (ptrdiff_t i(0); i < nRow_; ++i) {
        for (ptrdiff_t j(0); j < nCol_; ++j) {
            at(i,j) -= newMatrix.at(i,j);
        }
    }
    return *this;
}

MatrixU MatrixU::operator*=(const int number) {
    for (ptrdiff_t i(0); i < nRow_; ++i) {
        for (ptrdiff_t j(0); j < nCol_; ++j) {
            at(i,j) *= number;
        }
    }
    return *this;
}


MatrixU MatrixU::operator/=(const int number) {

    if (number == 0) {
        throw invalid_argument("You can not devide by zerooooooo");
    }

    for (ptrdiff_t i(0); i < nRow_; ++i) {
        for (ptrdiff_t j(0); j < nCol_; ++j) {
            at(i,j) /= number;
        }
    }
    return *this;
}

bool MatrixU::operator==(const MatrixU& newMatrix){
    if (newMatrix.nRow_ != nRow_ || newMatrix.nCol_ != nCol_) {
        return false;
    }
    for (ptrdiff_t i(0); i < nRow_; ++i) {
        for (ptrdiff_t j(0); j < nCol_; ++j) {

           if (at(i,j) != newMatrix.at(i,j)) {
               return false;
           }
        }
    }

    return true;
}

bool MatrixU::operator!=(const MatrixU& newMatrix) {
    return !operator==(newMatrix);
}



int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow < 0 || iCol < 0 || iRow >= nRow_ || iCol >= nCol_){
        throw out_of_range("Index was out of range in U");
    }
    return pData_[nCol_*iRow + iCol];
}
const int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow < 0 || iCol < 0 || iRow >= nRow_ || iCol >= nCol_){
        throw out_of_range("Index was out of range in U");
    }
    return pData_[nCol_*iRow + iCol];
}

std::ostream& MatrixU::writeTo(std::ostream& ostrm) const
{

   // ostrm << "{ ";
    cout.setf(ios::fixed);

    for (int i(0); i < nRow_; i++){
        for (int j(0); j < nCol_; j++) {
            ostrm  <<  setw(12) <<pData_[nCol_*i+j] << " ";
        }
       ostrm << endl;
    }
    //ostrm << "}";
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostr, MatrixU matrix)
{
    return matrix.writeTo(ostr);
}

