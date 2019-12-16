#include <cassert>
#include <iostream>
#include <string>
#include <vector>

bool is_palindrome_permutation(const std::string &str) {
  std::vector<size_t> incidence_map(1 << sizeof(char) * 8, 0);
  for (const auto &c : str) {
    char lower_c = tolower(c);
    if (isspace(lower_c))
      continue;
    incidence_map[lower_c]++;
  }

  bool middle_used = false;
  for (const auto &incidence : incidence_map) {
    if (incidence & 1) {
      if (middle_used)
        return false;
      else
        middle_used = true;
    }
  }

  return true;
}

int main() {
  std::string input = "Tact Coat";
  std::cout << is_palindrome_permutation(input) << "\n";

  return 0;
}
