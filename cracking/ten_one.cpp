#include <algorithm>
#include <vector>

template <typename T>
void sorted_merge(std::vector<T> &array_A, const std::vector<T> &array_B) {
  // n = |A|, m = |B|
  // A = <a1, a2, .., an, _1, _2, .., _m, ..>
  // B = <b1, b2, .., bm>
  std::rotate(array_A.rbegin(), array_A.rbegin() + array_B.size(),
              array_A.rend());
  // A = <_1, _2, .., _m, a1, a2, .., an, ..>
  auto a_head = array_A.begin() + array_B.size();
  auto b_head = array_B.begin();
  for (auto current = array_A.begin();
       current != array_A.begin() + array_A.size() + array_B.size();
       current++) {
    if (*a_head < *b_head) {
      *current = *a_head;
      a_head++;
    } else {
      *current = *b_head;
      b_head++;
    }
  }
}

int main() {
  std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 0, 0, 0, 0, 0};
  std::vector<int> B = {1, 2, 3, 4, 5};

  sorted_merge(A, B);
  return 0;
}
