#include <cassert>
#include <iostream>
#include <cstring>

void urlify(char *str, size_t size) {
  int last_unused = size - 1;
  int last_non_space = size - 1;
  while (*(str + last_non_space) == ' ')
    --last_non_space;

  assert(last_non_space >= 0);

  for (int i = last_non_space; i >= 0; i--) {
    if (*(str + i) == ' ') {
      *(str + last_unused) = '0';
      --last_unused;
      *(str + last_unused) = '2';
      --last_unused;
      *(str + last_unused) = '\%';
      --last_unused;
    } else {
      *(str + last_unused) = *(str + i);
      --last_unused;
    }
  }
  assert(last_unused==-1);
}

int main() {
  std::string input = "Mr John Smith    ";
//std::string onput = "Mr%20John%20Smith";
  char input_copy[input.size()+1];
  std::memcpy(input_copy, input.c_str(), input.size());
  input_copy[input.size()]='\0';
  urlify(input_copy, input.size());

  std::cout << input_copy << "\n";

  return 0;
}
