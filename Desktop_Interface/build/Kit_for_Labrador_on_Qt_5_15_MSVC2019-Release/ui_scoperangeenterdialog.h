/********************************************************************************
** Form generated from reading UI file 'scoperangeenterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOPERANGEENTERDIALOG_H
#define UI_SCOPERANGEENTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <espospinbox.h>

QT_BEGIN_NAMESPACE

class Ui_scopeRangeEnterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    espoSpinBox *vMaxBox;
    QLabel *label;
    espoSpinBox *vMinBox;
    QLabel *label_2;
    espoSpinBox *timeWindowBox;
    QLabel *label_3;
    espoSpinBox *delayBox;
    QLabel *label_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *scopeRangeEnterDialog)
    {
        if (scopeRangeEnterDialog->objectName().isEmpty())
            scopeRangeEnterDialog->setObjectName(QString::fromUtf8("scopeRangeEnterDialog"));
        scopeRangeEnterDialog->resize(206, 170);
        verticalLayout_2 = new QVBoxLayout(scopeRangeEnterDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        vMaxBox = new espoSpinBox(scopeRangeEnterDialog);
        vMaxBox->setObjectName(QString::fromUtf8("vMaxBox"));
        vMaxBox->setMinimum(20.000000000000000);
        vMaxBox->setMaximum(20.000000000000000);

        gridLayout->addWidget(vMaxBox, 0, 0, 1, 1);

        label = new QLabel(scopeRangeEnterDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        vMinBox = new espoSpinBox(scopeRangeEnterDialog);
        vMinBox->setObjectName(QString::fromUtf8("vMinBox"));
        vMinBox->setMinimum(-20.000000000000000);
        vMinBox->setMaximum(-20.000000000000000);

        gridLayout->addWidget(vMinBox, 1, 0, 1, 1);

        label_2 = new QLabel(scopeRangeEnterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        timeWindowBox = new espoSpinBox(scopeRangeEnterDialog);
        timeWindowBox->setObjectName(QString::fromUtf8("timeWindowBox"));
        timeWindowBox->setDecimals(6);
        timeWindowBox->setMinimum(0.000001000000000);
        timeWindowBox->setMaximum(10.000000000000000);

        gridLayout->addWidget(timeWindowBox, 2, 0, 1, 1);

        label_3 = new QLabel(scopeRangeEnterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        delayBox = new espoSpinBox(scopeRangeEnterDialog);
        delayBox->setObjectName(QString::fromUtf8("delayBox"));
        delayBox->setDecimals(6);
        delayBox->setMinimum(0.000000000000000);
        delayBox->setMaximum(10.000000000000000);
        delayBox->setValue(0.000000000000000);

        gridLayout->addWidget(delayBox, 3, 0, 1, 1);

        label_4 = new QLabel(scopeRangeEnterDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(scopeRangeEnterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(scopeRangeEnterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), scopeRangeEnterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), scopeRangeEnterDialog, SLOT(reject()));
        QObject::connect(vMaxBox, SIGNAL(valueChanged(double)), scopeRangeEnterDialog, SLOT(toUpdateYTop(double)));
        QObject::connect(vMinBox, SIGNAL(valueChanged(double)), scopeRangeEnterDialog, SLOT(toUpdateYBot(double)));
        QObject::connect(vMaxBox, SIGNAL(valueChanged(double)), vMinBox, SLOT(setMax(double)));
        QObject::connect(vMinBox, SIGNAL(valueChanged(double)), vMaxBox, SLOT(setMin(double)));
        QObject::connect(timeWindowBox, SIGNAL(valueChanged(double)), scopeRangeEnterDialog, SLOT(toUpdateWindow(double)));
        QObject::connect(delayBox, SIGNAL(valueChanged(double)), scopeRangeEnterDialog, SLOT(toUpdateDelay(double)));

        QMetaObject::connectSlotsByName(scopeRangeEnterDialog);
    } // setupUi

    void retranslateUi(QDialog *scopeRangeEnterDialog)
    {
        scopeRangeEnterDialog->setWindowTitle(QCoreApplication::translate("scopeRangeEnterDialog", "Enter Scope Range", nullptr));
        vMaxBox->setSuffix(QCoreApplication::translate("scopeRangeEnterDialog", "V", nullptr));
        label->setText(QCoreApplication::translate("scopeRangeEnterDialog", "Vmax", nullptr));
        vMinBox->setSuffix(QCoreApplication::translate("scopeRangeEnterDialog", "V", nullptr));
        label_2->setText(QCoreApplication::translate("scopeRangeEnterDialog", "Vmin", nullptr));
        timeWindowBox->setSuffix(QCoreApplication::translate("scopeRangeEnterDialog", "s", nullptr));
        label_3->setText(QCoreApplication::translate("scopeRangeEnterDialog", "Time Window", nullptr));
        delayBox->setSuffix(QCoreApplication::translate("scopeRangeEnterDialog", "s", nullptr));
        label_4->setText(QCoreApplication::translate("scopeRangeEnterDialog", "Delay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scopeRangeEnterDialog: public Ui_scopeRangeEnterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOPERANGEENTERDIALOG_H
