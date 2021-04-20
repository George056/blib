#include "Fraction.h"

namespace blib{
  fraction fraction::operator +(fraction right) const {
    long long num_l = __numerator, num_2 = right.__numerator;
    long long denum = lcm(__denominator, right.__denominator);
    num1 *= denum/__denominator;
    num2 *= denum/right.__denominator;
    return fraction(num1 + num2, denum);
  }
  fraction fraction::operator +(long long right) const {
    return fraction(__numerator + (right * __denominator), __denominator);
  }

  fraction fraction::operator -(fraction right) const {
    long long num_l = __numerator, num_2 = right.__numerator;
    long long denum = lcm(__denominator, right.__denominator);
    num1 *= denum/__denominator;
    num2 *= denum/right.__denominator;
    return fraction(num1 - num2, denum);
  }
  fraction fraction::operator -(long long right) const {
    return fraction(__numerator - (right * __denominator), __denominator);
  }

  fraction fraction::operator -() const {
    return fraction(-__numerator, __denominator);
  }

  fraction fraction::operator *(fraction right) const {
    return fraction(__numerator * right.__numerator, __denominator * right.__denominator);
  }
  fraction fraction::operator *(long long right) const {
    return fraction(__numerator * right, __denominator);
  }

  fraction fraction::operator /(fraction right) const {
    return fraction(__numerator * right.__denominator, __denominator * right.__numerator);
  }
  fraction fraction::operator /(long long right) const {
    return fraction(__numerator, __denominator * right);
  }

  fraction& fraction::operator +=(fraction right){
    fraction temp = *this + right;
    __numerator = temp.__numerator;
    __denominator = temp.__denominator;
    return *this;
  }
  fraction& fraction::operator +=(long long right){
    __numerator += (right * __denominator);
    return *this;
  }

  fraction& fraction::operator -=(fraction right){
    fraction temp = *this - right;
    __numerator = temp.__numerator;
    __denominator = temp.__denominator;
    return *this;
  }
  fraction& fraction::operator -=(long long right){
    __numerator -= (right * __denominator);
    return *this;
  }

  fraction& fraction::operator *=(fraction right){
    __numerator *= right.__numerator;
    __denominator *= right.__denominator;
    return *this;
  }
  fraction& fraction::operator *=(long long right){
    __numerator *= right;
    return *this;
  }

  fraction& fraction::operator /=(fraction right){
    __numerator *= right.__denominator;
    __denominator *= right.__numerator;
    return *this;
  }
  fraction& fraction::operator /=(long long right){
    __denominator *= right;
    return *this;
  }

  fraction::operator float() const{
    return __numerator / __denominator;
  }
  fraction::operator double() const{
    return __numerator / __denominator;
  }
  fraction::operator long double() const{
    return __numerator / __denominator;
  }
  
  fraction fraction::inverse(){
    return fraction(__denominator, __numerator);
  }

  fraction operator +(long long left, fraction right){
    return right + left;
  }
  fraction operator -(long long left, fraction right){
    return (-right) + left;
  }
  fraction operator *(long long left, fraction right){
    return right * left;
  }
  fraction operator /(long long left, fraction right){
    return right.inverse() * left;
  }
}