#include <cassert>
#include <vector>

using Pixel = size_t;
using Matrix = std::vector<std::vector<Pixel>>;

void rotate_layer(Matrix &m, size_t layer) {
  size_t edge_size = (m.size() - layer) - 1;
  for (size_t offset = layer; offset < edge_size; offset++) {
    auto temp = m[layer][offset];
    m[layer][offset] = m[m.size() - offset][layer];
    m[m.size() - offset][layer] = m[m.size() - layer][m.size() - offset];
    m[m.size() - layer][m.size() - offset] = m[offset][m.size() - layer];
    m[offset][m.size() - layer] = temp;
  }
}

void rotate(Matrix &m) {
  if (m.size() < 2)
    return;
  assert(m.at(0).size() == m.size());

  for (size_t layer = 0; layer < m.size() / 2; layer++)
    rotate_layer(m, layer);
}
