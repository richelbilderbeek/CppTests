#include <boost/graph/adjacency_list.hpp>
#include <QCoreApplication>
#include <fstream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  std::ofstream f("filename.dot");
  boost::write_graphviz(
    f,
    boost::adjacency_list<>()
  );
  return a.exec();
}
