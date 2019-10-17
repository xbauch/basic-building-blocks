#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>

#include "merge_sort.h"

const size_t field_size = 100000;
const size_t iterations = 10;
const size_t num_increases = 11;

int main() {

  std::vector<std::pair<size_t, size_t>> timing;

  for (size_t increase = 1; increase < num_increases; increase++) {

    std::vector<size_t> field(field_size * increase);
    std::iota(field.begin(), field.end(), 0);

    decltype(std::chrono::system_clock::now())::duration sort_time;

    for (size_t it = 0; it < iterations; it++) {
      std::shuffle(field.begin(), field.end(),
                   std::mt19937{std::random_device{}()});
      auto start = std::chrono::system_clock::now();
      merge_sort(field.begin(), field.end());
      sort_time += std::chrono::system_clock::now() - start;
    }

    timing.push_back({field.size() * iterations, sort_time.count()});
    std::cout << "Sorting " << field.size() * iterations
              << " elements took: " << sort_time.count() / 1000000 << " ms ("
              << (float)timing.back().second / (float)timing[0].second
              << "x).\n";
  }

  return 0;
}
