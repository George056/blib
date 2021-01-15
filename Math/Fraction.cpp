#include "Fraction.h"

namespace blib{
  fraction fraction::operator +(fraction right){
    return fraction(__numerator + right.__numerator, __denominator + right.__denominator);
  }
  fraction fraction::operator +(long long right){
    return fraction(__numerator + right, __denominator);
  }

  fraction fraction::operator -(fraction right){
    return fraction(__numerator - right.__numerator, __denominator - right.__denominator);
  }
  fraction fraction::operator -(long long right){
    return fraction(__numerator - right, __denominator);
  }

  fraction fraction::operator -(){
    return fraction(-__numerator, __denominator);
  }

  fraction fraction::operator *(fraction right){
    return fraction(__numerator * right.__numerator, __denominator * right.__denominator);
  }
  fraction fraction::operator *(long long right){
    return fraction(__numerator * right, __denominator);
  }

  fraction fraction::operator /(fraction right);
  fraction fraction::operator /(long long right);

  fraction& fraction::operator +=(fraction right);
  fraction& fraction::operator +=(long long right);

  fraction& fraction::operator -=(fraction right);
  fraction& fraction::operator -=(long long right);

  fraction& fraction::operator *=(fraction right);
  fraction& fraction::operator *=(long long right);

  fraction& fraction::operator /=(fraction right);
  fraction& fraction::operator /=(long long right);

  fraction::operator double() const;
}