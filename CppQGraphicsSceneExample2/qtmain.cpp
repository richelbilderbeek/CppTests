#include <cassert>
#include <iostream>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QFile>
#include <QTimer>

void RenderScene(QGraphicsScene& s, const std::string& filename)
{
  QGraphicsView v(&s);
  QImage image;
  QPainter painter(&image);
  painter.setRenderHint(QPainter::Antialiasing);
  s.render(&painter);
  image.save(filename.c_str());
  if (QFile::exists(filename.c_str()))
  {
    assert(!"Fixed");
  }
  else
  {
    std::cerr << "Does not work" << std::endl;
  }
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QGraphicsScene s;
  QGraphicsSimpleTextItem t;
  t.setText("My QGraphicsSimpleTextItem");
  t.setFlags(
      QGraphicsItem::ItemIsSelectable
    | QGraphicsItem::ItemIsMovable
  );

  s.addItem(&t);
  QGraphicsView v(&s);
  v.setGeometry(100,100,400,100);
  v.show();
  RenderScene(s,"test.png");
  return a.exec();
}
