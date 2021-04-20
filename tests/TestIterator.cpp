#include "Iterator.hpp"
#include <vector>
#include <iostream>
#include <typeinfo>

int main() {
		std::vector<int> test = { 1, 2, 3, 4 };
		george_data_structures::random_access_iterator<const int> itr(&test[0]);

		for (unsigned int i = 0; i < test.size(); ++i, ++itr) {
				std::cout << *itr << std::endl;
		}

		std::cout << itr[-2] << std::endl;

		itr = &test[2];

		std::cout << *itr << std::endl;

		return 0;
}