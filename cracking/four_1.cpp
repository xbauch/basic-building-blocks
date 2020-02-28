#include <queue>
#include <unordered_set>
#include <vector>

struct DirectedGraph {
  struct Node {
    std::vector<Node *> successors;
  };

  Node *root;

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

bool reachable(const DirectedGraph &G, const Node *s, const Node *t) {
  bool found = false;
  G.bfs(
      [&found, &t](const Node *v) {
        if (v == t)
          found = true;
      },
      s);
  return found;
}
