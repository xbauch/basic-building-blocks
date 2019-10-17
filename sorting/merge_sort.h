#include <assert.h>
#include <iterator>
#include <vector>

template<typename ForwardIterator>
void merge(ForwardIterator left_start, ForwardIterator left_end,
           ForwardIterator right_start, ForwardIterator right_end,
           ForwardIterator output) {
  auto current_left = left_start;
  auto current_right = right_start;

  while (current_left != left_end || current_right != right_end) {
    if (current_left == left_end)
      *output++ = *current_right++;
    else if (current_right == right_end)
      *output++ = *current_left++;
    else if (*current_left < *current_right)
      *output++ = *current_left++;
    else
      *output++ = *current_right++;
  }
}

template<typename RandomAccessIterator>
void merge_sort(RandomAccessIterator from, RandomAccessIterator to) {
  auto current_size = to - from;
  if (current_size <= 1)
    return;

  auto half = from + current_size / 2;

  merge_sort(from, half);
  merge_sort(half, to);

  std::vector<typename RandomAccessIterator::value_type> output;
  output.resize(current_size);
  merge(from, half, half, to, output.begin());
  for (const auto &temp : output)
    *from++ = temp;
}
