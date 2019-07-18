#include <vector>

template <typename T>
void merge(std::vector<T> &input, size_t left_start, size_t middle,
           size_t right_end) {
  size_t current_left = left_start;
  size_t current_right = middle;
  std::vector<T> output;
  for (size_t i = left_start; i < right_end; i++) {
    if (input[current_left] < input[current_right])
      output.push_back(input[current_left++]);
    else
      output.push_back(input[current_right++]);
  }

  size_t j = 0;
  for (size_t i = left_start; i < right_end; i++)
    input[i] = output[j++];
}

template <typename T>
void merge_sort(std::vector<T> &input, size_t from, size_t to) {
  size_t current_size = to - from;
  if (current_size <= 1)
    return;

  size_t half = from + current_size / 2;

  merge_sort(input, from, half);
  merge_sort(input, half, to);
  merge(input, from, half, to);
}

template <typename T> void merge_sort(std::vector<T> &input) {
  merge_sort(input, 0, input.size());
}

