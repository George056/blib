#ifndef ARRAY
#define ARRAY

#include "Container.hpp"
#include <stdexcept>

namespace blib {

		/// <summary>
		/// An object based (C++) array data structure.
		/// </summary>
		/// <typeparam name="arrayType">The type of data held by the array.</typeparam>
		/// <typeparam name="SIZE">The size of the array.</typeparam>
		template <typename arrayType, size_t SIZE>
		class array : public container<arrayType, arrayType*, const arrayType*> {
		public:

				using value_type = arrayType;
				using size_type = size_t;
				using reference = value_type&;
				using constant_reference = const value_type&;
				using pointer = value_type*;
				using const_pointer = const value_type*;
				using iterator = pointer;
				using const_iterator = const_pointer;
				using reverse_iterator = pointer;
				using const_reverse_iterator = const_pointer;

				/// <summary>
				/// The default constructor for an array.
				/// </summary>
				array() : container<value_type, iterator, const_iterator>::container(SIZE), __size_used{ 0 } {
						__array = new value_type[SIZE];
				}

				/// <summary>
				/// A copy constructor that will copy perform a minimum copy.
				/// </summary>
				/// <param name="ary">The array to be copied.</param>
				/// <exception cref="std::logic_error">Thrown when the array to be copied's size is not equal to SIZE.</exception>
				array(const array& ary) : __size_used{ ary.__size_used },
																container<value_type, iterator, const_iterator>::__size{ ary.get_size() }{
						if (ary.size() != SIZE) throw std::logic_error("The two arrays are of different size.");
						__array = new value_type[ary.size()];
						copy_array(ary, *this);
				}

				/// <summary>
				/// The copy operator.
				/// </summary>
				/// <param name="ary">The array to be copied</param>
				/// <returns>The array that was assigned to.</returns>
				/// <exception cref="std::out_of_range">Thrown when the given C-array is larger then the memory alloted to the array.</exception>
				virtual array& operator =(const array& ary) {
						if (container<value_type, iterator, const_iterator>::__size < ary.size())
								throw std::out_of_range("Size of the given array is too large.");
						__size_used = ary.__size_used;
						copy_array(ary, *this);
						return *this;
				}

				array(array&&) = default;
				virtual array& operator =(array&&) = default;

				/// <summary>
				/// Copy a C-array with the starting pointer and how far to go.
				/// </summary>
				/// <param name="ptr">The array's, to be copied, starting point.</param>
				/// <param name="size">The size of the array to be copied.</param>
				/// <exception cref="std::out_of_range">Thrown when the given C-array is larger then the memory alloted to the array.</exception>
				array(pointer ptr, size_type size) : container<value_type, iterator, const_iterator>::container(SIZE), __size_used{ size }{
						__array = new value_type[SIZE];
						if (size < SIZE)
								for (size_type i = 0; i < size; ++i) {
										__array[i] = ptr[i];
								}
						else
								std::out_of_range("Given C-array is bigger than memory allotted.");
				}

				/// <summary>
				/// Copy a C-array with the starting end ending points.
				/// </summary>
				/// <param name="start">The starting point of coping the C-array.</param>
				/// <param name="end">The ending point of coping the C-array.</param>
				array(pointer start, pointer end) : container<value_type, iterator, const_iterator>::container(SIZE) {
						size_type j = end - start;
						if(j > SIZE) std::out_of_range("Given series is bigger than memory allotted.");

						__array = new value_type[SIZE];

						for (size_type i = 0; i < j; ++i) {
								__array[i] = start[i];
						}
				}

				/// <summary>
				/// A constant C-array copy with starting and ending points.
				/// </summary>
				/// <param name="start">The starting point of coping the C-array.</param>
				/// <param name="end">The ending point of coping the C-array.</param>
				array(const_pointer start, const_pointer end) : container<value_type, iterator, const_iterator>::container(SIZE) {
						size_type j = end - start;
						if (j > SIZE) std::out_of_range("Given series is bigger than memory allotted.");

						__array = new value_type[j];

						for (size_type i = 0; i < j; ++i) {
								__array[i] = start[i];
						}
				}

				/// <summary>
				/// Release the memory of the array before destructing it.
				/// </summary>
				virtual ~array() { if (__array != nullptr) delete[] __array; }

