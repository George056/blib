#ifndef RANDOM
#define RANDOM

#include <ctime>

namespace blib {
  template<typename T, T seed = std::time(NULL)>
  class random {
  private:
    T __seed = seed;

    static T BiologicalRand(T start, T end, size_t n, T value) {
      if (n >= seed) {
        if (value >= start && value <= end) return value;
      }
      // Fall into calculation if wrong bounding

      return BiologicalRand(start, end, ++n, seed(value + 1));
    }

  public:

    static T BiologicalRand(T start, T end) {
      return BiologicalRand(start, end, 0, 0);
    }

  };
}

#endif