//
// Created by Елена Сермягина on 02.11.2017.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iosfwd>
#include <cstddef>

class MatrixU {

public:
    ~MatrixU() = default;
    MatrixU();
    MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol);
    MatrixU(const MatrixU& copyMatrixU);
    bool operator==(const MatrixU& newMatrix);
    bool operator!=(const MatrixU& newMatrix);
    MatrixU operator=(const MatrixU& newMatrix);
    MatrixU operator+=(const MatrixU& newMatrix);
    MatrixU operator-=(const MatrixU& newMatrix);
    MatrixU operator*=(const int number);
    MatrixU operator/=(const int number);




    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const; //проверить валидность индексов
    std::ostream& writeTo(std::ostream& ostrm) const;



private:
    ptrdiff_t nRow_{0};
    ptrdiff_t nCol_{0};
    int* pData_{nullptr};


};

std::ostream& operator<<(std::ostream& ostr, MatrixU matrix);






#endif //MATRIX_MATRIX_H
