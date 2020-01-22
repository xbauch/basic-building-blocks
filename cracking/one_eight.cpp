#include <algorithm>
#include <vector>

using Number = int;
using Matrix = std::vector<std::vector<Number>>;

template <typename Getter>
bool all_or_nothing(Getter at_m_n, size_t index, size_t bound) {
  bool all_zero = true;
  bool at_least_one_zero = false;
  for (size_t i = 0; i < bound; i++) {
    if (at_m_n(i, index) == 0)
      at_least_one_zero = true;
    else
      all_zero = false;
  }
  return !at_least_one_zero || all_zero;
}

bool is_zero_matrix(const Matrix &m) {
  if (m.empty())
    return true;

  for (size_t i = 0; i < m.size(); i++) {
    if (!all_or_nothing( // row
            [&m](size_t column_index, size_t row_index) {
              return m[row_index][column_index];
            },
            i, m[i].size()))
      return false;
  }
  for (size_t i = 0; i < m[0].size(); i++) {
    if (!all_or_nothing( // column
            [&m](size_t row_index, size_t column_index) {
              return m[row_index][column_index];
            },
            column_index, m.size()))
      return false;
  }
  return true;
}
