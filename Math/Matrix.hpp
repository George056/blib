#ifndef MATRIX
#define MATRIX

namespace blib{
  template<typename T>
  class matrix;
  template<>
  class matrix<float>;
  template<>
  class matrix<double>;
  template<>
  class matrix<long double>;


  template<>
  class matrix<float>{
  public:
    using value_type = float;
    using size_type = unsigned int;

    matrix() = default;
    matrix(matrix&&) = default;

    matrix& operator =(matrix&&) = default;

    matrix(size_type m, size_type n) : __col{ m }, __row{ n }, __matrix{ new value_type[m*n] } {}
    matrix(size_type m) : __col{ m }, __row{ m }, __matrix{ new value_type[m*m] } {}

    template <typename other>
    matrix(const matrix<other>& mat) : matrix(mat.__col, mat.__row) {
      for(size_type i = 0; i < __col * __row; ++i){
        __matrix[i] = mat.__matrix[i];
      }
    }

  private:
    size_type __col;
    size_type __row;
    value_type* __matrix;
  };
}

#endif