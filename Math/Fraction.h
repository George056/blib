#ifndef FRACTION
#define FRACTION

#include "Functions.h"

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

    fraction operator +(fraction) const;
    fraction operator +(long long) const;

    fraction operator -(fraction) const;
    fraction operator -(long long) const;

    inline fraction operator -() const;

    inline fraction operator *(fraction) const;
    inline fraction operator *(long long) const;

    inline fraction operator /(fraction) const;
    inline fraction operator /(long long) const;

    fraction& operator +=(fraction);
    fraction& operator +=(long long);

    fraction& operator -=(fraction);
    fraction& operator -=(long long);

    inline fraction& operator *=(fraction);
    inline fraction& operator *=(long long);

    inline fraction& operator /=(fraction);
    inline fraction& operator /=(long long);

    operator float() const;
    operator double() const;
    operator long double() const;

    fraction inverse();

  }

  inline fraction operator +(long long, fraction);
  inline fraction operator -(long long, fraction);
  inline fraction operator *(long long, fraction);
  inline fraction operator /(long long, fraction);

}

#endif