#ifndef MATRIX
#define MATRIX

#include "..\Containers\Array.hpp"

namespace blib{
  template<typename T, size_t rows, size_t cols>
  class matrix;
  template<>
  class matrix<float, size_t rows, size_t cols>;
  template<>
  class matrix<double, size_t rows, size_t cols>;
  template<>
  class matrix<long double, size_t rows, size_t cols>;


  template<>
  class matrix<float, size_t rows, size_t cols>{
  public:
    using value_type = float;
    using size_type = unsigned int;

    matrix() = default;
    matrix(const matrix&) = default;
    matrix(matrix&&) = default;

    matrix& operator =(cosnt matrix&) = default;
    matrix& operator =(matrix&&) = default;

    matrix& operator +(const matrix& r) const {
      matrix result;

      return result;
    }

  private:
    size_type __col;
    size_type __row;
    array<array<double, cols>, rows> __2DArray;
  };
}

#endif