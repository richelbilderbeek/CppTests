#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

int main()
{
  //Define the type of graph:
  //boost::adjacency_list is the 'Swiss army knife' graph
  using graph = boost::adjacency_list
  <
    //Store all out edges as a std::vector
    boost::vecS,
    //Store all vertices in a std::vector
    boost::vecS,
    //Relations are both ways (in this example)
    //(note: but you can freely change it to boost::directedS)
    boost::undirectedS,
    //All vertices are person names of type std::string
    boost::property<boost::vertex_name_t,std::string>,
    //All edges are relation of type std::string
    boost::property<boost::edge_name_t,std::string>
  >;

  graph  g;

  const graph::vertex_descriptor v1 = boost::add_vertex(std::string("Mr. A"),g);
  const graph::vertex_descriptor v2 = boost::add_vertex(std::string("Mrs. B"),g);
  const graph::vertex_descriptor v3 = boost::add_vertex(std::string("Dr. C"),g);
  const graph::vertex_descriptor v4 = boost::add_vertex(std::string("Prof. D"),g);
  boost::add_edge(v1,v2,std::string("Married"),g);
  boost::add_edge(v2,v3,std::string("Lovers"),g);
  boost::add_edge(v3,v4,std::string("Collegues"),g);
  boost::add_edge(v1,v4,std::string("Roommates"),g);

  //Writing graph to file
  {
    std::ofstream f("test.dot");
    //Problems:
    //- All names are replaced by numbers
    //- All relationships are omitted
    boost::write_graphviz(f,g);
    f.close();
  }

  //View the output directly using KGraphViewerer
  const int error{
    std::system("kgraphviewer test.dot")
  };
  if (error != 0) {
    std::cerr << "system commmand failed" << std::endl;
  }
}
