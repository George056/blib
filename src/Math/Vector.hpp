#ifndef MATRIX
#define MATRIX

#include "../Containers/Array.hpp"

#include<stdexcept>

namespace blib{

  enum class orientation : char{
    vertical = 'v',
    horizontal = 'h'
  };

  /// <summary>
  /// This class represents a mathematical vector by use of an array. This
  /// is used to reduce the complexity and size of a vector (and confusion of 
  /// using blib::dynamic_array which is approximately the same as std::vector).
  /// </summary>
  /// <typeparam name="T"></typeparam>
  template<typename T, size_t SIZE>
  class vector{
  private:
    array<T,SIZE> __vector;
    orientation __orient;

    size_t size(){ return __vector.size(); }

  public:
    vector() : __vector(), __orient{ horizontal }{
      for(size_t i = 0; i < SIZE; ++i){
        __vector[i] = 0;
      }
    }

    vector(T* _first, T* _second) : __vector() , __orient{ horizontal }{
      for(auto i = _first, int j = 0; i < _second; ++i, ++j){
        __vector[j] = *i;
      }
    }

    vector(const vector&) = default;
    vector(vector&&) = default;

    vector& operator =(const vector&) = default;
    vector& operator =(vector&) = default;

    vector operator +(const vector& right){
      if(size() != right.size()) throw std::logic_error("Mismatched vector sizes");

      if(__orient == right.__orient){
        array<T, SIZE> temp;
        for(size_t i = 0; i < size(); ++i){
          temp[i] = __array[i] + right.__array[i];
        }
        return temp;
      }
      else throw std::logic_error("Mismatched vector orientation");
    }

    vector operator -(const vector& right){
      if(size() != right.size()) throw std::logic_error("Mismatched vector sizes");

      if(__orient == right.__orient){
        array<T, SIZE> temp;
        for(size_t i = 0; i < size(); ++i){
          temp[i] = __array[i] - right.__array[i];
        }
        return temp;
      }
      else throw std::logic_error("Mismatched vector orientation");
    }

    vector operator -(){
      array<T, SIZE> temp;
      for(size_t i = 0; i < size(); ++i){
        temp[i] = -__array[i];
      }
      return temp;
    }

    vector operator *(auto value){
      array<T, SIZE> temp;
      for(size_t i= 0; i < size(); ++i){
        temp[i] = value * __array[i];
      }
      return temp;
    }

    vector operator *(const vector& right){

    }
  };

  /// <summery>
  /// This class is a lighter weight implementation of vector specifically for 2D vectors.
  /// This is done using doubles.
  /// </summery>
  class vector2D{
  private:
    double __i, __j;

  public:
    vector2D() = default;
    vector2D(const vector2D&) = default;
    vector2D(vector2D&&) = default;

    vector2D(double i, double j) : __i{ i }, __j{ j } {}

    ~vector2D() = default;

    vector2D& operator =(const vector2D&) = default;
    vector2D& operator =(vector2D&&) = default;

    inline double x() { return __i; }
    inline double y() { return __j; }
    inline double i_hat() { return x(); }
    inline double j_hat() { return y(); }

    double dot(const vector2D& r){
      double result;
      result = __i * r.__i + __j * r.__j;
    }

    vector2D& operator +(const vector2D& r){
      vector2D result;
      result.__i = __i + r.__i;
      result.__j = __j + r.__j;
      return result;
    }

    vector2D& operator +=(const vector2D& r){
      __i += r.__i;
      __j += r.__j;
      return *this;
    }

    vector2D& operator -(const vector2D& r){
      vector2D result;
      result.__i = __i - r.__i;
      result.__j = __j - r.__j;
      return result;
    }

    vector2D& operator -=(const vector2D& r){
      __i -= r.__i;
      __j -= r.__j;
      return *this;
    }

    vector2D& operator-(){
      __i *= -1;
      __j *= -1;
      return *this;
    }

    vector2D& operator+(){
      return *this;
    }
  };

  class vector3D{
  private:
    double __i, __j, __k;

  public:
    vector3D() = default;
    vector3D(const vector3D&) = default;
    vector3D(vector3D&&) = default;

    vector3D(double i, double j, double k) : __i{ i }, __j{ j }, __k{ k } {}
    vector3D(vector2D v2d) : __i{ v2d.x() }, __j{ v2d.y() }, __k{ 0 } {}
    vector3D(vector2D v2d, double k) : __i{ v2d.x() }, __j{ v2d.y() }, __k{ k } {}

    ~vector3D() = default;

    vector3D& operator =(const vector3D&) = default;
    vector3D& operator =(vector3D&&) = default;

    vector3D& operator =(const vector2D& v2d) {
      __i = v2d.x();
      __j = v2d.y();
      __k = 0;
    }

