/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_options
{
public:
    QGridLayout *gridLayout;
    QSlider *horizontalSlider_size_vertexes;
    QPushButton *button_apply;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *radioButton_vertex_cube;
    QLabel *label_projection;
    QLabel *label;
    QRadioButton *radioButton_parallel;
    QPushButton *button_cancel;
    QSlider *horizontalSlider_wigth_edges;
    QLabel *label_3;
    QRadioButton *radioButton_central;
    QRadioButton *radioButton_vertex_shere;
    QToolButton *button_color_edges;
    QToolButton *button_color_vertexes;
    QLabel *label_7;
    QLabel *label_2;
    QPushButton *button_background;
    QRadioButton *radioButton_solid;
    QLabel *label_edges;
    QRadioButton *radioButton_dashed;
    QRadioButton *radioButton_vertex_nope;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QDialog *options)
    {
        if (options->objectName().isEmpty())
            options->setObjectName("options");
        options->resize(300, 390);
        gridLayout = new QGridLayout(options);
        gridLayout->setObjectName("gridLayout");
        horizontalSlider_size_vertexes = new QSlider(options);
        horizontalSlider_size_vertexes->setObjectName("horizontalSlider_size_vertexes");
        horizontalSlider_size_vertexes->setMinimum(1);
        horizontalSlider_size_vertexes->setMaximum(20);
        horizontalSlider_size_vertexes->setValue(10);
        horizontalSlider_size_vertexes->setSliderPosition(10);
        horizontalSlider_size_vertexes->setOrientation(Qt::Horizontal);
        horizontalSlider_size_vertexes->setTickPosition(QSlider::NoTicks);
        horizontalSlider_size_vertexes->setTickInterval(1);

        gridLayout->addWidget(horizontalSlider_size_vertexes, 14, 1, 1, 1);

        button_apply = new QPushButton(options);
        button_apply->setObjectName("button_apply");
        button_apply->setMinimumSize(QSize(140, 0));

        gridLayout->addWidget(button_apply, 17, 1, 1, 1);

        label_4 = new QLabel(options);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(16777215, 20));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 9, 0, 1, 2);

        label_5 = new QLabel(options);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 10, 0, 1, 1);

        label_6 = new QLabel(options);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 13, 0, 1, 1);

        radioButton_vertex_cube = new QRadioButton(options);
        buttonGroup_2 = new QButtonGroup(options);
        buttonGroup_2->setObjectName("buttonGroup_2");
        buttonGroup_2->addButton(radioButton_vertex_cube);
        radioButton_vertex_cube->setObjectName("radioButton_vertex_cube");

        gridLayout->addWidget(radioButton_vertex_cube, 11, 1, 1, 1);

        label_projection = new QLabel(options);
        label_projection->setObjectName("label_projection");
        label_projection->setMaximumSize(QSize(16777215, 20));
        label_projection->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_projection, 0, 0, 1, 2);

        label = new QLabel(options);
        label->setObjectName("label");
        label->setMaximumSize(QSize(16777215, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 5, 0, 1, 1);

        radioButton_parallel = new QRadioButton(options);
        radioButton_parallel->setObjectName("radioButton_parallel");

        gridLayout->addWidget(radioButton_parallel, 2, 0, 1, 1);

        button_cancel = new QPushButton(options);
        button_cancel->setObjectName("button_cancel");
        button_cancel->setMinimumSize(QSize(140, 0));

        gridLayout->addWidget(button_cancel, 17, 0, 1, 1);

        horizontalSlider_wigth_edges = new QSlider(options);
        horizontalSlider_wigth_edges->setObjectName("horizontalSlider_wigth_edges");
        horizontalSlider_wigth_edges->setMouseTracking(false);
        horizontalSlider_wigth_edges->setTabletTracking(false);
        horizontalSlider_wigth_edges->setAcceptDrops(false);
        horizontalSlider_wigth_edges->setInputMethodHints(Qt::ImhNone);
        horizontalSlider_wigth_edges->setMinimum(1);
        horizontalSlider_wigth_edges->setMaximum(11);
        horizontalSlider_wigth_edges->setSliderPosition(5);
        horizontalSlider_wigth_edges->setOrientation(Qt::Horizontal);
        horizontalSlider_wigth_edges->setInvertedAppearance(false);
        horizontalSlider_wigth_edges->setTickPosition(QSlider::NoTicks);
        horizontalSlider_wigth_edges->setTickInterval(1);

        gridLayout->addWidget(horizontalSlider_wigth_edges, 8, 1, 1, 1);

        label_3 = new QLabel(options);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        radioButton_central = new QRadioButton(options);
        radioButton_central->setObjectName("radioButton_central");

        gridLayout->addWidget(radioButton_central, 2, 1, 1, 1);

        radioButton_vertex_shere = new QRadioButton(options);
        buttonGroup_2->addButton(radioButton_vertex_shere);
        radioButton_vertex_shere->setObjectName("radioButton_vertex_shere");

        gridLayout->addWidget(radioButton_vertex_shere, 10, 1, 1, 1);

        button_color_edges = new QToolButton(options);
        button_color_edges->setObjectName("button_color_edges");
        button_color_edges->setMinimumSize(QSize(40, 20));

        gridLayout->addWidget(button_color_edges, 7, 1, 1, 1);

        button_color_vertexes = new QToolButton(options);
        button_color_vertexes->setObjectName("button_color_vertexes");
        button_color_vertexes->setMinimumSize(QSize(40, 20));

        gridLayout->addWidget(button_color_vertexes, 13, 1, 1, 1);

        label_7 = new QLabel(options);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 14, 0, 1, 1);

        label_2 = new QLabel(options);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 7, 0, 1, 1);

        button_background = new QPushButton(options);
        button_background->setObjectName("button_background");
        button_background->setStyleSheet(QString::fromUtf8("Background "));

        gridLayout->addWidget(button_background, 3, 0, 1, 2);

        radioButton_solid = new QRadioButton(options);
        buttonGroup = new QButtonGroup(options);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(radioButton_solid);
        radioButton_solid->setObjectName("radioButton_solid");

        gridLayout->addWidget(radioButton_solid, 5, 1, 1, 1);

        label_edges = new QLabel(options);
        label_edges->setObjectName("label_edges");
        label_edges->setMaximumSize(QSize(16777215, 20));
        label_edges->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_edges, 4, 0, 1, 2);

        radioButton_dashed = new QRadioButton(options);
        buttonGroup->addButton(radioButton_dashed);
        radioButton_dashed->setObjectName("radioButton_dashed");
        radioButton_dashed->setCheckable(true);
        radioButton_dashed->setChecked(false);
        radioButton_dashed->setAutoExclusive(false);

        gridLayout->addWidget(radioButton_dashed, 6, 1, 1, 1);

        radioButton_vertex_nope = new QRadioButton(options);
        buttonGroup_2->addButton(radioButton_vertex_nope);
        radioButton_vertex_nope->setObjectName("radioButton_vertex_nope");

        gridLayout->addWidget(radioButton_vertex_nope, 12, 1, 1, 1);


        retranslateUi(options);

        QMetaObject::connectSlotsByName(options);
    } // setupUi

    void retranslateUi(QDialog *options)
    {
        options->setWindowTitle(QCoreApplication::translate("options", "Dialog", nullptr));
        button_apply->setText(QCoreApplication::translate("options", "Apply", nullptr));
        label_4->setText(QCoreApplication::translate("options", "Vertexes:", nullptr));
        label_5->setText(QCoreApplication::translate("options", "Type ", nullptr));
        label_6->setText(QCoreApplication::translate("options", "Color", nullptr));
        radioButton_vertex_cube->setText(QCoreApplication::translate("options", "Cube", nullptr));
        label_projection->setText(QCoreApplication::translate("options", "Projection:", nullptr));
        label->setText(QCoreApplication::translate("options", "Type line", nullptr));
        radioButton_parallel->setText(QCoreApplication::translate("options", "parallel", nullptr));
        button_cancel->setText(QCoreApplication::translate("options", "Can\321\201el", nullptr));
        label_3->setText(QCoreApplication::translate("options", "Width", nullptr));
        radioButton_central->setText(QCoreApplication::translate("options", "central", nullptr));
        radioButton_vertex_shere->setText(QCoreApplication::translate("options", "Sphere", nullptr));
        button_color_edges->setText(QCoreApplication::translate("options", "...", nullptr));
        button_color_vertexes->setText(QCoreApplication::translate("options", "...", nullptr));
        label_7->setText(QCoreApplication::translate("options", "Size", nullptr));
        label_2->setText(QCoreApplication::translate("options", "Color", nullptr));
        button_background->setText(QCoreApplication::translate("options", "Background color", nullptr));
        radioButton_solid->setText(QCoreApplication::translate("options", "Solid", nullptr));
        label_edges->setText(QCoreApplication::translate("options", "Edges:", nullptr));
        radioButton_dashed->setText(QCoreApplication::translate("options", "Dashed", nullptr));
        radioButton_vertex_nope->setText(QCoreApplication::translate("options", "Nope", nullptr));
    } // retranslateUi

};

namespace Ui {
    class options: public Ui_options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
