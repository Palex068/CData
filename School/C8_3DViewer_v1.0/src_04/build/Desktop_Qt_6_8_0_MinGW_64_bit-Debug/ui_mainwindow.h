/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <glview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QWidget *centralwidget;
    glview *widget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_edges;
    QPushButton *button_jpeg;
    QLabel *label_translate_z;
    QLabel *label_translate_x;
    QLineEdit *rotate_x;
    QLabel *label_translate_y;
    QPushButton *button_setting;
    QPushButton *button_Translate;
    QLineEdit *translate_z;
    QPushButton *button_Rotate;
    QLineEdit *scaleLineEdit;
    QLabel *label_vertexes;
    QLabel *label_rotate_x;
    QLabel *label_path;
    QLabel *label_rotate_y;
    QPushButton *button_open_path;
    QLineEdit *rotate_z;
    QPushButton *button_gif;
    QLineEdit *rotate_y;
    QLineEdit *translate_x;
    QPushButton *scalingButton;
    QPushButton *button_bmp;
    QLineEdit *translate_y;
    QLabel *label_rotate_z;
    QMenuBar *menubar;
    QMenu *menuAr;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(990, 600);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new glview(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 580, 580));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(600, 10, 384, 561));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(-1);
        gridLayout->setContentsMargins(0, 0, 10, 0);
        label_edges = new QLabel(gridLayoutWidget);
        label_edges->setObjectName("label_edges");
        label_edges->setEnabled(false);
        label_edges->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(label_edges, 3, 1, 1, 2);

        button_jpeg = new QPushButton(gridLayoutWidget);
        button_jpeg->setObjectName("button_jpeg");
        button_jpeg->setMinimumSize(QSize(170, 0));
        button_jpeg->setMaximumSize(QSize(170, 16777215));

        gridLayout->addWidget(button_jpeg, 13, 1, 1, 1);

        label_translate_z = new QLabel(gridLayoutWidget);
        label_translate_z->setObjectName("label_translate_z");
        label_translate_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_translate_z, 6, 1, 1, 1);

        label_translate_x = new QLabel(gridLayoutWidget);
        label_translate_x->setObjectName("label_translate_x");
        label_translate_x->setMaximumSize(QSize(123123, 16777215));
        label_translate_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_translate_x, 4, 1, 1, 1);

        rotate_x = new QLineEdit(gridLayoutWidget);
        rotate_x->setObjectName("rotate_x");

        gridLayout->addWidget(rotate_x, 8, 2, 1, 1);

        label_translate_y = new QLabel(gridLayoutWidget);
        label_translate_y->setObjectName("label_translate_y");
        label_translate_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_translate_y, 5, 1, 1, 1);

        button_setting = new QPushButton(gridLayoutWidget);
        button_setting->setObjectName("button_setting");

        gridLayout->addWidget(button_setting, 15, 1, 1, 2);

        button_Translate = new QPushButton(gridLayoutWidget);
        button_Translate->setObjectName("button_Translate");

        gridLayout->addWidget(button_Translate, 7, 1, 1, 2);

        translate_z = new QLineEdit(gridLayoutWidget);
        translate_z->setObjectName("translate_z");

        gridLayout->addWidget(translate_z, 6, 2, 1, 1);

        button_Rotate = new QPushButton(gridLayoutWidget);
        button_Rotate->setObjectName("button_Rotate");

        gridLayout->addWidget(button_Rotate, 11, 1, 1, 2);

        scaleLineEdit = new QLineEdit(gridLayoutWidget);
        scaleLineEdit->setObjectName("scaleLineEdit");

        gridLayout->addWidget(scaleLineEdit, 12, 2, 1, 1);

        label_vertexes = new QLabel(gridLayoutWidget);
        label_vertexes->setObjectName("label_vertexes");
        label_vertexes->setEnabled(false);
        label_vertexes->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(label_vertexes, 2, 1, 1, 2);

        label_rotate_x = new QLabel(gridLayoutWidget);
        label_rotate_x->setObjectName("label_rotate_x");
        label_rotate_x->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_rotate_x, 8, 1, 1, 1);

        label_path = new QLabel(gridLayoutWidget);
        label_path->setObjectName("label_path");
        label_path->setEnabled(false);
        label_path->setMaximumSize(QSize(16777215, 15));
        label_path->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_path, 1, 0, 1, 3);

        label_rotate_y = new QLabel(gridLayoutWidget);
        label_rotate_y->setObjectName("label_rotate_y");
        label_rotate_y->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_rotate_y, 9, 1, 1, 1);

        button_open_path = new QPushButton(gridLayoutWidget);
        button_open_path->setObjectName("button_open_path");

        gridLayout->addWidget(button_open_path, 0, 1, 1, 2);

        rotate_z = new QLineEdit(gridLayoutWidget);
        rotate_z->setObjectName("rotate_z");

        gridLayout->addWidget(rotate_z, 10, 2, 1, 1);

        button_gif = new QPushButton(gridLayoutWidget);
        button_gif->setObjectName("button_gif");

        gridLayout->addWidget(button_gif, 14, 1, 1, 2);

        rotate_y = new QLineEdit(gridLayoutWidget);
        rotate_y->setObjectName("rotate_y");

        gridLayout->addWidget(rotate_y, 9, 2, 1, 1);

        translate_x = new QLineEdit(gridLayoutWidget);
        translate_x->setObjectName("translate_x");

        gridLayout->addWidget(translate_x, 4, 2, 1, 1);

        scalingButton = new QPushButton(gridLayoutWidget);
        scalingButton->setObjectName("scalingButton");

        gridLayout->addWidget(scalingButton, 12, 1, 1, 1);

        button_bmp = new QPushButton(gridLayoutWidget);
        button_bmp->setObjectName("button_bmp");
        button_bmp->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(button_bmp, 13, 2, 1, 1);

        translate_y = new QLineEdit(gridLayoutWidget);
        translate_y->setObjectName("translate_y");

        gridLayout->addWidget(translate_y, 5, 2, 1, 1);

        label_rotate_z = new QLabel(gridLayoutWidget);
        label_rotate_z->setObjectName("label_rotate_z");
        label_rotate_z->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_rotate_z, 10, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 990, 24));
        menuAr = new QMenu(menubar);
        menuAr->setObjectName("menuAr");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAr->menuAction());
        menuAr->addAction(actionClose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_edges->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        button_jpeg->setText(QCoreApplication::translate("MainWindow", "Save to jpeg", nullptr));
        label_translate_z->setText(QCoreApplication::translate("MainWindow", "Z :", nullptr));
        label_translate_x->setText(QCoreApplication::translate("MainWindow", "X :", nullptr));
        label_translate_y->setText(QCoreApplication::translate("MainWindow", "Y :", nullptr));
        button_setting->setText(QCoreApplication::translate("MainWindow", "Setting", nullptr));
        button_Translate->setText(QCoreApplication::translate("MainWindow", "Moving", nullptr));
        button_Rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_vertexes->setText(QCoreApplication::translate("MainWindow", "Vertexes: ", nullptr));
        label_rotate_x->setText(QCoreApplication::translate("MainWindow", "X :", nullptr));
        label_path->setText(QCoreApplication::translate("MainWindow", "No path", nullptr));
        label_rotate_y->setText(QCoreApplication::translate("MainWindow", "Y :", nullptr));
        button_open_path->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        button_gif->setText(QCoreApplication::translate("MainWindow", "Record gif", nullptr));
        scalingButton->setText(QCoreApplication::translate("MainWindow", "Scaling", nullptr));
        button_bmp->setText(QCoreApplication::translate("MainWindow", "Save to bmp", nullptr));
        label_rotate_z->setText(QCoreApplication::translate("MainWindow", "Z :", nullptr));
        menuAr->setTitle(QCoreApplication::translate("MainWindow", "Ar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
