#include "Functions.h"

namespace blib{

  template <typename return_type>
  return_type abs(return_type value){
    return (value > 0) ? value : -value;
  }

  VALUE_TYPE get_e(size_t times){
    VALUE_TYPE result;
    for(size_t i = 0; times > i; ++i){
      result += 1.0/(VALUE_TYPE)factorial<int>(i);
    }
    return result;
  }

  /*float absf(float value){
    return (value >= 0) ? value : -value;
  }
  double abs(double value){
    return (value >= 0) ? value : -value;
  }
  long double absl(long double value){
    return (value >= 0) ? value : -value;
  }*/

  /*unsigned int factorial(unsigned int i){
    unsigned int result = 1;
    while(i > 1){
      result *= i--;
    }
    return result;
  }
  unsigned long factoriall(unsigned long i){
    unsigned long result = 1;
    while(i > 1){
      result *= i--;
    }
    return result;
  }
  unsigned long long factorialll(unsigned long long i){
    unsigned long long result = 1;
    while(i > 1){
      result *= i--;
    }
    return result;
  }*/

  int ceil(double value){
    return ++((int)value);
  }
  int floor(double value){
    return (int)value;
  }
  int round(double value){
    int temp_int = (int) value;
    double temp_double = value - temp_int;
    return (temp_double > 0.5) ? ++temp_int : temp_int;
  }

  double square(double base){
    return base * base;
  }
  double cube(double base){
    return base * base * base;
  }

  double sqrt(double value);
  long double sqrtl(long double value);

  long double exp(double power);
  long double pow(double base, double power);

  double hypo(double leg1, double leg2){
    return sqrt(pow(leg1, 2) + pow(leg2, 2));
  }
  double leg(double hypot, double leg){
    return sqrt(pow(hypot, 2) - pow(leg, 2));
  }

  double log(double expo);
  double lg(double expo);
  double ln(double expo);
  double log_base(unsigned int base, double expo);

  long gcd(long a, long b){
    if(a == 0) return b;
    else if (b == 0) return a;
    else{
      long remander = a % b;
      return gcd(b, remander);
    }
  }

  long lcm(long a, long b){
    long temp_a = a, temp_b = b;
    while(temp_a != temp_b){
      (temp_a > temp_b) ? temp_b += b : temp_a += a;
    }
  }

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