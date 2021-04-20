#include "Integral.h"

namespace blib{
  namespace integral{

    double left_rectangular_rule(blib::array<double> values, double left_bound, double right_bound, double width){
      blib::array<double, values.size() / 2 + (values.size() % 2) ? 1 : 0> areas;
      for(int i = 0, j = 0; i < values.size(); i += 2, ++j){
        areas[j] = values[j] * width;
      }
      double sum = 0;
      for(int i = 0; i < areas.size(); ++i){
        sum += areas[i];
      }
      return sum;
    }

    double trapizoid_rule(blib::array<double> values, double left_bound, double right_bound, double width){

    }
  }
}