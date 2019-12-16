#include <vector>

struct Coordinate {
  using DistanceType = int;

  Coordinate(DistanceType left, DistanceType right) : position{left, right} {}
  std::pair<DistanceType, DistanceType> position;

  DistanceType x() const { return position.first; }
  DistanceType y() const { return position.second; }
  Coordinate operator+(const Coordinate &other) const {
    return Coordinate{x() + other.x(), y() + other.y()};
  }
};

struct Submatrix {
  // tl----------tr
  // |           |
  // |           |
  // |           |
  // |           |
  // bl----------br
  Coordinate bottom_left_corner;
  Coordinate top_rigth_corner;

  Submatrix(Coordinate blc, Coordinate trc)
      : bottom_left_corner(blc), top_rigth_corner(trc) {}

  Coordinate tl() const {
    return Coordinate{bottom_left_corner.x(), top_rigth_corner.y()};
  }
  Coordinate tr() const { return top_rigth_corner; }
  Coordinate bl() const { return bottom_left_corner; }
  Coordinate br() const {
    return Coordinate{top_rigth_corner.x(), bottom_left_corner.y()};
  }

  size_t size() const { return tr().x() - bl().x(); }
  bool has_odd_size() const { return (size() & 1) == 1;}
};

Coordinate middle(Coordinate left, Coordinate right) {
  return Coordinate{(left.x() + right.x()) / 2, (left.y() + right.y()) / 2};
}

std::vector<Submatrix> split_sub(const Submatrix &origin) {
  if (origin.size() < 2) {
    return {origin};
  }
  const Coordinate::DistanceType offset = 1 + (origin.has_odd_size() ? 1 : 0);
  return {
      // bl
      Submatrix{origin.bl(), middle(origin.bl(), origin.tr())},
      // br
      Submatrix{middle(origin.bl(), origin.br()) + Coordinate{offset, 0},
                middle(origin.br(), origin.tr())},
      // tl
      Submatrix{middle(origin.bl(), origin.tl()),
                middle(origin.tl(), origin.tr()) + Coordinate{0, offset}},
      // tr
      Submatrix{middle(origin.bl(), origin.tr()) + Coordinate{offset, offset},
                origin.tr()}};
}
