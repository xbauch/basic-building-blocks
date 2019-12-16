#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool check_permutation(std::string &left, std::string &right) {
  if (left.size() != right.size())
    return false;

  std::vector<int> incidence_map(1 << sizeof(char) * 8, 0);
  for (const auto &c : left) {
    ++incidence_map[c];
  }
  for (const auto &c : right) {
    --incidence_map[c];
  }
  return std::for_each(incidence_map.begin(), incidence_map.end(),
                       [](int i) { return i == 0; });
}

int main() {
  std::string left_input, right_input;
  std::cin >> left_input;
  std::cin >> right_input;
  std::cout << check_permutation(left_input, right_input) << "\n";

  return 0;
}