    inline void set(double i, double j, double k){
      __i = i;
      __j = j;
      __k = k;
    }

    inline double x() { return __i; }
    inline double y() { return __j; }
    inline double z() { return __k; }
    inline double i_hat() { return x(); }
    inline double j_hat() { return y(); }
    inline double k_hat() { return z(); }

    double dot(const vector3D& r){
      double result;
      result = __i * r.__i + __j * r.__j + __k * r.__k;
    }

    vector3D& cross(const vector3D& r){
      vector3D result;

      result.__i = __j * r.__k - __k * r.__j;
      result.__j = __k * r.__i - __i * r.__k;
      result.__k = __i * r.__j - __j * r.__i;

      return result;
    }

    vector3D& cross_equal(const vector3D& r){
      double i, j, k;

      i = __j * r.__k - __k * r.__j;
      j = __k * r.__i - __i * r.__k;
      k = __i * r.__j - __j * r.__i;

      __i = i;
      __j = j;
      __k = k;

      return *this;
    }
  };

  class quaternion{
  private:
    double __scaler, __i, __j, __k;

    inline double x() { return __i; }
    inline double y() { return __j; }
    inline double z() { return __k; }

    class __Iterator__{
    private:
      double* itr;

      __Iterator__(double* value) : itr{ value } {}

    public:
      __Iterator__() = default;
      __Iterator__(const __Iterator__&) = default;
      __Iterator__(__Iterator__&&) = default;

      void next(){
        if(itr == &__scaler) itr = &__i;
        else if(itr == &__i) itr = &__j;
        else if(itr == &__j) itr = &__k;
        else if(itr == &__k) itr += 1;
        else throw std::out_of_range("A quaternion only has 4 values.");
      }

      void previous(){
        if(itr == &__k) itr = &__j;
        else if(itr == &__j) itr = *__i;
        else if(itr == &__i) itr = *__scaler;
        else if(itr == &__scaler) itr -= 1;
        else throw std::out_of_range("A quaternion only has 4 values.");
      }

      __Iterator__& operator ++(int){
        next();
        return *this;
      }

      __Iterator__& operator --(int){
        previous();
        return *this;
      }

      double& operator *(){
        return *itr;
      }

    };

  public:

    using value_type = double;
		using size_type = size_t;
		using iterator = __Iterator__;
		using const_iterator = const __Iterator__;

    quaternion() = default;
    quaternion(const quaternion&) = default;
    quaternion(quaternion&&) = default;

    quaternion(double scaler, double i, double j, double k) : __scaler{ scaler }, __i{ i }, __j{ j }, __k{ k } {}
    quaternion(const vector3D& v3d) : __scaler{ 0 }, __i{ v3d.x() }, __j{ v3d.y() }, __k{ v3d.z() } {}

    ~quaternion() = default;

    quaternion& operator =(const quaternion&) = default;
    quaternion& operator =(quaternion&&) = default;

    quaternion& operator =(const vector3D& v3d){
      __scaler = 0;
      __i = v3d.x();
      __j = v3d.y();
      __k = v3d.z();
    }

    iterator begin(){
      return iterator(&__scaler);
    }

    iterator end(){
      return iterator((&__k) + 1);
    }

    inline void set(double scaller, double i, double j, double k){
      __scaller = scaller;
      __i = i;
      __j = j;
      __k = k;
    }
    
    inline void set(double i, double j, double k){
      __scaler = 0;
      __i = i;
      __j = j;
      __k = k;
    }

    inline void set(const vector3D& v3d){
      __scaler = 0;
      __i = v3d.x();
      __j = v3d.y();
      __k = v3d.z();
    }

    inline double scaler_value() { return __scaler; }
    inline double i_hat() { return x(); }
    inline double j_hat() { return y(); }
    inline double k_hat() { return z(); }
    double& operator [](size_type index){
      switch(index){
        case 0:
          return __scaler;
          break;
        case 1:
          return __i;
          break;
        case 2:
          return __j;
          break;
        case 3:
          return __k;
          break;
        default:
          throw std::out_of_range("A quaternion only has 4 values.");
      }
    }
    double& at(size_type index){
      return this->operator[index];
    }

    quaternion& operator +(const quaternion& q){
      quaternion result;
      result.__scaler = __scaler + q.__scaler;
      result.__i = __i + q.__i;
      result.__j = __j + q.__j;
      result.__k = __k + q.__k;
      return result;
    }

    quaternion& operator *(const quaternion& q){
      quaternion result;
      result.__scaler = __scaler * q.__scaler;
      result.__i = __j * q.__k;
      result.__j = __k * q.__i;
      result.__k = __i * q.__j;
      return result;
    }
  };
}

#endif