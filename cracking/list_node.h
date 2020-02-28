#include <initializer_list>
#include <string>

template <typename T> struct List {
  struct ListNode {
    T value;
    ListNode *next;

    ListNode() : value(T{}), next(nullptr) {}
    ListNode(T value) : value(value), next(nullptr) {}

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

    std::string print() {
      std::string result = "";
      auto current = this;
      while (current != nullptr) {
        result += std::to_string(current->value) + " -> ";
        current = current->next;
      }
      return result;
    }
  };
  ListNode *head;

  List() : head(nullptr) {}

  List(T value) {
    head = new (ListNode);
    head->value = value;
    head->next = nullptr;
  }
  List(std::initializer_list<T> l) : head(nullptr) {
    if (l.begin() == l.end())
      return;
    head = new (ListNode);
    head->value = *l.begin();
    auto current = head;
    for (auto it = l.begin() + 1; it != l.end(); it++) {
      current->next = new (ListNode);
      current->next->value = *it;
      current = current->next;
    }
  }

  ~List() {
    if (head == nullptr)
      return;
    head->delete_next();
    delete (head);
  }

  std::string print() {
    std::string result = "";
    auto current = head;
    while (current != nullptr) {
      result += std::to_string(current->value) + " -> ";
      current = current->next;
    }
    return result;
  }
};
