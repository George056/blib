#ifndef FUNCTIONS
#define FUNCTIONS

#include "Fraction.h"
#include "Constants.h"

namespace blib{

  template <typename return_type>
  return_type abs(return_type);

  /*float absf(float value);
  double abs(double value);
  long double absl(long double value);*/

  template <typename return_type = int>
  class __factorial__{
  public:
    __factorial__() = default;
    return_type operator ()(unsigned int n){
      return n > 1 ? (n * this->operator()(n - 1)) : 1;
    }
  }

  template <typename return_type = int>
  __factorial__<return_type> factorial;

  /*unsigned int factorial(unsigned int i);
  unsigned long factoriall(unsigned long i);
  unsigned long long factorialll(unsigned long long i);*/

  int ceil(double value);
  int floor(double value);
  int round(double value);

  double square(long base);
  long double squarel(long long base);
  double cube(long base);
  long double cubel(long long base);

  double hypo(double leg1, double leg2);
  double leg(double hypot, double leg);

  long gcd(long a, long b);

  long lcm(long a, long b);

  double sqrt(double value);
  long double sqrtl(long double value);

  long double exp(double power);
  long double pow(double base, double power);

  double log(double expo);
  double lg(double expo);
  double ln(double expo);
  double log_base(unsigned int base, double expo);

  float cosf(float value);
  double cos(double value);
  long double cosl(double value);

  float sinf(float value);
  double sin(double value);
  long double sinl(double value);

  float tanf(float value);
  double tan(double value);
  long double tanl(double value);

  float acosf(float value);
  double acos(double value);
  long double acosl(double value);

  float asinf(float value);
  double asin(double value);
  long double asinl(double value);

  float atanf(float value);
  double atan(double value);
  long double atanl(double value);

  float atan2f(float value);
  double atan2(double value);
  long double atan2l(double value);

  float coshf(float value);
  double cosh(double value);
  long double coshl(double value);

  float sinhf(float value);
  double sinh(double value);
  long double sinhl(double value);

  float tanhf(float value);
  double tanh(double value);
  long double tanhl(double value);

  float acoshf(float value);
  double acosh(double value);
  long double acoshl(double value);

  float asinhf(float value);
  double asinh(double value);
  long double asinhl(double value);

  float atanhf(float value);
  double atanh(double value);
  long double atanhl(double value);

  float atanh2f(float value);
  double atanh2(double value);
  long double atanh2l(double value);
}

#endif