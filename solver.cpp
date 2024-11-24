#include "solver.h"
#include <algorithm>
#include <iostream>

#include "utils.h"

std::vector<double> solveLinearSystem(const CSRMatrix &A, const std::vector<double> &b, double tol) {
    double TOLERANCE = 1.0e-10;
    int n = A.row_ptr.size() - 1;
    std::vector<double> X(n, 0.0);
    std::vector<double> R = b;
    std::vector<double> P = R;
    int k = 0;

    while (k < n) {
        std::vector<double> Rold = R;
        std::vector<double> AP = matrixTimesVector(A, P);
        double alpha = innerProduct(R, R) / std::max(innerProduct(P, AP), TOLERANCE);

        if (std::isnan(alpha)) {
            std::cerr << "Error: alpha is NaN" << std::endl;
            break;
        }

        X = vectorCombination(1.0, X, alpha, P);
        R = vectorCombination(1.0, R, -alpha, AP);

        if (vectorNorm(R) < tol) break;

        double beta = innerProduct(R, R) / std::max(innerProduct(Rold, Rold), TOLERANCE);
        P = vectorCombination(1.0, R, beta, P);
        k++;
    }

    return X;
}
