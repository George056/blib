#ifndef DERIVATIVE
#define DERIVATIVE
#include "..\Containers\Array.hpp"

namespace blib{
  namespace derivative{

    double point_derivative(/*function*/, double point);
    double point_derivative(blib::array<double> values, double point);
  }
}

#endif