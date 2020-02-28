#include <iostream>
#include <optional>

#include "list_node.h"

template <typename T>
auto sum_rec(typename List<T>::ListNode *left,
             typename List<T>::ListNode *right, List<T> &result)
    -> std::optional<T> {
  std::cout << "foo: " << result.print() << "\n";

  if (left->next == nullptr && right->next == nullptr) {
    return {};
  }
  auto carry_over = std::optional<T>{};
  if (left->next == nullptr) {
    carry_over = sum_rec<T>(left, right->next, result);
  } else if (right->next == nullptr) {
    carry_over = sum_rec<T>(left->next, right, result);
  } else
    carry_over = sum_rec<T>(left->next, right->next, result);

  auto current_sum = left->value + right->value;
  if (carry_over.has_value())
    current_sum += *carry_over;
  auto carry_over_next = current_sum / 10;
  auto current_value = current_sum % 10;

  auto new_node = new (typename List<T>::ListNode);
  new_node->value = current_value;
  new_node->next = result.head;
  result.head = new_node;

  std::cout << "bar: " << result.print() << "\n";

  if (carry_over_next > 0)
    return carry_over_next;
  else
    return {};
}

// In :  (7->1->6), (5->9->2)
// Out : (2->1->9)
template <typename T> List<T> sum(List<T> left, List<T> right) {
  List<T> new_list;
  auto carry_over = sum_rec<T>(left.head, right.head, new_list);
  if (carry_over.has_value()) {
    auto new_node = new (typename List<T>::ListNode);
    new_node->value = *carry_over;
    new_node->next = new_list.head;
    new_list.head = new_node;
  }
  return new_list;
}

int main() {
  List<int> list_1({7, 1, 6});
  List<int> list_2({5, 9, 2});

  auto result_list = sum(list_1, list_2);
  std::cout << result_list.print() << "\n";

  return 0;
}
