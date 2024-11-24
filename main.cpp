#include "matrix_io.h"
#include "solver.h"
#include <iostream>
#include <bits/fs_fwd.h>
#include <bits/fs_path.h>

int main() {
    try {
        CSRMatrix csrMatrix;
        std::cout << "Choose input method: (1) File or (2) Manual: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
            std::cout << "Enter file path:  ";
            std::string filename;
            std::cin >> filename;
            std::cout << filename;
            readMatrixFromFile(filename, csrMatrix);
        } else {
            csrMatrix = readMatrixFromInput();
        }

        const int num_rows = csrMatrix.row_ptr.size() - 1;
        const std::vector<double> b(num_rows, 1.0);

        printMatrix(csrMatrix);

        auto solution = solveLinearSystem(csrMatrix, b);
        std::cout << "Solution:\n";
        for (const auto &val : solution) {
            std::cout << val << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
