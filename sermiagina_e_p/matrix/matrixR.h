//
// Created by Елена Сермягина on 07.11.2017.
//

#ifndef MATRIX_MATRIXR_H
#define MATRIX_MATRIXR_H

#include <iosfwd>
#include <cstddef>

class MatrixR {

public:
    MatrixR();
    ~MatrixR();
    MatrixR(const ptrdiff_t nRow, const ptrdiff_t nCol);
    MatrixR(const MatrixR& newMatrix);
    MatrixR operator=(const MatrixR& newMatrix);
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    //void clear();
    void make(const MatrixR& matrix);
    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    int** pRows_{nullptr};
    ptrdiff_t nRow_{0};
    ptrdiff_t nCol_{0};



};

std::ostream& operator<<(std::ostream& ostr, MatrixR matrix);


#endif //MATRIX_MATRIXR_H
