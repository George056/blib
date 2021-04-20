#include "Fourier.h"
#include "Functions.h"
#include "Complex.hpp"
#include "Constants.h"

namespace blib{
  namespace fourier{
    blib::array<double> dft(blib::array<double> values){
      blib::array<double, values.size()> solution;
      for(int r = 0; r < values.size(); ++r){
        for(int n = 0; n < values.size(); ++n){
          solution[r] = values[n] * exp(complex(0,-1) * r * 2 * PI / values.size() * n);
        }
      }
      return solution;
    }

    blib::array<double> fft(blib::array<double> values){

    }
  }
}