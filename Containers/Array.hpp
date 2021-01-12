#pragma once
#ifndef ARRAY
#define ARRAY

#include "../Container/Container.hpp"
#include <stdexcept>

namespace george_data_structures {

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

				array() : container<value_type, iterator, const_iterator>::container(SIZE), __size_used{ 0 } {
						__array = new value_type[SIZE];
				}

				//this uses a minimum copy, only having just enough cells to copy the given array.
				array(const array& ary) : __size_used{ ary.__size_used },
																container<value_type, iterator, const_iterator>::__size{ ary.get_size() }{
						__array = new value_type[ary.size()];
						copy_array(ary, *this);
				}

				virtual array& operator =(const array& ary) {
						if (container<value_type, iterator, const_iterator>::__size < ary.size())
								throw std::out_of_range("Size of the given array is too large.");
						__size_used = ary.__size_used;
						copy_array(ary, *this);
						return *this;
				}

				array(array&&) = default;
				virtual array& operator =(array&&) = default;

				//copy a c-array
				array(pointer ptr, size_type size) : container<value_type, iterator, const_iterator>::container(SIZE), __size_used{ size }{
						__array = new value_type[SIZE];
						if (size < SIZE)
								for (size_type i = 0; i < size; ++i) {
										__array[i] = ptr[i];
								}
						else
								std::out_of_range("Given C-array is bigger than memory alotted.");
				}

				array(pointer start, pointer end) : container<value_type, iterator, const_iterator>::container(SIZE) {
						size_type j = end - start;
						if(j > SIZE) std::out_of_range("Given series is bigger than memory alotted.");

						__array = new value_type[SIZE];

						for (size_type i = 0; i < j; ++i) {
								__array[i] = start[i];
						}
				}

				array(const_pointer start, const_pointer end) : container<value_type, iterator, const_iterator>::container(SIZE) {
						size_type j = end - start;
						if (j > SIZE) std::out_of_range("Given series is bigger than memory alotted.");

						__array = new value_type[j];

						for (size_type i = 0; i < j; ++i) {
								__array[i] = start[i];
						}
				}

				virtual ~array() { if (__array != nullptr) delete[] __array; }

				inline size_t max_size() const noexcept { return container<value_type, iterator, const_iterator>::__size; }
				inline virtual size_type size() const noexcept override { return __size_used; }
				inline virtual bool empty() const noexcept override { return __size_used == 0; }

				inline virtual value_type& operator [](size_type index) override { return __array[index]; }
				virtual value_type& at(size_type index) override {
						if (index > __size_used)
								throw std::out_of_range("exceeds the size of the array");
						return __array[index];
				}

				inline array& push_back(value_type item) { __array[__size_used++] = item; return *this; }

				inline virtual iterator begin() override {
						return iterator(&__array[0]);
				}

				inline virtual iterator end() override {
						return iterator((&__array[__size_used]) + 1);
				}

				inline virtual const_iterator cbegin() const override {
						return const_iterator(&__array[0]);
				}

				inline virtual const_iterator cend() const override {
						return const_iterator((&__array[__size_used]) + 1);
				}

				inline void relese(){ if (__array != nullptr) delete[] __array; }
				inline void assign(size_t i) { if (__array == nullptr) __array = new value_type[i]; }

		private:

				pointer __array;
				size_type __size_used;

				static void copy_array(const array& from, array& to) {
						for (size_type i = 0; i < from.size(); ++i) {
								to.__array[i] = from.__array[i];
						}
				}
		};

}

#endif
