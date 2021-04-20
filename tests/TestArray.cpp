#include "Array.hpp"
#include<iostream>

using namespace george_data_structures;

int main() {

		array<int, 5> test;
		test.push_back(1).push_back(2).push_back(3);

		std::cout << test[0] << " " << test[1] << " " << test[2] << std::endl;

		array<int, 10> test2(test.begin(), test.end());

		return 0;
}