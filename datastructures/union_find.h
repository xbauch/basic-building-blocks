#include <data>
#include <optional>

template <typename T> struct UnionFind {
  std::vector<T> data;

  struct Node {
    size_t rank;
    size_t id;
    std::optional<size_t> parent_id;
  };

  void make_set(T x) {}
  bool find(T x) {}
  void unite(T x, T y) {}
};
