#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <fstream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include "mygraphicsview.h"
#pragma GCC diagnostic pop


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  const std::string filename = "tmp.svg";
  {
    std::ofstream f(filename.c_str());

    //Use '*(' and ')*' as raw string delimiters
    f
      << R"*(<svg xmlns="http://www.w3.org/2000/svg" version="1.1">)*"
      //Use these:
      << R"*(  <path d="M 20 40 C 100 -30 180 90 20 160 L 120 160" stroke="black" fill="none" stroke-width="5" />)*"
      //Or use these:
      //<< R"*(  <path d="M 0 -2 L 1.7320508075688774 0.99999999999999956 ,-1.7320508075688767 1.0000000000000009 z" stroke="black" fill="none" stroke-width="0.1"/>)*"
      //<< R"*(  <path d="M 0 -4 L 3.8042260651806141 -1.2360679774997898 ,2.351141009169893 3.2360679774997894 ,-2.3511410091698921 3.2360679774997902 ,-3.8042260651806146 -1.2360679774997889 z" stroke="black" fill="none" stroke-width="0.1"/>)*"
      //<< R"*(  <path d="M 0 -6 L 3.2438449047335851 -5.0475211969870877 ,5.4577919721271098 -2.4924900780113184 ,5.9389286512855968 0.85388902963971003 ,4.5344974461255498 3.9291644036717099 ,1.6903953410485779 5.756957841686984 ,-1.6903953410485764 5.7569578416869849 ,-4.5344974461255489 3.9291644036717113 ,-5.9389286512855959 0.85388902963971136 ,-5.4577919721271115 -2.4924900780113162 ,-3.2438449047335847 -5.0475211969870877 z" stroke="black" fill="none" stroke-width="0.1"/>)*"
      //<< R"*(  <path d="M 0 -8 L 2.3580413952872337 -7.6445824462891254 ,4.5065604645089765 -6.6099101945279592 ,6.2546518597442384 -4.9879184148698688 ,7.446989989153634 -2.9227281949311599 ,7.977630377449441 -0.59784074869139514 ,7.799423297454589 1.7801674716505147 ,6.9282032302755097 3.9999999999999982 ,5.4413819021673548 5.8644149746386107 ,3.4710699129404659 7.2077509432193523 ,1.1923381294093978 7.9106466098010282 ,-1.1923381294093958 7.9106466098010282 ,-3.4710699129404641 7.2077509432193532 ,-5.4413819021673531 5.8644149746386125 ,-6.928203230275507 4.0000000000000036 ,-7.799423297454589 1.7801674716505167 ,-7.977630377449441 -0.59784074869139492 ,-7.4469899891536357 -2.9227281949311563 ,-6.2546518597442393 -4.987918414869867 ,-4.5065604645089756 -6.6099101945279592 ,-2.3580413952872377 -7.6445824462891245 z" stroke="black" fill="none" stroke-width="0.1"/>)*"
      //Close file
      << R"*(</svg>)*"
    ;

  }
  QGraphicsSvgItem i(filename.c_str());

  i.setScale(1000.0);

  QGraphicsScene s;
  s.addItem(&i);

  MyGraphicsView w;
  w.setGeometry(100,100,200,200);
  w.setScene(&s);

  w.show();
  return a.exec();
}
