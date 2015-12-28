#ifndef DIALOG_H
#define DIALOG_H

#include <boost/graph/adjacency_list.hpp> //Uncomment for compile error
#include <QDialog>

namespace Ui {
  class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

private:
  Ui::Dialog *ui;
};

#endif // DIALOG_H
