#include <set>

template <typename T> struct ListNode {
  T value;
  ListNode *next;

  ListNode *append(T new_value) {
    next = new (ListNode);
    next->value = new_value;
    return next;
  }

  void remove_next() {
    if (next == nullptr)
      return;
    auto next_copy = next;
    next = next->next;
    delete (next);
  }

  void delete_next() {
    if (next == nullptr)
      return;
    next->delete_next();
    delete (next);
  }

  ListNode(T value) : value(value), next(nullptr) {}

  ~ListNode() {
    auto temp_next = next;
    while (temp_next != nullptr) {
      delete (temp_next);
    }
  }
};

template <typename T> void remove_duplicates_const(ListNode<T> *first_node) {
  if (first_node == nullptr)
    return;

  auto current_node = first_node;
  while (current_node->next != nullptr) {
    if (current_node->next->value == first_node->value)
      current_node->remove_next();
    current_node = current_node->next;
  }
  remove_duplicates_const(first_node->next);
}

template <typename T> void remove_duplicates(ListNode<T> *first_node) {
  if (first_node == nullptr)
    return;
  std::set<T> known_values;
  known_values.insert(first_node->value);
  auto current_node = first_node;
  while (current_node->next != nullptr) {
    if (known_values.count(current_node->next->value) == 0)
      known_values.insert(current_node->next->value);
    else
      current_node->remove_next();

    current_node = current_node->next;
  }
}
