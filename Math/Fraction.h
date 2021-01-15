#ifndef FRACTION
#define FRACTION

namespace blib{

  class fraction{
  private:
    long long __numerator;
    long long __denominator;

  public:
    fraction() = default;
    fraction(const fraction&) = default;
    fraction(fraction&&) = default;
    fraction& operator =(const fraction&) = default;
    fraction& operator =(fraction&&) = default;

    fraction(long long numerator, long long denominator) : 
            __numerator{ numerator }, __denominator { denominator } {}

    //constructor from double to fraction

    inline long long numerator(){ return __numerator; }
    inline long long denominator(){ return __denominator; }

    fraction operator +(fraction);
    fraction operator +(long long);

    fraction operator -(fraction);
    fraction operator -(long long);

    fraction operator -();

    fraction operator *(fraction);
    fraction operator *(long long);

    fraction operator /(fraction);
    fraction operator /(long long);

    fraction& operator +=(fraction);
    fraction& operator +=(long long);

    fraction& operator -=(fraction);
    fraction& operator -=(long long);

    fraction& operator *=(fraction);
    fraction& operator *=(long long);

    fraction& operator /=(fraction);
    fraction& operator /=(long long);

    operator double() const;

    fraction inverse();

  }

}

#endif