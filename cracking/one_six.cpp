#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::pair<bool, std::string> maybe_compress(const std::string str) {
  if (str.size() < 3)
    return std::make_pair(false, str);

  std::stringstream result_stream;
  char current_c = str[0];
  size_t current_count = 1;
  for (size_t i = 1; i < str.size(); i++) {
    if (str[i] != current_c) {
      result_stream << current_c << current_count;
      current_c = str[i];
      current_count = 1;
    } else
      ++current_count;
  }
  result_stream << current_c << current_count;

  std::string result = result_stream.str();
  return (result.size() >= str.size() ? std::make_pair(false, str)
                                      : std::make_pair(true, result));
}

int main() {
  std::string input = "aabcccccaaa";
  std::cout << maybe_compress(input).second << "\n";
  input = "aabcaaa";
  std::cout << maybe_compress(input).second << "\n";

  return 0;
}
