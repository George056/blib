#ifndef CONTAINER
#define CONTAINER
#pragma once
/*
This is an abstract class used as a base for all container types
*/
#include "../Iterator/Iterator.hpp"

namespace george_data_structures {

		template <typename dataType, class iterator_type, class const_iterator_type = input_iterator<dataType>>
		class container {
		public:
				using size_type = size_t;
				using iterator = iterator_type;
				using const_iterator = const_iterator_type;

		protected:
				size_type __size;
				inline void set_size(size_type i) { __size = i; }
				inline size_type get_size() { return __size; }

		public:

				container() : __size{ 0 } {}
				container(size_type size) : __size{ size } {}
				container(const container&) = default;
				container(container&&) = default;

				virtual ~container() = default;

				virtual container& operator =(const container&) = default;
				virtual container& operator =(container&&) = default;
				virtual dataType& operator [](size_type index) = 0;

				virtual dataType& at(size_t index) = 0;

				inline virtual size_type size() const { return __size; }
				inline virtual bool empty() const { return __size == 0; }

				virtual iterator begin() = 0;
				virtual iterator end() = 0;

				virtual const_iterator cbegin() const = 0;
				virtual const_iterator cend() const = 0;

		};

}

#endif
