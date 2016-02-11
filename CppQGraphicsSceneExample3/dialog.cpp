#include "dialog.h"

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QTimer>
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);

  {
    QGraphicsSimpleTextItem * const t
      = new QGraphicsSimpleTextItem("Can I copy a QGraphicsScene?");
    t->setFlags(
        QGraphicsItem::ItemIsSelectable
      | QGraphicsItem::ItemIsMovable
    );
    m_s1.addItem(t);
  }
  {
    QGraphicsSimpleTextItem * const t
      = new QGraphicsSimpleTextItem("Yes");
    t->setFlags(
        QGraphicsItem::ItemIsSelectable
      | QGraphicsItem::ItemIsMovable
    );
    m_s2.addItem(t);
  }

  QTimer * const t{new QTimer(this)};
  connect(t,SIGNAL(timeout()),this,SLOT(onTimer()));
  t->setInterval(1000);
  t->start();
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::onTimer() noexcept
{
  static int cnt = 1;

  ui->m_view->setScene(cnt % 2 ? &m_s1 : &m_s2);
  ++cnt;
}