				/// <summary>
				/// Find the maximum size of the array.
				/// </summary>
				/// <returns>The maximum size of the array.</returns>
				inline size_t max_size() const noexcept { return container<value_type, iterator, const_iterator>::__size; }

				/// <summary>
				/// The size of the array that is currently being used.
				/// </summary>
				/// <returns>The size of the array in use.</returns>
				inline virtual size_type size() const noexcept override { return __size_used; }

				/// <summary>
				/// If the array is holding any data.
				/// </summary>
				/// <returns>True if it has any data, false if it has no data.</returns>
				inline virtual bool empty() const noexcept override { return __size_used == 0; }

				/// <summary>
				/// Change where push_back will insert the next item.
				/// </summary>
				/// <remarks>
				/// The slider is left in the starting state if an error is thrown.
				/// </remarks>
				/// <param name="i">The value to shift the slider by (can be positive or negative).</param>
				/// <exception cref="std::logic_error">Thrown when the slider would have been shifted beyond the ends of the array.</exception>
				inline void shift_slider(int i) { 
						if (__size_used + i > SIZE)
								throw std::logic_error("The slider is past the end of the array.");
						else if (__size_used + i < 0)
								throw std::logic_error("The slider is before the array.");
						else
								__size_used += i;
				}

				/// <summary>
				/// An operator to access the value of an array to read and write.
				/// </summary>
				/// <remarks>
				/// This operator does not check to make sure you stay in the bounds of the array.
				/// </remarks>
				/// <param name="index">Where to look.</param>
				/// <returns>The value at that location in the array.</returns>
				inline virtual value_type& operator [](size_type index) override { return __array[index]; }

				/// <summary>
				/// Access the value of the array to read and write.
				/// </summary>
				/// <param name="index">The index where to look.</param>
				/// <returns>The value at the location in the array.</returns>
				/// <exception cref="std::out_of_range">Thrown when the index is out of the range of the array.</exception>
				virtual value_type& at(size_type index) override {
						if (index > __size_used)
								throw std::out_of_range("exceeds the size of the array");
						return __array[index];
				}

				/// <summary>
				/// Add an element to the end of the array.
				/// </summary>
				/// <remarks>
				/// This functions the same as the []'s.
				/// </remarks>
				/// <param name="item">The element to be added.</param>
				/// <returns>The array that was just added to.</returns>
				inline array& push_back(value_type item) { __array[__size_used++] = item; return *this; }

				inline virtual iterator begin() override {
						return iterator(&__array[0]);
				}

				inline virtual iterator end() override {
						return iterator((&__array[SIZE]) + 1);
				}

				inline virtual const_iterator cbegin() const override {
						return const_iterator(&__array[0]);
				}

				inline virtual const_iterator cend() const override {
						return const_iterator((&__array[SIZE]) + 1);
				}

				inline reverse_iterator rbegin() {
						return reverse_iterator(&__array[SIZE]);
				}

				inline reverse_iterator rend() {
						return reverse_iterator((&__array[0]) - 1);
				}

				inline const_reverse_iterator crbegin() const {
						return const_reverse_iterator(&__array[SIZE]);
				}

				inline const_reverse_iterator crend() const {
						return const_reverse_iterator((&__array[0]) - 1);
				}

				/// <summary>
				/// Releases the memory held by the array.
				/// </summary>
				inline void release(){ if (__array != nullptr) delete[] __array; }

				/// <summary>
				/// This assigns new memory to the array if it is pointing to nothing.
				/// </summary>
				/// <param name="i">The size of the new array.</param>
				inline void assign(size_t i) { if (__array == nullptr) __array = new value_type[i]; }

		private:

				pointer __array;
				size_type __size_used;

				/// <summary>
				/// Copies one array to the other.
				/// </summary>
				/// <remark>
				/// This assumes that the 2 arrays already have allocated memory and are of correct size.
				/// </remark>
				/// <param name="from">The array to be copied.</param>
				/// <param name="to">The array to be copied to.</param>
				static void copy_array(const array& from, array& to) {
						for (size_type i = 0; i < from.size(); ++i) {
								to.__array[i] = from.__array[i];
						}
				}
		};

}

#endif
