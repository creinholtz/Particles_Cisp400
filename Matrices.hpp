#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

namespace Matrices
{
  class Matrix
  {
    public:
      Matrix(int _rows, int _cols);
      const double& operator()(int i, int j) const {return a.at(i).at(j);}
      double& operator()(int i, int j) {return a.at(i).at(j);}
      int getRows() const {return rows;}
      int getCols() const {return cols;}
    protected:
      vector<vector<double>> a;
    private:
      int rows;
      int cols;
  };
  Matrix operator+(const Matrix& a, const Matrix& b);
  Matrix operator*(const Matrix& a, const Matrix& b);
  bool operator==(const Matrix& a, const Matrix& b);
  bool operator!=(const Matrix& a, const Matrix& b);
  std::ostream& operator<<(std::ostream& os, const Matrix& a);

  ///2D rotation matrix
  ///usage: A = R * A rotates A theta radians counter-clockwise
  class RotationMatrix : public Matrix
  {
    public:
      RotationMatrix(double theta);
  };
  
  ///2D scaling matrix
  ///usage: A = S * A expands or contracts A by the specified scaling factor
  class ScalingMatrix : public Matrix
  {
    public:
      ScalingMatrix(double scale);
  };
  
  ///2D Translation matrix
  ///usage: A = T + A will shift all coordinates of A by (xShift, yShift)
  class TranslationMatrix : public Matrix
  {
    public:
      TranslationMatrix(double xShift, double yShift, int nCols);
  };
}

#endif