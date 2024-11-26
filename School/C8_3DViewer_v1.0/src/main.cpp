#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWindow w;
  w.setWindowTitle("3D_Viewer_v1.0");
  w.show();
  return app.exec();
}
