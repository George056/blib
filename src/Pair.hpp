#ifndef PAIR
#define PAIR

namespace blib{

  template<typename first__, typename second__>
  class pair{
  public:
    first__ first;
    second__ second;

    pair() = default;
    pair(first__ f, second__ s) : first{ f }, second{ s } {}
    pair(const pair&) = default;
    pair(pair&&) = default;

    pair& operator =(const pair&) = default;
    pair& operator =(pair&&) = default;
  };

}

#endif