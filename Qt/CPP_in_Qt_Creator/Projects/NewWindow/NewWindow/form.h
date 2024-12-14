#ifndef FORM_H
#define FORM_H

#include <QString>
#include <QTimer>
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void setParams(double hours, double salary);

private slots:
    void on_Timer();

private:
    Ui::Form *ui;
    QTimer *timer;
    double a, b, month_summ = 0, hours_summ = 0;
};

#endif // FORM_H
