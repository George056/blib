#ifndef INTEGRAL
#define INTEGRAL
#include "..\Containers\Array.hpp"

namespace blib{
  namespace integral{
    double left_rectangular_rule(/*function*/, double left_bound, double right_bound, int intervals);
    double left_rectangular_rule(blib::array<double> values, double left_bound, double right_bound, double width);

    double right_rectangular_rule(/*function*/, double left_bound, double right_bound, int intervals);
    double right_rectangular_rule(blib::array<double> values, double left_bound, double right_bound, double width);

    double midpoint_rule(/*function*/, double left_bound, double right_bound, int intervals);
    double midpoint_rule(blib::array<double> values, double left_bound, double right_bound, double width);

    using LRAM left_rectangular_rule;
    using RRAM right_rectangular_rule;
    using MRAM midpoint_rule;

    double trapizoid_rule(/*function*/, double left_bound, double right_bound, int intervals);
    double trapizoid_rule(blib::array<double> values, double left_bound, double right_bound, double width);

    double simpsons_1_3(/*function*/, double left_bound, double right_bound, int intervals);
    double simpsons_1_3(blib::array<double> values, double left_bound, double right_bound);

    double simpsons_3_8(/*function*/, double left_bound, double right_bound, int intervals);
    double simpsons_3_8(blib::array<double> values, double left_bound, double right_bound);

    double simpsons_rule(/*function*/, double left_bound, double right_bound, int intervals);
    double simpsons_rule(blib::array<double> values, double left_bound, double right_bound);

    double gaussian_quadratures();

    double volume_washer();

    double volume_shell();
  }
}

#endif