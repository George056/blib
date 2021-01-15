#include "Functions.h"

namespace blib{
  float absf(float value){
    return (value >= 0) ? value : -value;
  }
  double abs(double value){
    return (value >= 0) ? value : -value;
  }
  long double absl(long double value){
    return (value >= 0) ? value : -value;
  }

  unsigned int factorial(unsigned int i){
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
  }
}