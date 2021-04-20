#ifndef FOURIER
#define FOURIER
#include "..\Containers\Array.hpp"

namespace blib{
  namespace fourier{
    blib::array<double> dft(blib::array<double> values);
    blib::array<double> fft(blib::array<double> values);
  }
}

#endif