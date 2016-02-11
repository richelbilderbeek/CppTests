#include "dialog.h"
#include <QApplication>

//Q: Can I copy a QGraphicsScene?
//A: Yes
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Dialog w;
  w.show();

  return a.exec();
}
