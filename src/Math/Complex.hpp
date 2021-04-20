#ifndef COMPLEX
#define COMPLEX

namespace blib{
  template<typename t>
  class complex;
  template<typename t>
  class complex_polar;

  template<>
  class complex<float>;
  template<>
  class complex<double>;
  template<>
  class complex<long double>;

  template<>
  class complex_polar<float>;
  template<>
  class complex_polar<double>;
  template<>
  class complex_polar<long double>;

  template<>
  class complex<float>{
  private:
    using value_type = float;

    float real;
    float imaginary;

    friend complex<double>;
    friend complex<long double>;

  public:
    complex() = default;
    constexpr complex(value_type r, value_type i) : real{ r }, imaginary{ i } {}
    complex(value_type r, complex<value_type> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
    complex(value_type r, complex<double> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
    complex(value_type r, complex<long double> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
    complex(const complex&) = default;
    complex(complex&&) = default;

    template<typename other>
    complex(const complex<other>& co) : real{ static_cast<value_type>(co.real) }, imaginary{ static_cast<value_type>(co.imaginary) } {}
    
    complex& operator =(const complex&) = default;
    complex& operator =(complex&&) = default;

    inline complex operator +(char i) { return complex(real + i, imaginary); }
    inline complex operator +(int i) { return complex(real + i, imaginary); }
    inline complex operator +(long i) { return complex(real + i, imaginary); }
    inline complex operator +(long long i) { return complex(real + i, imaginary); }

    inline complex operator +(float i) { return complex(real + i, imaginary); }
    inline complex operator +(double i) { return complex(real + i, imaginary); }
    inline complex operator +(long double i) { return complex(real + i, imaginary); }

    template<typename other>
    inline complex operator +(complex<other> cf) { 
      return complex(real + static_cast<value_type>(cf.real), imaginary + static_cast<value_type>(cf.imaginary));
    }
  };

  template<>
  class complex<double> {
  private:
      using value_type = double;

      float real;
      float imaginary;

      friend complex<float>;
      friend complex<long double>;

  public:
      complex() = default;
      constexpr complex(value_type r, value_type i) : real{ r }, imaginary{ i } {}
      complex(value_type r, complex<value_type> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
      complex(value_type r, complex<float> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
      complex(value_type r, complex<long double> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
      complex(const complex&) = default;
      complex(complex&&) = default;

      template<typename other>
      complex(const complex<other>& co) : real{ static_cast<value_type>(co.real) }, imaginary{ static_cast<value_type>(co.imaginary) } {}

      complex& operator =(const complex&) = default;
      complex& operator =(complex&&) = default;

      inline complex operator +(char i) { return complex(real + i, imaginary); }
      inline complex operator +(int i) { return complex(real + i, imaginary); }
      inline complex operator +(long i) { return complex(real + i, imaginary); }
      inline complex operator +(long long i) { return complex(real + i, imaginary); }

      inline complex operator +(float i) { return complex(real + i, imaginary); }
      inline complex operator +(double i) { return complex(real + i, imaginary); }
      inline complex operator +(long double i) { return complex(real + i, imaginary); }

      template<typename other>
      inline complex operator +(complex<other> cf) {
          return complex(real + static_cast<value_type>(cf.real), imaginary + static_cast<value_type>(cf.imaginary));
      }
  };

  template<>
  class complex<long double> {
  private:
      using value_type = long double;

      float real;
      float imaginary;

      friend complex<double>;
      friend complex<float>;

  public:
      complex() = default;
      constexpr complex(value_type r, value_type i) : real{ r }, imaginary{ i } {}
      complex(value_type r, complex<value_type> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
      complex(value_type r, complex<double> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
      complex(value_type r, complex<float> c) : real{ r + c.real }, imaginary{ c.imaginary } {}
      complex(const complex&) = default;
      complex(complex&&) = default;

      template<typename other>
      complex(const complex<other>& co) : real{ static_cast<value_type>(co.real) }, imaginary{ static_cast<value_type>(co.imaginary) } {}

      complex& operator =(const complex&) = default;
      complex& operator =(complex&&) = default;

      inline complex operator +(char i) { return complex(real + i, imaginary); }
      inline complex operator +(int i) { return complex(real + i, imaginary); }
      inline complex operator +(long i) { return complex(real + i, imaginary); }
      inline complex operator +(long long i) { return complex(real + i, imaginary); }

      inline complex operator +(float i) { return complex(real + i, imaginary); }
      inline complex operator +(double i) { return complex(real + i, imaginary); }
      inline complex operator +(long double i) { return complex(real + i, imaginary); }

      template<typename other>
      inline complex operator +(complex<other> cf) {
          return complex(real + static_cast<value_type>(cf.real), imaginary + static_cast<value_type>(cf.imaginary));
      }
  };

  complex<float> operator"" _if(long double imaginary) {
    return complex<float>(0, imaginary);
  }

  template<typename T>
  T norm(complex<T> cmplx){
    //sqrt(real^2 + imj^2)
  }

}

#endif