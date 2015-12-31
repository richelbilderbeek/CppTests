#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>

namespace Ui {
  class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

private slots:
  void onTimer() noexcept;

private:
  Ui::Dialog *ui;
  QGraphicsScene m_s1;
  QGraphicsScene m_s2;
};

#endif // DIALOG_H
