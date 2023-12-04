#include <benchmark/benchmark.h>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <random>

static void BM_VectorSum(benchmark::State &state)
{
	int num_entries = state.range(0);

	for (auto _ : state)
	{
		auto result = sum_of_vector_squared(num_entries);
		benchmark::DoNotOptimize(result);
	}
}

// Set the vector size as a range for the benchmark
BENCHMARK(BM_VectorSum)->Range(10, 10000);

std::vector<int> generateRandomVector(int size)
{
	std::vector<int> randomVector(size);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	std::generate(randomVector.begin(), randomVector.end(), [&]()
				  { return dist(gen); });

	return randomVector;
}

uint64_t sum_of_vector_squared(int num_entries)
{
	std::vector<int> testVector = generateRandomVector(num_entries);

	std::vector<int> squaredVector;
	for (int value : testVector)
	{
		squaredVector.push_back(value * value);
	}
	return std::accumulate(squaredVector.begin(), squaredVector.end(), static_cast<uint64_t>(0));
}
