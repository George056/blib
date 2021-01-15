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
}