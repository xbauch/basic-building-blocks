#include <string>

bool isSubstring(const std::string &smaller, const std::string &larger) {
  return larger.find(smaller) != std::string::npos;
}

bool is_rotation_of(const std::string &s1, const std::string &s2)
{
  return isSubstring(s1, s2 + s2);
}

int main()
{
  std::string s1 = "waterbottle";
  std::string s2 = "erbottlewat";

  if (!is_rotation_of(s1,s2))
    return 1;

  return 0;
}
