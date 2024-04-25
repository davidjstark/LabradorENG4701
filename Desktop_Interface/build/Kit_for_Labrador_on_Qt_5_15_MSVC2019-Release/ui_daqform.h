/********************************************************************************
** Form generated from reading UI file 'daqform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAQFORM_H
#define UI_DAQFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_daqForm
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *sampleAveragingGroup;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *numberOfPointsLabel;
    QSpinBox *numberOfPointsSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sampleRateLabel;
    QLabel *sampleRateLabel_val;
    QHBoxLayout *horizontalLayout_4;
    QLabel *sampleRateLabel_Double;
    QLabel *sampleRateLabel_Double_val;
    QGroupBox *limitFileSizeGroupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *fileSizeLabel;
    QSpinBox *fileSizeSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *numSamplesStoredLabel;
    QLabel *numSamplesStoredLabel_Value;
    QPushButton *saveAsDefaultsButton;

    void setupUi(QWidget *daqForm)
    {
        if (daqForm->objectName().isEmpty())
            daqForm->setObjectName(QString::fromUtf8("daqForm"));
        daqForm->resize(480, 320);
        verticalLayout = new QVBoxLayout(daqForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sampleAveragingGroup = new QGroupBox(daqForm);
        sampleAveragingGroup->setObjectName(QString::fromUtf8("sampleAveragingGroup"));
        sampleAveragingGroup->setCheckable(true);
        sampleAveragingGroup->setChecked(false);
        verticalLayout_2 = new QVBoxLayout(sampleAveragingGroup);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        numberOfPointsLabel = new QLabel(sampleAveragingGroup);
        numberOfPointsLabel->setObjectName(QString::fromUtf8("numberOfPointsLabel"));

        horizontalLayout_3->addWidget(numberOfPointsLabel);

        numberOfPointsSpinBox = new QSpinBox(sampleAveragingGroup);
        numberOfPointsSpinBox->setObjectName(QString::fromUtf8("numberOfPointsSpinBox"));
        numberOfPointsSpinBox->setMinimum(2);
        numberOfPointsSpinBox->setMaximum(750000000);

        horizontalLayout_3->addWidget(numberOfPointsSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sampleRateLabel = new QLabel(sampleAveragingGroup);
        sampleRateLabel->setObjectName(QString::fromUtf8("sampleRateLabel"));

        horizontalLayout_2->addWidget(sampleRateLabel);

        sampleRateLabel_val = new QLabel(sampleAveragingGroup);
        sampleRateLabel_val->setObjectName(QString::fromUtf8("sampleRateLabel_val"));
        sampleRateLabel_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(sampleRateLabel_val);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sampleRateLabel_Double = new QLabel(sampleAveragingGroup);
        sampleRateLabel_Double->setObjectName(QString::fromUtf8("sampleRateLabel_Double"));

        horizontalLayout_4->addWidget(sampleRateLabel_Double);

        sampleRateLabel_Double_val = new QLabel(sampleAveragingGroup);
        sampleRateLabel_Double_val->setObjectName(QString::fromUtf8("sampleRateLabel_Double_val"));
        sampleRateLabel_Double_val->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(sampleRateLabel_Double_val);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(sampleAveragingGroup);

        limitFileSizeGroupBox = new QGroupBox(daqForm);
        limitFileSizeGroupBox->setObjectName(QString::fromUtf8("limitFileSizeGroupBox"));
        limitFileSizeGroupBox->setCheckable(true);
        verticalLayout_3 = new QVBoxLayout(limitFileSizeGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fileSizeLabel = new QLabel(limitFileSizeGroupBox);
        fileSizeLabel->setObjectName(QString::fromUtf8("fileSizeLabel"));

        horizontalLayout->addWidget(fileSizeLabel);

        fileSizeSpinBox = new QSpinBox(limitFileSizeGroupBox);
        fileSizeSpinBox->setObjectName(QString::fromUtf8("fileSizeSpinBox"));
        fileSizeSpinBox->setMinimum(1);
        fileSizeSpinBox->setMaximum(1024000000);
        fileSizeSpinBox->setValue(1024);

        horizontalLayout->addWidget(fileSizeSpinBox);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        numSamplesStoredLabel = new QLabel(limitFileSizeGroupBox);
        numSamplesStoredLabel->setObjectName(QString::fromUtf8("numSamplesStoredLabel"));

        horizontalLayout_5->addWidget(numSamplesStoredLabel);

        numSamplesStoredLabel_Value = new QLabel(limitFileSizeGroupBox);
        numSamplesStoredLabel_Value->setObjectName(QString::fromUtf8("numSamplesStoredLabel_Value"));
        numSamplesStoredLabel_Value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(numSamplesStoredLabel_Value);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout->addWidget(limitFileSizeGroupBox);

        saveAsDefaultsButton = new QPushButton(daqForm);
        saveAsDefaultsButton->setObjectName(QString::fromUtf8("saveAsDefaultsButton"));

        verticalLayout->addWidget(saveAsDefaultsButton);


        retranslateUi(daqForm);

        QMetaObject::connectSlotsByName(daqForm);
    } // setupUi

    void retranslateUi(QWidget *daqForm)
    {
        daqForm->setWindowTitle(QCoreApplication::translate("daqForm", "DAQ Settings", nullptr));
        sampleAveragingGroup->setTitle(QCoreApplication::translate("daqForm", "Sample Averaging", nullptr));
#if QT_CONFIG(tooltip)
        numberOfPointsLabel->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        numberOfPointsLabel->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(whatsthis)
        numberOfPointsLabel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        numberOfPointsLabel->setText(QCoreApplication::translate("daqForm", "Number of Points", nullptr));
        sampleRateLabel->setText(QCoreApplication::translate("daqForm", "Effective Sample Rate (Standard Mode)", nullptr));
        sampleRateLabel_val->setText(QCoreApplication::translate("daqForm", "TextLabel", nullptr));
        sampleRateLabel_Double->setText(QCoreApplication::translate("daqForm", "Effective Sample Rate (Double Sample Rate)", nullptr));
        sampleRateLabel_Double_val->setText(QCoreApplication::translate("daqForm", "TextLabel", nullptr));
        limitFileSizeGroupBox->setTitle(QCoreApplication::translate("daqForm", "Limit File Size", nullptr));
        fileSizeLabel->setText(QCoreApplication::translate("daqForm", "Maximum File Size (MB)", nullptr));
        numSamplesStoredLabel->setText(QCoreApplication::translate("daqForm", "Number of Samples Stored", nullptr));
        numSamplesStoredLabel_Value->setText(QCoreApplication::translate("daqForm", "TextLabel", nullptr));
        saveAsDefaultsButton->setText(QCoreApplication::translate("daqForm", "Save As Defaults", nullptr));
    } // retranslateUi

};

namespace Ui {
    class daqForm: public Ui_daqForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAQFORM_H
