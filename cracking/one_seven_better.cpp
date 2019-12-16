#include <cassert>
#include <vector>

#include "matrix.hpp"

using Pixel = size_t;

struct Matrix {
  std::vector<std::vector<Pixel>> table;

  Pixel &get_at(Coordinate c) { return table[c.x()][c.y()]; }

  void swap(Coordinate left, Coordinate right) {
    std::swap(get_at(left), get_at(right));
  }

  void swap(Submatrix left, Submatrix right) {
    assert(left.size() == right.size());
    for (size_t x_i = 0; x_i < left.size(); x_i++) {
      for (size_t y_i = 0; y_i < left.size(); y_i++) {
        const auto offset = Coordinate{(int)x_i, (int)y_i};
        swap(left.bl() + offset, right.bl() + offset);
      }
    }
  }

  size_t size() const { return table.size(); }

  void rotate_pixels(Coordinate bl, Coordinate br, Coordinate tl,
                     Coordinate tr) {
    swap(bl, br);
    swap(tl, tr);
    swap(tl, br);
  }
};

void rotate_cross(Matrix &m, Submatrix sub) {
  const auto sub_middle = middle(sub.bl(), sub.tr()) + Coordinate{1, 1};
  for (int off_center = 1; off_center <= (int)sub.size() / 2; off_center++) {
    m.rotate_pixels(sub_middle + Coordinate{0, -off_center},
                    sub_middle + Coordinate{off_center, 0},
                    sub_middle + Coordinate{-off_center, 0},
                    sub_middle + Coordinate{0, off_center});
  }
}

void rotate_rec(Matrix &m, Submatrix sub) {
  if (sub.size() < 2)
    return;
  if (sub.size() == 2) {
    m.rotate_pixels(sub.bl(), sub.br(), sub.tl(), sub.tr());
    return;
  }
  if (sub.has_odd_size()) {
    rotate_cross(m, sub);
  }
  auto subsubs = split_sub(sub);
  assert(subsubs.size() == 4);
  m.swap(subsubs[0], subsubs[1]);
  m.swap(subsubs[2], subsubs[3]);
  m.swap(subsubs[2], subsubs[1]);
  for (const auto &subsub : subsubs) {
    rotate_rec(m, subsub);
  }
}

void rotate(Matrix &m) {
  rotate_rec(
      m, Submatrix{Coordinate{0, 0}, Coordinate{(int)m.size(), (int)m.size()}});
}

int main() { return 0; }
