#include "Algorithm.h"

namespace blib {
  unsigned int mod2(unsigned int num) {
    return ((num & 0b00000001) == 0) ? 0 : 1;
  }

  bool divisable_by_7(unsigned int num) {
    if (num < 10) {
      if (num == 7) return true;
      else return false;
    }
    unsigned last_digit = num % 10;
    unsigned rest = num / 10;

    last_digit *= 2;

    int result = abs<int>(rest - last_digit);

    if (result < 10 && result != 7) return false;
    else if (result == 7) return true;
    else return divisable_by_7(result);
  }
}