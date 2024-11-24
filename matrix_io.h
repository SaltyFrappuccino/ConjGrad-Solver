#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include <vector>
#include <string>

struct CSRMatrix {
    std::vector<double> values;
    std::vector<int> columns;
    std::vector<int> row_ptr;
};

CSRMatrix convertToCSRFormat(const std::vector<std::vector<double>> &matrix);
void readMatrixFromFile(const std::string &filename, CSRMatrix &csrMatrix);
CSRMatrix readMatrixFromInput();
void printMatrix(const CSRMatrix &csrMatrix);

#endif // MATRIX_IO_H
