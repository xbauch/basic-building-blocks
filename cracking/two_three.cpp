#include "list_node.h"

template <typename T> delete_this(ListNode<T> *first_node, ListNode<T> *one) {
  auto current_node = first_node;
  while (current_node->next != nullptr) {
    if (current_node->next == one) {
      current_node->next = one->next;
      return;
    }
    current_node = current_node->next;
  }
}
