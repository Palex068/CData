/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_xRot;
    QLineEdit *lineEdit_zRot;
    QLabel *label_2;
    QLineEdit *lineEdit_yRot;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(222, 119);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(130, 30, 81, 81));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 75, 16, 21));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 15, 16, 21));
        lineEdit_xRot = new QLineEdit(Dialog);
        lineEdit_xRot->setObjectName("lineEdit_xRot");
        lineEdit_xRot->setGeometry(QRect(60, 10, 61, 21));
        lineEdit_zRot = new QLineEdit(Dialog);
        lineEdit_zRot->setObjectName("lineEdit_zRot");
        lineEdit_zRot->setGeometry(QRect(60, 70, 61, 21));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 45, 16, 21));
        lineEdit_yRot = new QLineEdit(Dialog);
        lineEdit_yRot->setObjectName("lineEdit_yRot");
        lineEdit_yRot->setGeometry(QRect(60, 40, 61, 21));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 10, 71, 16));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Z", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "X", nullptr));
        lineEdit_xRot->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        lineEdit_zRot->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Y", nullptr));
        lineEdit_yRot->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\320\232\321\200\321\203\321\202\320\270\321\202\320\265\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
