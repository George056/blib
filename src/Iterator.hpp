
#ifndef ITERATOR
#define ITERATOR

namespace george_data_structures {

		template <typename T>
		class iterator_base {
		private:
				using iterator = iterator_base;
		public:

				using value_type = T;
				using pointer_type = T*;

				iterator_base() = delete;
				iterator_base(iterator_base&&) = default;
				iterator_base(const iterator_base&) = default;
				virtual ~iterator_base() = default;

				iterator_base(pointer_type ptr) : __itr{ ptr } {}

				iterator& operator =(const pointer_type& ptr) { __itr = ptr; return *this; }

				virtual iterator& operator =(const iterator&) = default;
				virtual iterator& operator =(iterator&&) = default;

				iterator& operator ++() { ++__itr; return *this; }
				iterator& operator ++(int) {
						iterator result = *this;
						++__itr;
						return result;
				}

		protected:
				pointer_type __itr;

		};

		//read only
		template <typename T>
		class input_iterator : public iterator_base<T> {
		private:
				using iterator = input_iterator;
				
		public:

				using value_type = T;
				using reference_type = const T&;
				using pointer_type = const T*;

				input_iterator() = delete;
				input_iterator(const input_iterator&) = default;
				input_iterator(input_iterator&&) = default;
				virtual ~input_iterator() = default;

				input_iterator(pointer_type ptr) : iterator_base<T>::iterator_base(ptr) {}

				virtual iterator& operator =(const iterator&) = default;
				virtual iterator& operator =(iterator&&) = default;

				virtual inline reference_type operator *() { return *iterator_base<T>::__itr; }
				virtual inline pointer_type operator ->() { return &*iterator_base<T>::__itr; }

				inline bool operator ==(const iterator& itr) { return iterator_base<T>::__itr == itr.iterator_base<T>::__itr;	}
				inline bool operator !=(const iterator& itr) { return !(*this == itr); }

				iterator& operator ++() { ++iterator_base<T>::__itr; return *this; }
				iterator& operator ++(int) {
						iterator result = *this;
						++iterator_base<T>::__itr;
						return result;
				}
		};

		//write only
		template <typename T>
		class output_iterator : public iterator_base<T> {
		private:
				using iterator = output_iterator;

		public:

				using value_type = T;
				using reference_type = T&;
				using pointer_type = T*;

				output_iterator() = delete;
				output_iterator(const output_iterator&) = default;
				output_iterator(output_iterator&&) = default;
				virtual ~output_iterator() = default;

				output_iterator(pointer_type ptr) : iterator_base<T>::iterator_base(ptr) {}

				virtual iterator& operator =(const iterator&) = default;
				virtual iterator& operator =(iterator&&) = default;

				virtual inline reference_type operator *() { return *iterator_base<T>::__itr; }
				virtual inline pointer_type operator ->() { return &*iterator_base<T>::__itr; }

				iterator& operator ++() { ++iterator_base<T>::__itr; return *this; }
				iterator& operator ++(int) {
						iterator result = *this;
						++iterator_base<T>::__itr;
						return result;
				}
		};

		template <typename T>
		class forward_iterator : public output_iterator<T> {
		private:
				using iterator = forward_iterator;

		public:

				using value_type = T;
				using reference_type = T&;
				using pointer_type = T*;

				using output_iterator<T>::operator*;
				using output_iterator<T>::operator->;

				inline bool operator ==(const iterator& itr) { return iterator_base<T>::__itr == itr.iterator_base<T>::__itr; }
				inline bool operator !=(const iterator& itr) { return !(*this == itr); }

				forward_iterator() : iterator_base<T>::__itr{ nullptr } {}
				forward_iterator(pointer_type ptr) : output_iterator<T>::output_iterator(ptr) {}

				iterator& operator ++() { ++iterator_base<T>::__itr; return *this; }
				iterator& operator ++(int) {
						iterator result = *this;
						++iterator_base<T>::__itr;
						return result;
				}

		};

		template <typename T>
		class bidirectional_iterator : public forward_iterator<T> {
		private:
				using iterator = bidirectional_iterator;

		public:

				using value_type = T;
				using reference_type = T&;
				using pointer_type = T*;

				bidirectional_iterator(pointer_type ptr) : forward_iterator<T>::forward_iterator(ptr) {}

				using output_iterator<T>::operator*;
				using output_iterator<T>::operator->;
				using forward_iterator<T>::operator==;
				using forward_iterator<T>::operator!=;

				iterator& operator ++() { ++iterator_base<T>::__itr; return *this; }
				iterator& operator ++(int) {
						iterator result = *this;
						++iterator_base<T>::__itr;
						return result;
				}

				virtual iterator& operator --() { --iterator_base<T>::__itr; return *this; }
				virtual iterator& operator --(int) {
						iterator result = *this;
						--iterator_base<T>::__itr;
						return result;
				}

		};

		template <typename T>
		class random_access_iterator : public bidirectional_iterator<T> {
		private:
				using iterator = random_access_iterator;

		public:

				using value_type = T;
				using reference_type = T&;
				using pointer_type = T*;

				random_access_iterator(pointer_type ptr) : bidirectional_iterator<T>::bidirectional_iterator(ptr) {}

				using output_iterator<T>::operator*;
				using output_iterator<T>::operator->;
				using forward_iterator<T>::operator==;
				using forward_iterator<T>::operator!=;

				iterator& operator ++() { ++iterator_base<T>::__itr; return *this; }
				iterator& operator ++(int) {
						iterator result = *this;
						++iterator_base<T>::__itr;
						return result;
				}

				iterator& operator --() { --iterator_base<T>::__itr; return *this; }
				iterator& operator --(int) {
						iterator result = *this;
						--iterator_base<T>::__itr;
						return result;
				}

				iterator& operator +(size_t i) { return iterator(iterator_base<T>::__itr + i); }
				iterator& operator -(size_t i) { return iterator(iterator_base<T>::__itr - i); }

				friend random_access_iterator& operator +(size_t i, const random_access_iterator& itr) { 
						return random_access_iterator(itr.iterator_base<T>::__itr + i); 
				}
				friend random_access_iterator& operator -(size_t i, const random_access_iterator& itr) { 
						return random_access_iterator(itr.iterator_base<T>::__itr - i);
				}

				iterator& operator +=(size_t i) { iterator_base::__itr += i; return *this; }
				iterator& operator -=(size_t i) { iterator_base::__itr -= i; return *this; }

				value_type& operator [](size_t index) {
						return *(iterator_base<T>::__itr + index);
				}

		};

		

}

#endif
