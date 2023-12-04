#include <benchmark/benchmark.h>
#include "benchmarking.hpp"
#include <list>

static void BM_ListSum(benchmark::State &state)
{
	int num_entries = state.range(0);

	for (auto _ : state)
	{
		auto result = sum_of_list_squared(num_entries);
		benchmark::DoNotOptimize(result);
	}
}

BENCHMARK(BM_ListSum)->Range(10, 10000);

BENCHMARK_MAIN();
