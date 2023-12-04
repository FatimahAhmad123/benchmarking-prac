#include <benchmark/benchmark.h>
#include "benchmarking.hpp"
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

BENCHMARK(BM_VectorSum)->Range(10, 10000);

BENCHMARK_MAIN();