#include "list_node.h"

template <typename T> T get_kth_last(ListNode<T> *first_node, size_t k) {
  auto k_before = first_node;
  auto current_node = first_node;
  for (size_t i = 0; i < k; i++) {
    if (current_node->next == nullptr)
      return k_before->value;
    current_node = current_node->next;
  }
  while (current_node->next != nullptr) {
    k_before = k_before->next;
    current_node = current_node->next;
  }
  return k_before->value;
}
