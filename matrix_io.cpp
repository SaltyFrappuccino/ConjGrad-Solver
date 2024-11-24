#include "matrix_io.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

CSRMatrix convertToCSRFormat(const std::vector<std::vector<double>> &matrix) {
    CSRMatrix csrMatrix;
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();

    csrMatrix.row_ptr.push_back(0);

    for (int i = 0; i < num_rows; i++) {
        int nonzero_count = 0;
        for (int j = 0; j < num_cols; j++) {
            if (matrix[i][j] != 0.0) {
                csrMatrix.values.push_back(matrix[i][j]);
                csrMatrix.columns.push_back(j);
                nonzero_count++;
            }
        }
        csrMatrix.row_ptr.push_back(csrMatrix.row_ptr.back() + nonzero_count);
    }

    return csrMatrix;
}

void readMatrixFromFile(const std::string &filename, CSRMatrix &csrMatrix) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open the file.");
    }

    int num_rows, num_cols, num_elements;

    while (file.peek() == '%') {
        file.ignore(2048, '\n');
    }

    file >> num_rows >> num_cols >> num_elements;

    csrMatrix.row_ptr.assign(num_rows + 1, 0);

    std::vector<std::vector<std::pair<int, double>>> rows(num_rows);

    for (int i = 0; i < num_elements; i++) {
        int row, col;
        double value;
        file >> row >> col >> value;
        rows[row - 1].emplace_back(col - 1, value);
    }

    for (int i = 0; i < num_rows; i++) {
        for (const auto &[fst, snd] : rows[i]) {
            csrMatrix.values.push_back(snd);
            csrMatrix.columns.push_back(fst);
        }
        csrMatrix.row_ptr[i + 1] = csrMatrix.values.size();
    }

    file.close();
}

CSRMatrix readMatrixFromInput() {
    std::cout << "Enter the number of rows and columns: ";
    int num_rows, num_cols;
    std::cin >> num_rows >> num_cols;

    std::vector<std::vector<double>> matrix(num_rows, std::vector<double>(num_cols, 0.0));

    std::cout << "Enter nonzero elements as (row, column, value):\n";
    int row, col;
    double value;
    while (std::cin >> row >> col >> value) {
        matrix[row - 1][col - 1] = value;
    }

    return convertToCSRFormat(matrix);
}

void printMatrix(const CSRMatrix &csrMatrix) {
    std::cout << "Matrix in CSR Format:" << std::endl;
    for (size_t i = 0; i < csrMatrix.values.size(); i++) {
        std::cout << csrMatrix.values[i] << " ";
    }
    std::cout << std::endl;
}
