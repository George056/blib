#pragma once

#include <memory>
#include <stdexcept>

namespace george_data_structures {

		enum class sort {
				LARGEST_FIRST,
				LARGEST_LAST
		};

		template <typename listType>
		class __singular_node__ {
				listType _data;
				std::unique_ptr<_node> _next = std::make_unique<_node>();
		};

		template <typename listType>
		class __doubly_node__ {
				listType _data;
				std::shared_ptr<_node> _next = std::make_unique<_node>();
				std::shared_ptr<_node> _parent = std::make_unique<_node>();
		};

		template <typename listType>
		class unsorted_list {
		protected:

				using _node = __singular_node__;

				std::unique_ptr<_node> _head;
				_node* _tail;

				class __Iterator__ {
				protected:
						_node* _itr;

						friend class unsorted_list<listType>;

						__Iterator__& operator [](int index) const {
								int count = 0;
								iterator itr = *this.begin();

								for (itr; itr < *this.end() && count < index; ++itr) {
										++count;
								}

								return itr;
						}

				public:

						__Iterator__(Node* node) : _itr{ node } {}
						listType& operator *() const {
								if (_itr == nullptr) throw std::logic_error("Dereferenced a iterator to end");
								return _itr->_data;
						}
						listType* operator ->() const {
								if (_itr == nullptr) throw std::logic_error("Dereferenced a iterator to end");
								return &_itr->_data;
						}

						__Iterator__& operator ++() {
								if (_itr == nullptr) throw std::logic_error("Incremented a iterator to end");
								_itr = _itr->_next.get();
								return *this;
						}
						__Iterator__ operator ++(int) {
								if (_itr == nullptr) throw std::logic_error("Incremented a iterator to end");
								auto result = *this;
								_itr = _itr->_next.get();
								return result;
						}


						bool operator ==(__Iterator__ itr) { return _itr == itr._itr; }
						bool operator !=(__Iterator__ itr) { return _itr != itr._itr; }
				};

				void copyNodes(std::unique_ptr<_node>& dest, const std::unique_ptr<_node>& src);
				
		public:
				using value_type = listType;
				using size_type = size_t;
				using reference = value_type&;
				using constant_reference = const value_type&;
				using pointer = value_type*;
				using const_pointer = const value_type*;
				using iterator = __Iterator__;

				unsorted_list() = default;

				unsorted_list(const unsorted_list& listToCopy) {
						copyNodes(_head, listToCopy._head);
				}
				unsorted_list& operator =(const unsorted_list& listToCopy) {
						copyNodes(_head, listToCopy._head);
				}

				unsorted_list(unsorted_list&& listToCopy) = default;
				unsorted_list& operator =(unsorted_list&& listToCopy) = default;

				listType& operator [](int index);
				listType& operator [](iterator itr);

				iterator begin() { return _head.get(); }
				iterator end() { return nullptr; }

				bool empty() { return _head == nullptr; }
				unsigned int size();

				unsorted_list& append(listType element);
				unsorted_list& insert(listType element, int indexOfInsert);

				void deleteItem(int index);
				void deleteItem(iterator& itr);
				void deleteItem(listType element);

				void visit(void(*visitor)(listType&));

		};

		template <typename listType>
		unsigned int unsorted_list<listType>::size() {
				unsigned int result = 0;

				for (auto ns : *this) {
						++result;
				}

				return result;
		}

		template <typename listType>
		void unsorted_list<listType>::copyNodes(std::unique_ptr<_node>& dest, const std::unique_ptr<_node>& src) {
				if (src == nullptr) {
						dest = nullptr;
				}
				else {
						if (dest) {
								dest->_data = src->_data;
						}
						else {
								dest = make_unique<_node>(src->_data, nullptr);
						}
						tail = dest.get();
						copyNodes(dest->_next, src->_next);
				}
		}

		template <typename listType>
		listType& unsorted_list<listType>::operator[](int index) {
				int count = 0;
				for (auto& location : *this) {
						if (count == index) return location;
						++count;
				}
		}

		template <typename listType>
		listType& unsorted_list<listType>::operator [](iterator itr) {
				return *itr;
		}

		template <typename listType>
		unsorted_list<listType>& unsorted_list<listType>::append(listType element) {
				if (_head) {
						tail->next = make_unique<_node>(std::move(element), nullptr);
						tail = tail->_next.get();
				}
				else {
						_head = make_unique<_node>(std::move(element), nullptr);
						tail = _head.get();
				}
		}

		template <typename listType>
		unsorted_list<listType>& unsorted_list<listType>::insert(listType element, int indexOfInsert) {
				int count = 0;
				iterator itr = *this.begin();
				
				for (itr; itr != *this.end() && count < --indexOfInsert; itr++) {
						++count;
				}

				itr._itr->_next = make_unique<_node>(std::move(element), std::move(insertAfter->_next));
				
				return *this;
		}

		template <typename listType>
		void unsorted_list<listType>::deleteItem(int index) {
				if (index > size()) throw std::out_of_range("The input index is beyond the end of the list.");

				itr = *this.begin();
				itr = itr[--index];
				itr->_next = std::move(itr->_next->_next);
		}

		template <typename listType>
		void unsorted_list<listType>::deleteItem(iterator& itr) {

		}

		template <typename listType>
		void unsorted_list<listType>::deleteItem(listType element) {

		}

		template<typename listType>
		void unsorted_list<listType>::visit(void(*visitor)(listType&))
		{
				Node* token = _head;

				while (token != nullptr)
				{
						visitor(token->_data);
						token = token->_next;
				}
		}

		template <typename listType>
		class doubly_linked_list {
		protected:
				using _node = __doubly_node__;

				std::shared_ptr<_node> _head;

				class __Doubly_List_Iterator__ : public unsorted_list::iterator {
				protected:

				public:
						__Doubly_List_Iterator__& operator --() {
								_itr = _itr->_parent;
								return *this;
						}

						__Doubly_List_Iterator__ operator --(int) {
								auto result = *this;
								_itr = _itr->_parent;
								return result;
						}
				};

		public:
				using iterator = __Doubly_List_Iterator__;

		};
}