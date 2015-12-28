#include "dialog.h"
#include "ui_dialog.h"
#include <boost/graph/graphviz.hpp>

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);

  std::ofstream f("filename.dot");

  boost::adjacency_list<> g;
  boost::add_vertex(g);
  std::vector<std::string> labels{ "A" };

  boost::write_graphviz(
    f,
    g,
    boost::make_label_writer(&labels[0])
  );
}

Dialog::~Dialog()
{
  delete ui;
}
