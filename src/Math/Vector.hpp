#ifndef VECTOR
#define VECTOR

#include "../Containers/Array.hpp"
#include "Functions.h"

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
  /// <typeparam name="T">The type held by the vector (must have the numeric operator defined for it).</typeparam>
  template<typename T, size_t SIZE>
  class vector{
  private:
    array<T,SIZE> __vector;
    orientation __orient;

    size_t size(){ return __vector.size(); }

  public:

    using value_type = T;
    using size_type = size_t;
    using reference = value_type&;
    using constant_reference = const value_type&;
    using pointer_type = T*;

    /// <summary>
    /// Default constructs to the 0 vector.
    /// </summary>
    vector() : __vector(), __orient{ horizontal }{
      for(size_t i = 0; i < SIZE; ++i){
        __vector[i] = 0;
      }
    }

    /// <summary>
    /// Copy over a given range. Done with pointers.
    /// </summary>
    /// <param name="_first">The beginning of the range</param>
    /// <param name="_second">The end of the range</param>
    vector(pointer_type _first, pointer_type _second) : __vector() , __orient{ horizontal } {
      for(auto i = _first, int j = 0; i < _second; ++i, ++j){
        __vector[j] = *i;
      }
    }

    vector(const vector&) = default;
    vector(vector&&) = default;

    vector& operator =(const vector&) = default;
    vector& operator =(vector&) = default;

    /// <summary>
    /// Access the given element of the vector (does not check for out of bounds).
    /// </summary>
    /// <param name="index">The location in the vector to access</param>
    /// <returns>A reference to the accessed element</returns>
    reference operator [](size_t index) {
      return __vector[index];
    }

    /// <summary>
    /// Access the given element of the vector (does not check for out of bounds).
    /// </summary>
    /// <param name="index">The location in the vector to access</param>
    /// <returns>A const reference to the accessed element</returns>
    constant_reference operator [](size_t index) const {
      return __vector[index];
    }

    /// <summary>
    /// Access the given element of the vector.
    /// </summary>
    /// <param name="index">The location in the vector to access</param>
    /// <returns>A reference to the accessed element</returns>
    reference at(size_t index) {
      return __vector.at(index);
    }

    /// <summary>
    /// Access the given element of the vector (does not check for out of bounds).
    /// </summary>
    /// <param name="index">The location in the vector to access</param>
    /// <returns>A const reference to the accessed element</returns>
    constant_reference at(size_t index) const {
      return __vector.at(index);
    }

    /// <summary>
    /// Add to vectors together.
    /// </summary>
    /// <param name="right">The vector to be added on the right side.</param>
    /// <returns>The resulting vector after the addition.</returns>
    /// <exception cref="std::logic_error">Thrown when the index is out of the range of the vector.</exception>
    /// <exception cref="std::logic_error">Thrown when the vectors are of different orientations.</exception>
    vector operator +(const vector& right) const {
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

    vector operator -(const vector& right) const {
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

    vector& operator -(){
      for (size_type i = 0; i < __vector.size(); ++i) {
        __vector[i] *= -1;
      }
      return *this;
    }

    vector operator *(value_type value){
      for (size_type i = 0; i < __vector.size(); ++i) {
        __vector[i] *= value;
      }
      return *this;
    }

    double& dot(const vector& r) const {

    }

    void element_by_element(const vector& r, value_type (*function)(value_type, value_type)) {
      if (size() != r.size()) throw std::logic_error("Mismatched vector sizes");
      for (size_type i = 0; size_type j = 0; i < size(); ++i, ++j) {
        __vector[i] = function(__vector[i], r[i]);
      }
    }

    double norm() const {
      double result = 0;
      for (size_type i = 0; i < __vector.size(); ++i) {
        result += square(at(i));
      }
      return sqrt(result);
    }

    void zero() {
      for (size_type i = 0; i < __vector.size(); ++i) {
        __vector[i] = 0;
      }
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

    /// <summary>
    /// Construct the vector based on given values
    /// </summary>
    /// <param name="i">The i hat component of the vector</param>
    /// <param name="j">The j hat component of the vector</param>
    vector2D(double i, double j) : __i{ i }, __j{ j } {}

    /// <summary>
    /// Construct with a vector
    /// </summary>
    /// <param name="v">A vector of length 2</param>
    vector2D(const vector<double, 2>& v) : __i{ v[0] }, __j{ v[1] } {}

    ~vector2D() = default;

    vector2D& operator =(const vector2D&) = default;
    vector2D& operator =(vector2D&&) = default;

    /// <summary>
    /// Obtain the x component of the vector
    /// </summary>
    /// <returns>The x component of the vector</returns>
    inline double x() const { return __i; }

    /// <summary>
    /// Obtain the y component of the vector
    /// </summary>
    /// <returns>The y component of the vector</returns>
    inline double y() const { return __j; }

    /// <summary>
    /// Obtain the i hat for the vector
    /// </summary>
    /// <returns>The i hat component of the vector</returns>
    inline double i_hat() const { return x(); }

    /// <summary>
    /// Obtain the i hat for the vector
    /// </summary>
    /// <returns>The i hat component of the vector</returns>
    inline double j_hat() const { return y(); }

    /// <summary>
    /// Add two 2D vectors
    /// </summary>
    /// <param name="r">The vector on the right side of the + sign</param>
    /// <returns>A reference to the resulting vector</returns>
    vector2D& operator +(const vector2D& r) const {
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

    vector2D& operator -(const vector2D& r) const {
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

    /// <summary>
    /// Negates the elements of the vector
    /// </summary>
    /// <returns>A reference to this vector</returns>
    vector2D& operator-(){
      __i *= -1;
      __j *= -1;
      return *this;
    }

    /// <summary>
    /// Applies the + operator
    /// </summary>
    /// <remark>
    /// This does nothing
    /// </remark>
    /// <returns>A reference to this vector</returns>
    vector2D& operator+(){
      return *this;
    }

    /// <summary>
    /// Applies the + operator
    /// </summary>
    /// <remark>
    /// This does nothing
    /// </remark>
    /// <returns>A const reference to this vector</returns>
    const vector2D& operator+() const {
      return *this;
    }

    vector2D& operator *(double scaler) const {
      vector2D result;
      result.__i = __i * scaler;
      result.__j = __j * scaler;
      return result;
    }

    vector2D& operator /(double scaler) const {
      vector2D result;
      result.__i = __i / scaler;
      result.__j = __j / scaler;
      return result;
    }

    vector2D& operator *=(double scaler) {
      __i *= scaler;
      __j *= scaler;
      return *this;
    }

    /// <summary>
    /// Scaler devision of the vector
    /// </summary>
    /// <param name="scaler">The amount to scale the vector by</param>
    /// <returns>A reference to this vector</returns>
    vector2D& operator /=(double scaler) {
      __i /= scaler;
      __j /= scaler;
      return *this;
    }

    /// <summary>
    /// This calculates the (euclidean) norm of the vector
    /// </summary>
    /// <returns>The norm of the vector</returns>
    double norm() const {
      return sqrt(square(__i) + square(__j));
    }

    /// <summary>
    /// Calculate the projection of v on the vector that is called
    /// </summary>
    /// <remark>
    /// In the formula this vector is the u vector
    /// </remark>
    /// <param name="v">The vector casting the projection</param>
    void projection(const vector2D& v) {
      *this = (dot(*this, v) / norm()) * (*this) / norm();
    }

    /// <summary>
    /// Perform the given function on all elements and update their value
    /// </summary>
    /// <param name="value">The argument in the function for all of the elements</param>
    /// <param name="function">The function to be passed, needs to take two doubles and return a double</param>
    /// <returns>A reference to this vector</returns>
    vector2D& element_by_element(double value, double (*function)(double, double)) {
      __i = function(__i, value);
      __j = function(__j, value);
      return *this;
    }

    /// <summary>
    /// This sets the vector to zero
    /// </summary>
    inline void zero() {
      __i = 0;
      __j = 0;
    }
  };

  /// <summary>
  /// A 3D mathematical vector.
  /// </summary>
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
    vector3D(const vector<double, 3> v) : __i{ v[0] }, __j{ v[1] }, __k{ v[2] } {}

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

    inline double x() const { return __i; }
    inline double y() const { return __j; }
    inline double z() const { return __k; }
    inline double i_hat() const { return x(); }
    inline double j_hat() const { return y(); }
    inline double k_hat() const { return z(); }

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

    vector3D& operator *(double scaler) const {
      vector3D result;
      result.__i = __i * scaler;
      result.__j = __j * scaler;
      result.__k = __k * scaler;
      return result;
    }

    vector3D& operator /(double scaler) const {
      vector3D result;
      result.__i = __i / scaler;
      result.__j = __j / scaler;
      result.__k = __k / scaler;
      return result;
    }

    vector3D& operator *=(double scaler) {
      __i *= scaler;
      __j *= scaler;
      __k *= scaler;
      return *this;
    }

    vector3D& operator /=(double scaler) {
      __i /= scaler;
      __j /= scaler;
      __k /= scaler;
      return *this;
    }

    double norm() const {
      return sqrt(square(__i) + square(__j) + square(__k));
    }

    void projection(const vector3D& v) {
      *this = (dot(*this, v) / norm()) * (*this) / norm();
    }

    inline void zero() {
      __i = 0;
      __j = 0;
      __k = 0;
    }
  };

  /// <summary>
  /// This represents the mathematical concept of the quaternion. This is being based on
  /// <see cref="https://www.sciencedirect.com/topics/computer-science/quaternion-multiplication"/> and
  /// <see cref="https://eater.net/quaternions"/>.
  /// </summary>
  class quaternion{
  private:
    double __scaler, __i, __j, __k;

    inline double x() const { return __i; }
    inline double y() const { return __j; }
    inline double z() const { return __k; }

  public:

    using value_type = double;
		using size_type = size_t;

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

    explicit operator vector3D() {
      return vector3D(__i, __j, __k);
    }

    inline void set(double scaller, double i, double j, double k){
      __scaler = scaller;
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

    inline double scaler_value() const { return __scaler; }
    inline double i_hat() const { return x(); }
    inline double j_hat() const { return y(); }
    inline double k_hat() const { return z(); }
    double& operator [](size_type index) {
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
    const double& operator [](size_type index) const {
      switch (index) {
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
      return this->operator[](index);
    }
    const double& at(size_type index) const {
      return this->operator[](index);
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

    inline void zero() {
      __scaler = 0;
      __i = 0;
      __j = 0;
      __k = 0;
    }
  };

  inline double dot(const vector2D& l_value, const vector2D& r_value) {
    return l_value.x() * r_value.x() + l_value.y() * r_value.y();
  }

  inline vector2D operator *(double l_value, const vector2D& r_value) {
    return r_value * l_value;
  }

  inline double dot(const vector3D& l_value, const vector3D& r_value) {
    return l_value.x() * r_value.x() + l_value.y() * r_value.y();
  }

  inline vector3D operator *(double l_value, const vector3D& r_value) {
    return r_value * l_value;
  }

  template<typename T, size_t SIZE>
  double dot(const vector<T, SIZE>& l_value, const vector<T, SIZE>& r_value) {
    double result = 0;
    for (vector<T, SIZE>::size_type i = 0; i < SIZE; ++i) {
      result += l_value[i] * r_value[i];
    }
    return result;
  }
}

#endif