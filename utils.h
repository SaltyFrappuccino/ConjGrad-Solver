#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <cmath>

#include "matrix_io.h"

double innerProduct(const std::vector<double> &x, const std::vector<double> &y);
double vectorNorm(const std::vector<double> &x);
std::vector<double> vectorCombination(double a, const std::vector<double> &x, double b, const std::vector<double> &y);
std::vector<double> matrixTimesVector(const CSRMatrix &A, const std::vector<double> &x);

#endif //UTILS_H
