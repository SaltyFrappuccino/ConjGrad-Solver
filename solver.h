#ifndef SOLVER_H
#define SOLVER_H

#include "matrix_io.h"

std::vector<double> solveLinearSystem(const CSRMatrix &A, const std::vector<double> &b, double tol = 1e-10);

#endif // SOLVER_H
