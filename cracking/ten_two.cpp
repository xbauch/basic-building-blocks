#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void group_anagrams(vector<string> &input) {
  vector<pair<string, string>> pairs;
  for (const auto &i : input) {
    auto j = i;
    pairs.push_back({i, sort(j.begin(), j.end())});
  }

  sort(pairs.begin(), pairs.end(),
       [](const auto &left, const auto &right) -> bool {
         return left.second < right < second;
       });
  input.clear();
  for (const auto &p : pairs) {
    input.push_back(p.first);
  }
}
