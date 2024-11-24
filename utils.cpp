#include "utils.h"

double innerProduct(const std::vector<double> &x, const std::vector<double> &y) {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; i++) {
        result += x[i] * y[i];
    }

    return result;
}

double vectorNorm(const std::vector<double> &x) {
    return std::sqrt(innerProduct(x, x));
}

std::vector<double> vectorCombination(double a, const std::vector<double> &x, double b, const std::vector<double> &y) {
    int n = x.size();
    std::vector<double> result(n);

    for (int i = 0; i < n; i++) {
        result[i] = a * x[i] + b * y[i];
    }

    return result;
}

std::vector<double> matrixTimesVector(const CSRMatrix &A, const std::vector<double> &x) {
    int n = A.row_ptr.size() - 1;
    std::vector<double> result(n, 0.0);

    for (int i = 0; i < n; i++) {
        for (int k = A.row_ptr[i]; k < A.row_ptr[i + 1]; k++) {
            result[i] += A.values[k] * x[A.columns[k]];
        }
    }

    return result;
}