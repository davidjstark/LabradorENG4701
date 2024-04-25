/********************************************************************************
** Form generated from reading UI file 'daqloadprompt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAQLOADPROMPT_H
#define UI_DAQLOADPROMPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_daqLoadPrompt
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *startTimeLabel;
    QDoubleSpinBox *startTimeDoubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *endTimeLabel;
    QDoubleSpinBox *endTimeDoubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *contigRamLabel;
    QLabel *contigRamLabel_Value;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *daqLoadPrompt)
    {
        if (daqLoadPrompt->objectName().isEmpty())
            daqLoadPrompt->setObjectName(QString::fromUtf8("daqLoadPrompt"));
        daqLoadPrompt->resize(320, 240);
        verticalLayout = new QVBoxLayout(daqLoadPrompt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startTimeLabel = new QLabel(daqLoadPrompt);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));

        horizontalLayout->addWidget(startTimeLabel);

        startTimeDoubleSpinBox = new QDoubleSpinBox(daqLoadPrompt);
        startTimeDoubleSpinBox->setObjectName(QString::fromUtf8("startTimeDoubleSpinBox"));
        startTimeDoubleSpinBox->setDecimals(6);

        horizontalLayout->addWidget(startTimeDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        endTimeLabel = new QLabel(daqLoadPrompt);
        endTimeLabel->setObjectName(QString::fromUtf8("endTimeLabel"));

        horizontalLayout_2->addWidget(endTimeLabel);

        endTimeDoubleSpinBox = new QDoubleSpinBox(daqLoadPrompt);
        endTimeDoubleSpinBox->setObjectName(QString::fromUtf8("endTimeDoubleSpinBox"));
        endTimeDoubleSpinBox->setDecimals(6);

        horizontalLayout_2->addWidget(endTimeDoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        contigRamLabel = new QLabel(daqLoadPrompt);
        contigRamLabel->setObjectName(QString::fromUtf8("contigRamLabel"));

        horizontalLayout_3->addWidget(contigRamLabel);

        contigRamLabel_Value = new QLabel(daqLoadPrompt);
        contigRamLabel_Value->setObjectName(QString::fromUtf8("contigRamLabel_Value"));
        contigRamLabel_Value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(contigRamLabel_Value);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(daqLoadPrompt);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(daqLoadPrompt);
        QObject::connect(buttonBox, SIGNAL(accepted()), daqLoadPrompt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), daqLoadPrompt, SLOT(reject()));

        QMetaObject::connectSlotsByName(daqLoadPrompt);
    } // setupUi

    void retranslateUi(QDialog *daqLoadPrompt)
    {
        daqLoadPrompt->setWindowTitle(QCoreApplication::translate("daqLoadPrompt", "Load DAQ file", nullptr));
        startTimeLabel->setText(QCoreApplication::translate("daqLoadPrompt", "Start Time:", nullptr));
        endTimeLabel->setText(QCoreApplication::translate("daqLoadPrompt", "End Time:", nullptr));
        contigRamLabel->setText(QCoreApplication::translate("daqLoadPrompt", "Contiguous RAM required:", nullptr));
        contigRamLabel_Value->setText(QCoreApplication::translate("daqLoadPrompt", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class daqLoadPrompt: public Ui_daqLoadPrompt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAQLOADPROMPT_H
