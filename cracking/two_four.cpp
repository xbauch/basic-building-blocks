#include <iostream>

#include "list_node.h"

template <typename T> void partition_around_x(List<T> &l, T x) {
  auto first_node = l.head;
  if (first_node == nullptr)
    return;

  auto previous_node = first_node;
  auto current_node = first_node->next;
  while (current_node != nullptr) {
    if (current_node->value < x) {
      previous_node->next = current_node->next;
      current_node->next = l.head;
      l.head = current_node;
      current_node = previous_node->next;
    } else {
      previous_node = current_node;
      current_node = current_node->next;
    }
  }
}

int main() {
  List<int> ln({3, 5, 8, 5, 10, 2, 1});
  std::cout << ln.print() << "\n";
  partition_around_x(ln, 5);
  std::cout << ln.print() << "\n";

  return 0;
}
