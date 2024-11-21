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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <glview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *button_filename;
    QLabel *label_filename;
    QLineEdit *lineEdit_xRot;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_edge_amount;
    QLabel *label_7;
    QLabel *label_vertex_amount;
    QLineEdit *lineEdit_yRot;
    QLabel *label_2;
    QLineEdit *lineEdit_zRot;
    QLabel *label_3;
    QLineEdit *lineEdit_y_move;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_z_move;
    QLineEdit *lineEdit_x_move;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_scale_name;
    QGroupBox *groupBox;
    QRadioButton *radioButton_solid_edge;
    QRadioButton *radioButton_dotted_edge;
    QPushButton *pushButton_color_edge;
    QLabel *label_12;
    QLabel *label_color_edge;
    QLineEdit *lineEdit_thickness_edge;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_no_point;
    QRadioButton *radioButton_cube;
    QPushButton *pushButton_color_vertex;
    QLabel *label_16;
    QLabel *label_color_vertex;
    QRadioButton *radioButton_sphere;
    QLineEdit *lineEdit_dot_size;
    QPushButton *pushButton_save_image_bmp;
    QPushButton *pushButton_film;
    QLabel *label_color_background;
    QPushButton *pushButton_color_background;
    glView *widget;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_central;
    QRadioButton *radioButton_ortho;
    QPushButton *pushButton_xRot_right;
    QPushButton *pushButton_yRot_right;
    QPushButton *pushButton_zRot_right;
    QPushButton *pushButton_xRot_left;
    QPushButton *pushButton_yRot_left;
    QPushButton *pushButton_zRot_left;
    QPushButton *pushButton_x_move_left;
    QPushButton *pushButton_x_move_right;
    QPushButton *pushButton_y_move_left;
    QPushButton *pushButton_y_move_right;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_z_move_left;
    QPushButton *pushButton_z_move_right;
    QPushButton *pushButton_apply_rotate;
    QPushButton *pushButton_apply_move;
    QLabel *label_6;
    QLabel *label_scale;
    QPushButton *pushButton;
    QLabel *label_8;
    QPushButton *pushButton_save_image_jpeg;
    QLabel *label_film_process;
    QLabel *label_film_process_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 1000);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        button_filename = new QPushButton(centralwidget);
        button_filename->setObjectName("button_filename");
        button_filename->setGeometry(QRect(970, 20, 100, 32));
        label_filename = new QLabel(centralwidget);
        label_filename->setObjectName("label_filename");
        label_filename->setGeometry(QRect(970, 890, 291, 21));
        label_filename->setWordWrap(true);
        lineEdit_xRot = new QLineEdit(centralwidget);
        lineEdit_xRot->setObjectName("lineEdit_xRot");
        lineEdit_xRot->setGeometry(QRect(1200, 85, 61, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(960, 85, 16, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(970, 860, 101, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(970, 920, 131, 16));
        label_edge_amount = new QLabel(centralwidget);
        label_edge_amount->setObjectName("label_edge_amount");
        label_edge_amount->setGeometry(QRect(1130, 920, 131, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(970, 950, 131, 16));
        label_vertex_amount = new QLabel(centralwidget);
        label_vertex_amount->setObjectName("label_vertex_amount");
        label_vertex_amount->setGeometry(QRect(1130, 950, 131, 16));
        lineEdit_yRot = new QLineEdit(centralwidget);
        lineEdit_yRot->setObjectName("lineEdit_yRot");
        lineEdit_yRot->setGeometry(QRect(1200, 115, 61, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(960, 115, 16, 21));
        lineEdit_zRot = new QLineEdit(centralwidget);
        lineEdit_zRot->setObjectName("lineEdit_zRot");
        lineEdit_zRot->setGeometry(QRect(1200, 145, 61, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(960, 145, 16, 21));
        lineEdit_y_move = new QLineEdit(centralwidget);
        lineEdit_y_move->setObjectName("lineEdit_y_move");
        lineEdit_y_move->setGeometry(QRect(1200, 255, 61, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(960, 225, 16, 21));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(960, 255, 16, 21));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(960, 285, 16, 21));
        lineEdit_z_move = new QLineEdit(centralwidget);
        lineEdit_z_move->setObjectName("lineEdit_z_move");
        lineEdit_z_move->setGeometry(QRect(1200, 285, 61, 21));
        lineEdit_x_move = new QLineEdit(centralwidget);
        lineEdit_x_move->setObjectName("lineEdit_x_move");
        lineEdit_x_move->setGeometry(QRect(1200, 225, 61, 21));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(970, 196, 171, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(970, 60, 171, 16));
        label_scale_name = new QLabel(centralwidget);
        label_scale_name->setObjectName("label_scale_name");
        label_scale_name->setGeometry(QRect(970, 327, 171, 16));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(960, 390, 301, 131));
        radioButton_solid_edge = new QRadioButton(groupBox);
        radioButton_solid_edge->setObjectName("radioButton_solid_edge");
        radioButton_solid_edge->setGeometry(QRect(10, 30, 141, 20));
        radioButton_dotted_edge = new QRadioButton(groupBox);
        radioButton_dotted_edge->setObjectName("radioButton_dotted_edge");
        radioButton_dotted_edge->setGeometry(QRect(150, 30, 141, 20));
        pushButton_color_edge = new QPushButton(groupBox);
        pushButton_color_edge->setObjectName("pushButton_color_edge");
        pushButton_color_edge->setGeometry(QRect(130, 60, 161, 32));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 100, 58, 16));
        label_color_edge = new QLabel(groupBox);
        label_color_edge->setObjectName("label_color_edge");
        label_color_edge->setGeometry(QRect(20, 64, 120, 20));
        lineEdit_thickness_edge = new QLineEdit(groupBox);
        lineEdit_thickness_edge->setObjectName("lineEdit_thickness_edge");
        lineEdit_thickness_edge->setGeometry(QRect(130, 100, 161, 21));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(960, 530, 301, 131));
        radioButton_no_point = new QRadioButton(groupBox_2);
        radioButton_no_point->setObjectName("radioButton_no_point");
        radioButton_no_point->setGeometry(QRect(10, 30, 71, 20));
        radioButton_cube = new QRadioButton(groupBox_2);
        radioButton_cube->setObjectName("radioButton_cube");
        radioButton_cube->setGeometry(QRect(200, 30, 71, 20));
        pushButton_color_vertex = new QPushButton(groupBox_2);
        pushButton_color_vertex->setObjectName("pushButton_color_vertex");
        pushButton_color_vertex->setGeometry(QRect(130, 60, 161, 32));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 100, 58, 16));
        label_color_vertex = new QLabel(groupBox_2);
        label_color_vertex->setObjectName("label_color_vertex");
        label_color_vertex->setGeometry(QRect(20, 64, 120, 20));
        radioButton_sphere = new QRadioButton(groupBox_2);
        radioButton_sphere->setObjectName("radioButton_sphere");
        radioButton_sphere->setGeometry(QRect(110, 30, 71, 20));
        lineEdit_dot_size = new QLineEdit(groupBox_2);
        lineEdit_dot_size->setObjectName("lineEdit_dot_size");
        lineEdit_dot_size->setGeometry(QRect(130, 100, 161, 21));
        pushButton_save_image_bmp = new QPushButton(centralwidget);
        pushButton_save_image_bmp->setObjectName("pushButton_save_image_bmp");
        pushButton_save_image_bmp->setGeometry(QRect(970, 790, 141, 32));
        pushButton_film = new QPushButton(centralwidget);
        pushButton_film->setObjectName("pushButton_film");
        pushButton_film->setGeometry(QRect(970, 820, 281, 32));
        label_color_background = new QLabel(centralwidget);
        label_color_background->setObjectName("label_color_background");
        label_color_background->setGeometry(QRect(970, 676, 120, 20));
        pushButton_color_background = new QPushButton(centralwidget);
        pushButton_color_background->setObjectName("pushButton_color_background");
        pushButton_color_background->setGeometry(QRect(1090, 670, 161, 32));
        widget = new glView(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 20, 900, 951));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(970, 710, 281, 51));
        radioButton_central = new QRadioButton(groupBox_3);
        radioButton_central->setObjectName("radioButton_central");
        radioButton_central->setGeometry(QRect(2, 23, 131, 20));
        radioButton_ortho = new QRadioButton(groupBox_3);
        radioButton_ortho->setObjectName("radioButton_ortho");
        radioButton_ortho->setGeometry(QRect(148, 23, 121, 20));
        pushButton_xRot_right = new QPushButton(centralwidget);
        pushButton_xRot_right->setObjectName("pushButton_xRot_right");
        pushButton_xRot_right->setGeometry(QRect(1090, 80, 100, 32));
        pushButton_yRot_right = new QPushButton(centralwidget);
        pushButton_yRot_right->setObjectName("pushButton_yRot_right");
        pushButton_yRot_right->setGeometry(QRect(1090, 110, 100, 32));
        pushButton_zRot_right = new QPushButton(centralwidget);
        pushButton_zRot_right->setObjectName("pushButton_zRot_right");
        pushButton_zRot_right->setGeometry(QRect(1090, 140, 100, 32));
        pushButton_xRot_left = new QPushButton(centralwidget);
        pushButton_xRot_left->setObjectName("pushButton_xRot_left");
        pushButton_xRot_left->setGeometry(QRect(980, 80, 100, 32));
        pushButton_yRot_left = new QPushButton(centralwidget);
        pushButton_yRot_left->setObjectName("pushButton_yRot_left");
        pushButton_yRot_left->setGeometry(QRect(980, 110, 100, 32));
        pushButton_zRot_left = new QPushButton(centralwidget);
        pushButton_zRot_left->setObjectName("pushButton_zRot_left");
        pushButton_zRot_left->setGeometry(QRect(980, 140, 100, 32));
        pushButton_x_move_left = new QPushButton(centralwidget);
        pushButton_x_move_left->setObjectName("pushButton_x_move_left");
        pushButton_x_move_left->setGeometry(QRect(980, 220, 100, 32));
        pushButton_x_move_right = new QPushButton(centralwidget);
        pushButton_x_move_right->setObjectName("pushButton_x_move_right");
        pushButton_x_move_right->setGeometry(QRect(1090, 220, 100, 32));
        pushButton_y_move_left = new QPushButton(centralwidget);
        pushButton_y_move_left->setObjectName("pushButton_y_move_left");
        pushButton_y_move_left->setGeometry(QRect(980, 250, 100, 32));
        pushButton_y_move_right = new QPushButton(centralwidget);
        pushButton_y_move_right->setObjectName("pushButton_y_move_right");
        pushButton_y_move_right->setGeometry(QRect(1090, 250, 100, 32));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(960, 350, 100, 32));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(1070, 350, 100, 32));
        pushButton_z_move_left = new QPushButton(centralwidget);
        pushButton_z_move_left->setObjectName("pushButton_z_move_left");
        pushButton_z_move_left->setGeometry(QRect(980, 280, 100, 32));
        pushButton_z_move_right = new QPushButton(centralwidget);
        pushButton_z_move_right->setObjectName("pushButton_z_move_right");
        pushButton_z_move_right->setGeometry(QRect(1090, 280, 100, 32));
        pushButton_apply_rotate = new QPushButton(centralwidget);
        pushButton_apply_rotate->setObjectName("pushButton_apply_rotate");
        pushButton_apply_rotate->setGeometry(QRect(1140, 54, 121, 32));
        pushButton_apply_move = new QPushButton(centralwidget);
        pushButton_apply_move->setObjectName("pushButton_apply_move");
        pushButton_apply_move->setGeometry(QRect(1140, 190, 121, 32));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1240, 358, 21, 16));
        label_scale = new QLabel(centralwidget);
        label_scale->setObjectName("label_scale");
        label_scale->setGeometry(QRect(1176, 355, 61, 21));
        label_scale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1140, 323, 121, 32));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(980, 770, 251, 16));
        pushButton_save_image_jpeg = new QPushButton(centralwidget);
        pushButton_save_image_jpeg->setObjectName("pushButton_save_image_jpeg");
        pushButton_save_image_jpeg->setGeometry(QRect(1120, 790, 131, 32));
        label_film_process = new QLabel(centralwidget);
        label_film_process->setObjectName("label_film_process");
        label_film_process->setGeometry(QRect(1230, 970, 41, 20));
        label_film_process->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_film_process_5 = new QLabel(centralwidget);
        label_film_process_5->setObjectName("label_film_process_5");
        label_film_process_5->setGeometry(QRect(1273, 970, 20, 20));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button_filename->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label_filename->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\265\320\261\320\265\321\200", nullptr));
        label_edge_amount->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275", nullptr));
        label_vertex_amount->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\270 \320\264\320\273\321\217 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\270 \320\264\320\273\321\217 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", nullptr));
        label_scale_name->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\261\321\200\320\260", nullptr));
        radioButton_solid_edge->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\273\320\276\321\210\320\275\320\260\321\217 \320\273\320\270\320\275\320\270\321\217", nullptr));
        radioButton_dotted_edge->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\320\275\320\272\321\202\320\270\321\200\320\275\320\260\321\217 \320\273\320\270\320\275\320\270\321\217", nullptr));
        pushButton_color_edge->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        label_color_edge->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\210\320\270\320\275\321\213", nullptr));
        radioButton_no_point->setText(QCoreApplication::translate("MainWindow", "\320\243\320\261\321\200\320\260\321\202\321\214", nullptr));
        radioButton_cube->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        pushButton_color_vertex->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        label_color_vertex->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        radioButton_sphere->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        pushButton_save_image_bmp->setText(QCoreApplication::translate("MainWindow", "bmp", nullptr));
        pushButton_film->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \321\201\320\272\321\200\320\270\320\275\320\272\320\260\321\201\321\202", nullptr));
        label_color_background->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        pushButton_color_background->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217", nullptr));
        radioButton_central->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        radioButton_ortho->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\260\321\217", nullptr));
        pushButton_xRot_right->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_yRot_right->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_zRot_right->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_xRot_left->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_yRot_left->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_zRot_left->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_x_move_left->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_x_move_right->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_y_move_left->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_y_move_right->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\265\320\271 \320\274\320\265\320\275\321\217", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "\320\241\321\212\320\265\321\210\321\214 \320\274\320\265\320\275\321\217", nullptr));
        pushButton_z_move_left->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_z_move_right->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_apply_rotate->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\321\202\320\270\320\274 \320\261\320\260\321\200\320\260\320\261\320\260\320\275", nullptr));
        pushButton_apply_move->setText(QCoreApplication::translate("MainWindow", "\320\242\321\203\320\264\321\213\320\274 \321\201\321\216\320\264\321\213\320\274", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_scale->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265:", nullptr));
        pushButton_save_image_jpeg->setText(QCoreApplication::translate("MainWindow", "jpeg", nullptr));
        label_film_process->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_film_process_5->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
