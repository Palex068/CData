
#include <QApplication>
#include <iostream>

#include "Controller/controller.h"
#include "View/view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::Model *m = s21::Model::GetInstance();

  s21::Controller c(m);

  View w(nullptr, &c);

  w.show();
  return a.exec();
}
