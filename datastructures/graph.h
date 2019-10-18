#include <map>
#include <vector>

template <typename Vertex, typename Edge, typename VertexLabel,
          typename EdgeLabel>
struct Graph {
  using Vertices = std::vector<Vertex>;
  using Edges = std::vector<Edge>;
  using VertexLabelling = std::map<Vertex, VertexLabel>;
  using EdgeLabelling = std::map<Edge, EdgeLabel>;

  Vertices vertices;
  Edges edges;
  VertexLabelling vertex_labels;
  EdgeLabelling edge_labels;

  using Id = std::size_t;

  Id vertex_to_id(const Vertex &v) const {return }

  void add_initial_vertex(Vertex &&v, VertexLabel &&vl) {
    vertex_labels.resize(vertices.size() + 1);
    vertex_labels[vertices.size()] = vl;
    vertices.push_back(v);
  }
  
  void add_edge(Vertex from, Vertex to, EdgeLabel el)
  {
    
  }

  void add_successor(Vertex from, Vertex to, VertexLabel vl, EdgeLabel el)
  {
    
  }
};
