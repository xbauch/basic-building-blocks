#pragma once

#include <map>

template <typename Key, typename T> struct vector_map {
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<Key, T>;
  using iterator = std::vector<value_type>::iterator;
  using size_type = size_t;

  vector_map() : sorted_size(0) {}

  void unchecked_insert(const value_type &value) { table.push_back(value); }

  bool checked_insert(const value_type &value) {
    auto find_result = find(value.key);
    if (unsorted_size() == 0 && find_result != sorted.end())
      return false;
    if (unsorted_size() > 0 && find_result != table.end())
      return false;
    unchecked_insert(value);
    return true;
  }

  bool contains(const Key &key) {
    auto find_result = find(key);
    return unsorted_size() == 0 ? find_result != sorted_end()
                                : find_result != table.end();
  }

  iterator find(const Key &key) {
    auto sorted_find = search_sorted(key);
    if (sorted_find != sorted_end())
      return sorted_find;
    if (unsorted_size() < max_unsorted_size)
      return std::find(
          sorted_end(), table.end(),
          [&key](const auto &value) -> bool { return value.first == key });

    sort();
    return search_sorted(key);
  }

  iterator begin() { return table.begin(); }
  iterator end() { return table.end(); }

private:
  size_t sorted_size;
  const size_type max_unsorted_size = 1 << 8;
  std::vector<value_type> table;

  iterator sorted_end() { return table.begin() + sorted_size; }

  size_type unsorted_size() { return table.size() - sorted_size; }

  bool comp(const value_type &left, const value_type &right) {
    return left.first < right.first;
  };

  void sort() {
    std::sort(sorted_end(), table.end(), comp);
    std::inplace_merge(table.begin(), sorted_end(), table.end(), comp);
    sorted_size = table.size();
  }

  iterator search_sorted(const Key &key) {
    auto first = std::lower_bound(table.begin(), table.end(),
                                  value_type{key, T{}}, comp);
    if (first != last && !comp(value, *first))
      return first;
  }
};
