#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setParams(double hours, double salary)
{
    a = salary / 30 / 24;
    ui->salaryInHour_month->setNum(a);
    ui->salaryInMinute_month->setNum(a /= 60);
    ui->salaryInSec_month->setNum(a /= 60);

    b = salary / hours;
    ui->salaryInHour_wh->setNum(b);
    ui->salaryInMinute_wh->setNum(b /= 60);
    ui->salaryInSec_wh->setNum(b /= 60);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(on_Timer()));
    timer->start(1000); //< запустим таймер
}

void Form::on_Timer()
{
    month_summ += a;
    hours_summ += b;
    ui->salary_month->setNum(month_summ);
    ui->salary_wh->setNum(hours_summ);
}
