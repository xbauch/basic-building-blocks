#include <algorithm>
#include <cassert>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

template <typename T>
T smallest_difference(const vector<T> &left, const vector<T> &right) {
  assert(!left.empty() && !right.empty());
  auto sorted_left = left;
  sort(sorted_left.begin(), sorted_left.end());
  auto sorted_right = right;
  sort(sorted_right.begin(), sorted_right.end());

  auto left_index = 0;
  auto right_index = 0;

  auto min_candidate = abs(sorted_left[left_index], sorted_right[right_index]);
  auto update_min_candidate = [&sorted_left, &sorted_right, &min_candidate,
                               &left_index, &right_index]() -> void {
    auto current_diff = abs(sorted_left[left_index], sorted_right[right_index]);
    if (current_diff < min_candidate)
      min_candidate = current_diff;
  };

  while (left_index < left.size() || right_index < right.size()) {
    if (left_index < left.size() &&
        sorted_left[left_index] <= sorted_right[right_index]) {
      update_min_candidate();
      left_index++;
      continue;
    }
    if (right_index < right.size() &&
        sorted_left[left_index] >= sorted_right[right_index]) {
      update_min_candidate();
      right_index++;
    }
  }
  return min_candidate;
}

int main() {
  vector<int> left = {1, 3, 15, 11, 2};
  vector<int> right = {23, 127, 235, 19, 8};

  cout << smallest_difference(left, right) << "\n";

  return 0;
}
