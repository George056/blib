#ifndef NODE_ABSTRACT
#define NODE_ABSTRACT
#pragma once
/*
This file holds the abstract instances of nodes
*/

#include "Container.hpp"
#include<memory>

namespace blib {

		template <typename dataType>
		class node_abstract_singular {
		protected:
				using node_pointer = node_abstract_singular*;
				using node_reference_r = node_abstract_singular&;
				using node_reference_l = node_abstract_singular&&;
				using const_node_reference = const node_reference_r;

		public:
				using value_type = dataType;
				using reference = value_type&;
				using constant_reference = const value_type&;
				using pointer = value_type*;
				using const_pointer = const value_type*;

				value_type __data;
				node_pointer __next;

				node_abstract_singular() = default;
				virtual node_abstract_singular(const_node_reference) = 0;
				virtual node_abstract_singular(value_type data) : __data{ std::move(data) } { __next = nullptr; }
				virtual node_abstract_singular(node_reference_l) = default;

				virtual ~node_abstract_singular() = 0;

				virtual node_reference_r operator =(const_node_reference) = 0;
				virtual node_reference_r operator =(node_reference_l) = default;

				virtual value_type get_data() { return __data; }
				virtual node_reference_r set_next(node_pointer*) = 0;
		};

		template <typename dataType>
		class node_abstract_double : public node_abstract_singular{
		protected:
				using node_pointer = node_abstract_double*;
				using node_reference_r = node_abstract_double&;
				using node_reference_l = node_abstract_double&&;
				using const_node_reference = const node_reference_r;

		public:
				node_pointer; __parent;

				virtual node_abstract_double& set_parent(node_abstract_singular*) = 0;
		};

		template <typename dataType>
		class node_abstract_tree {
		protected:
				using node_pointer = node_abstract_tree*;
				using node_reference_r = node_abstract_tree&;
				using node_reference_l = node_abstract_tree&&;
				using const_node_reference = const node_reference_r;

		public:
				using value_type = dataType;
				using reference = value_type&;
				using constant_reference = const value_type&;
				using pointer = value_type*;
				using const_pointer = const value_type*;

				value_type __data;
				node_pointer __parent;
				node_pointer* __children;

				node_abstract_tree() = default;

		};

		template <typename dataType>
		class node_abstract_binary_tree {
		protected:
				using node_pointer = node_abstract_binary_tree*;
				using node_reference_r = node_abstract_binary_tree&;
				using node_reference_l = node_abstract_binary_tree&&;
				using const_node_reference = const node_reference_r;

		public:
				using value_type = dataType;
				using reference = value_type&;
				using constant_reference = const value_type&;
				using pointer = value_type*;
				using const_pointer = const value_type*;

				value_type __data;
				node_pointer __parent;
				node_pointer __left_child;
				node_pointer __right_child;
		};
}

#endif
