#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <memory>
#include <stdexcept>
#include <utility>

#ifdef golden_growth && GROWTH_RATE
		#define GROWTH_RATE 1.6180339887
#else
		#define GROWTH_RATE 2
#endif

namespace blib {
		/// <summary>
		/// <para>This class serves as the equivalent of std::vector. 
		/// Most functions operate and have the same name as the std version.</para>
		/// <para>The growth rate is set by the GROWTH_RATE macro. If golden_growth macro is defined then growth
		/// is based on the golden ratio. By default it grows binarily.</para>
		/// </summary>
		/// <typeparam name="arrayType">The type of the dynamic array</typeparam>
		/// <typeparam name="CAPACITY">The starting size of the dynamic array, default is 0</typeparam>
		template <typename arrayType, size_t CAPACITY = 0>
		class dynamic_array {
		protected:
				std::unique_ptr<arrayType[]> __array = std::make_unique<arrayType[]>(CAPACITY);
				size_t __size = 0;
				size_t __capacity = CAPACITY;

				/// <summary>
				/// The iterator for the dynamic_array
				/// </summary>
				class __Iterator__ {

				};

				static void copyArrays(const dynamic_array& source, dynamic_array& destination);

		public:

				using value_type = arrayType;
				using pointer = arrayType*;
				using const_pointer = const arrayType*;
				using reference = arrayType&;
				using const_reference = const reference;
				using size_type = size_t;
				using iterator = __Iterator__;

				dynamic_array() = default;
				dynamic_array(dynamic_array&&) = default;
				dynamic_array& operator =(dynamic_array&&) = default;

				dynamic_array(const dynamic_array& da) { copyArrays(da, *this); }
				dynamic_array& operator =(const dynamic_array& da) { copyArrays(da, *this); return *this; }

				arrayType& operator [](size_t index) { return __array[index]; }
				const arrayType& operator[](size_t index) const { return __array[index]; }

				size_t size() const { return __size; }
				size_t capacity() const { return __capacity; }
				void capacity(size_t newCapacity) {
						if (newCapacity != __capacity) {
								dynamic_array<arrayType, newCapacity> temp;

								copyArrays(*this, temp); //copy the values in this to temp
								delete[] __array.release(); //delete this array
								__array = std::move(temp.__array); //transfer temp to this
								__capacity = newCapacity;
								__size = temp.__size;
						}
				}
				void resize(size_t newSize) {
						capacity(newSize);
				}
				
				dynamic_array& push_back(arrayType value) {
						if(__size < __capacity)
								__array[__size++] = value;
						else {
								//growth-rate is user controlled, defaults to 2, efficient is golden ration
								size_t newCapacity = (__size > 0) ? (int)(__capacity * GROWTH_RATE) : 1;
								capacity(newCapacity);
								__array[__size++] = value;
						}
						return *this;
				}

				arrayType pop_back() {
						if(__size > 0)
								return __array[__size--];
						throw std::out_of_range("Nothing is in the array");
				}

				dynamic_array& insert(arrayType value, iterator location, bool replace = false);

				arrayType delete_at(iterator location);

				arrayType& at(int index) {
						if (index > __capacity) throw std::out_of_range("index exceeds the capacity of the array");
						else if (index > __size) throw std::out_of_range("index exceeds the size of the array");
						return __array[index];
				}

				const arrayType& at(int index) const {
						if (index > __capacity) throw std::out_of_range("index exceeds the capacity of the array");
						else if (index > __size) throw std::out_of_range("index exceeds the size of the array");
						return __array[index];
				}

				arrayType& at(iterator index) {//**************************************************************************************
						if (index > __capacity) throw std::out_of_range("index exceeds the capacity of the array");
						else if (index > __size) throw std::out_of_range("index exceeds the size of the array");
						return __array[index];
				}

				void visit(void(*visitor)(arrayType&)) {
						for (int i = 0; i < size; ++i) {
								visitor(__array[i]);
						}
				}

				/// <summary>
				/// This function is used to perform element by element operations on the elements of the dynamic_array
				/// </summary>
				/// <param name="function">A function to be performed on all the elements of the dynamic_array as the lvalue</param>
				/// <param name="rvalue">The rvalue for the above function</param>
				/// <returns></returns>
				dynamic_array<arrayType> element_operator(arrayType(*function)(arrayType, arrayType), arrayType rvalue) {
						dynamic_array<arrayType> result;
						for (int i = 0; i < size(); ++i) {
								result.push_back(function(at(i), rvalue));
						}
						return result;
				}
		};

		template<typename arrayType, size_t CAPACITY>
		void george_data_structures::dynamic_array<arrayType, CAPACITY>::copyArrays(const dynamic_array& source, dynamic_array& destination)
		{
				if(destination.__capacity < source.__capacity)
						destination.capacity(source.__capacity);

				for (int i = 0; i < source.__size; ++i) {
						destination.__array[i] = std::move(source.__array[i]);
				}
		}


};

#endif