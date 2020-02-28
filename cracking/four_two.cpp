#include <queue>
#include <unordered_set>
#include <vector>

template <typename T> struct DirectedGraph {
  struct Node {
    T data;
    std::vector<Node *> successors;
  };

  Node *root;
  std::vector<Node> table;

  template <typename F> void bfs(F f, Node *starting_node = root) {
    std::queue<Node *> queue;
    std::unordered_set<Node *> seen;
    queue.push_back(starting_node);
    seen.insert(starting_node);
    while (!queue.empty()) {
      auto current = queue.pop_front();
      for (const auto suc : current.successors) {
        f(suc);
        if (seen.count(suc) == 0) {
          queue.push_back(suc);
          seen.insert(suc);
        }
      }
    }
  }
};

DirectedGraph<int> minimal_tree(const std::vector<int> &sorted_array) {
  DirectedGraph<int> resultG;
  auto size = sorted_array.size();
  resultG.table.resize(size);
  resultG.root = &resultG.table[0];
  for (size_t i = 0; i < size; i++) {
    resultG.table[i].data = sorted_array[i];

    if (2 * i + 1 < size)
      resultG.table[i].successors.push_back(&resultG.table[2 * i + 1]);
    if (2 * i + 2 < size)
      resultG.table[i].successors.push_back(&resultG.table[2 * i + 2]);
  }
  return resultG;
}
