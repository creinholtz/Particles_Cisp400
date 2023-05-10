#include "Matrices.hpp"
#include <assert.h>
using namespace std;

namespace Matrices
{
  Matrix::Matrix(int _rows, int _cols)
  {
    rows = _rows;
    cols = _cols;
    a.resize(_rows, vector<double>(_cols, 0));
  }

  Matrix operator+(const Matrix& a, const Matrix& b)
  {
    Matrix c(a.getRows(), b.getCols());
    if(a.getCols() != b.getCols() || a.getRows() != b.getRows())
      throw runtime_error("Error: dimensions must agree");
    for(size_t i = 0; i < a.getRows(); i++)
    {
      for(size_t j = 0; j < a.getCols(); j++) 
        c(i, j) = a(i, j) + b(i, j); 
    }
    return c;
  }

  Matrix operator*(const Matrix& a, const Matrix& b)
  {
    Matrix c(a.getRows(), b.getCols());
    if(a.getCols() != b.getRows())
      throw runtime_error("Error: dimensions must agree");
    for(size_t i = 0; i < a.getRows(); i++)
    {
      for(size_t k = 0; k < b.getCols(); k++)
      {
        for(size_t j = 0; j < b.getRows(); j++)
          c(i, k) += a(i, j) * b(j, k);
      }
    }
    return c;
  }

  bool operator!=(const Matrix& a, const Matrix& b)
  {
    return !(a == b);
  }

  bool operator==(const Matrix& a, const Matrix& b)
  {
    if(a.getRows() == b.getRows() && a.getCols() == b.getCols())
    {
      for(size_t i = 0; i < a.getRows(); i++)
      {
        for(size_t j = 0; j < a.getCols(); j++)
        {
          if(a(i, j) != b(i, j))
            return false;
        }
      }
      return true;
    }
    else
      return false;
  }

  ostream& operator<<(ostream& os, const Matrix& a)
  {
    for(size_t i = 0; i < a.getRows(); i++)
    {
      for(size_t j = 0; j < a.getCols(); j++) 
        os << setw(11) << right << a(i, j) << " ";           
      os << endl;
    }
    return os;
  }
  
  RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
  {
    //assert(a.at(1).size() > 1);
    a.at(0).at(0) = cos(theta);
    a.at(0).at(1) = -sin(theta);
    a.at(1).at(0) = sin(theta);
    a.at(1).at(1) = cos(theta);
  }

  ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
  {
    a.at(0).at(0) = scale;
    a.at(0).at(1) = 0;
    a.at(1).at(0) = 0;
    a.at(1).at(1) = scale;
  }

  TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
  {
    //assert(a.size() >= nCols);
    for(int i = 0; i < nCols; i++)
    {
      a.at(0).at(i) = xShift;
      a.at(1).at(i) = yShift;
    }
  }
}