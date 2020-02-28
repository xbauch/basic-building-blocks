#include <optional>

struct Point {
  double x;
  double y;
};

struct Line {
  Point start;
  Point end;
};

optional<Point> intersection(const Line &l1, const Line &l2) {}
