#ifndef STACK
#define STACK

#include "Node_Abstract.hpp"
#include "Container.hpp"
#include <stdexcept>

namespace blib {
		template <typename T>
		class stack : public container<T, T*, const T*> {
		public:
				using value_type = T;
				using size_type = size_t;
				using reference = value_type&;
				using constant_reference = const value_type&;
				using pointer = value_type*;
				using const_pointer = const value_type*;
				using iterator = pointer;
				using const_iterator = const_pointer;

		private:
				class node<T> : node_abstract_singular<T> {
				public:
						node(value_type item) : node_abstract_singular(item) { }
						reference value() { return __data; }
				};

		public:

		private:

		};
}

#endif

