/**
 * \file  RandomNumberInitialization.cpp
 * \brief
 *
 * \todo
 */


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

struct RandomGenerator {
	int maxValue;
	RandomGenerator(int max) :
			maxValue(max) {
	}

	int operator()() {
		return rand() % maxValue;
	}
};

int main() {
	// Initialize a vector with 10 ints of value 0
	std::vector<int> vecOfRandomNums(10);

	// Generate 10 random numbers by lambda func and fill it in vector
	std::generate(vecOfRandomNums.begin(), vecOfRandomNums.end(), []() {
		return rand() % 100;
	});

	std::cout << "Random Number Generated by Lambda Function" << std::endl;
	for (int val : vecOfRandomNums)
		std::cout << val << " ";
	std::cout << "\n" << std::endl;

	// Generate 10 random numbers by a Functor and fill it in vector
	std::generate(vecOfRandomNums.begin(), vecOfRandomNums.end(),
			RandomGenerator(500));

	std::cout << "Random Number Generated by Functor" << std::endl;
	for (int val : vecOfRandomNums)
		std::cout << val << " ";
	std::cout << "" << std::endl;

	return 0;
}