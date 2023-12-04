#ifndef BENCHMARKING_HPP
#define BENCHMARKING_HPP

#include <list>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <random>

std::list<int> generateRandomList(int size)
{
	std::list<int> randomList;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	for (int i = 0; i < size; ++i)
	{
		randomList.push_back(dist(gen));
	}

	return randomList;
}

uint64_t sum_of_list_squared(int num_entries)
{
	std::list<int> testList = generateRandomList(num_entries);

	std::list<int> squaredList;
	for (int value : testList)
	{
		squaredList.push_back(value * value);
	}

	return std::accumulate(squaredList.begin(), squaredList.end(), static_cast<uint64_t>(0));
}

#endif
