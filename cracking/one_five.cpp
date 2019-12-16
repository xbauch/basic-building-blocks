#include <cassert>
#include <iostream>
#include <string>
#include <vector>

bool one_away(const std::string &left, const std::string &right) {
  if (left == right)
    return true;

  const std::string &shorter = (left.size() > right.size() ? right : left);
  const std::string &longer = (left.size() >= right.size() ? left : right);

  if (longer.size() - shorter.size() > 1)
    return false;

  size_t first_diff = 0;
  for (; first_diff < longer.size(); first_diff++)
    if (left[first_diff] != right[first_diff])
      break;

  // replace case
  if (left.size() == right.size()) {
    first_diff++;
    for (; first_diff < left.size(); first_diff++)
      if (left[first_diff] != right[first_diff])
        return false;
    return true;
  }

  auto shorter_modified = shorter;

  shorter_modified.insert(first_diff, 1, longer[first_diff]);

  return shorter_modified == longer;
}

int main() {
  std::string input_left = "pale";
  std::string input_right = "bake";
  std::cout << one_away(input_left, input_right) << "\n";

  return 0;
}
