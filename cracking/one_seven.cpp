#include <vector>

using Pixel = size_t;

struct Coordinate {
  Coordinate(size_t left, size_t right) : position{left, right} {}
  std::pair<size_t, size_t> position;

  size_t x() const { return position.first; }
  size_t y() const { return position.second; }
};

using Submatrix = std::pair<Coordinate, Coordinate>;

struct Matrix {
  std::vector<std::vector<Pixel>> table;

  Pixel &get_at(Coordinate c) { return table[c.x()][c.y()]; }

  void swap(Coordinate left, Coordinate right) {
    std::swap(get_at(left), get_at(right));
  }

  void swap(Submatrix left, Submatrix right) {
    //TODO
  }

  size_t size() const { return table.size(); }
};

Coordinate middle(Coordinate left, Coordinate right) {
  return Coordinate{(left.x() + right.x()) / 2, (left.y() + right.y()) / 2};
}

size_t submatrix_size(Coordinate left, Coordinate right) {
  return (left.x() > right.x() ? left.x() - right.x() : right.x() - left.x());
}

void rotate_rec(Matrix &m, Coordinate low_left, Coordinate high_right) {
  auto current_size = submatrix_size(low_left, high_right);
  if (current_size < 2) {
    return;
  } else if (current_size == 2) {
    Coordinate low_right{high_right.x(), low_left.y()};
    Coordinate high_left{low_left.x(), high_right.y()};
    m.swap(low_left, low_right);
    m.swap(high_left,high_right);
    m.swap(high_left, low_right);
  } else if ((current_size & 1) == 0) {
    auto current_center = middle(low_left, high_right);
    rotate_rec(m, low_left, current_center);
    rotate_rec(m, Coordinate{low_left.x(), current_center.y()},
               Coordinate{current_center.x(), high_right.y()});
    rotate_rec(m, Coordinate{current_center.x(), low_left.y()},
               Coordinate{high_right.x(), current_center.y()});
    rotate_rec(m, current_center, high_right);
  } else {
    //TODO
  }
}

void rotate(Matrix &m) {
  rotate_rec(m, Coordinate{0, 0}, Coordinate{m.size(), m.size()});
}

int main() { return 0; }
