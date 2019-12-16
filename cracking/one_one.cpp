#include <iostream>
#include <string>
#include <vector>

bool is_unique(std::string &s) {
  std::vector<bool> already_seen(1 << sizeof(char) * 8, false);
  for (const auto &c : s) {
    if (already_seen[c])
      return false;
    else
      already_seen[c] = true;
  }
  return true;
}

bool is_unique_no_additional_data_structure(std::string &s) {
  const int char_max = 1 << sizeof(char) * 8;
  for (int c = 0; c < char_max; c++) {
    bool c_was_seen = false;
    for (const auto &input_c : s) {
      if (input_c != c)
        continue;
      if (c_was_seen)
        return false;
      else
        c_was_seen = true;
    }
  }
  return true;
}

int main() {
  std::string user_input;
  std::cin >> user_input;
  std::cout << is_unique(user_input) << "\n";

  return 0;
}
