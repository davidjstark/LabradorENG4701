/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <buffercontrol.h>
#include <cursorenabler.h>
#include <deviceconnecteddisplay.h>
#include <espocombobox.h>
#include <esposlider.h>
#include <espospinbox.h>
#include <functiongencontrol.h>
#include <isodriver.h>
#include <noclosemenu.h>
#include <timedtickbox.h>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGainAuto;
    QAction *actionGain0_5;
    QAction *actionGain1;
    QAction *actionGain2;
    QAction *actionGain4;
    QAction *actionGain8;
    QAction *actionGain16;
    QAction *actionGain32;
    QAction *actionGain64;
    QAction *actionCalibrate;
    QAction *actionCursor_Stats;
    QAction *actionMax;
    QAction *actionMin;
    QAction *actionMean;
    QAction *actionRMS;
    QAction *actionMax_2;
    QAction *actionMin_2;
    QAction *actionMean_2;
    QAction *actionRMS_2;
    QAction *actionMV;
    QAction *actionV;
    QAction *actionAutoV;
    QAction *actionAutoI;
    QAction *actionMA;
    QAction *actionA;
    QAction *action300;
    QAction *action600;
    QAction *action1200;
    QAction *action2400;
    QAction *action4800;
    QAction *action9600;
    QAction *action14400;
    QAction *action19200;
    QAction *action28800;
    QAction *action38400;
    QAction *action57600;
    QAction *action115200;
    QAction *action8;
    QAction *actionNone;
    QAction *action300_2;
    QAction *action600_2;
    QAction *action1200_2;
    QAction *action2400_2;
    QAction *action4800_2;
    QAction *action9600_2;
    QAction *action14400_2;
    QAction *action19200_2;
    QAction *action28800_2;
    QAction *action38400_2;
    QAction *action57600_2;
    QAction *action115200_2;
    QAction *action8_2;
    QAction *actionNone_2;
    QAction *actionForce_Square;
    QAction *actionAutomatically_Enable_Cursors;
    QAction *action60FPS;
    QAction *action30FPS;
    QAction *action20FPS;
    QAction *action15FPS;
    QAction *action10FPS;
    QAction *action5FPS;
    QAction *actionAuto_Lock;
    QAction *actionSnap_to_Cursors;
    QAction *actionEnter_Manually;
    QAction *actionAutoR;
    QAction *actionOhm;
    QAction *actionKOhm;
    QAction *actionAutoC;
    QAction *actionNF;
    QAction *action_F;
    QAction *actionLo_bw;
    QAction *actionSingle_ep_msync;
    QAction *actionSingle_ep_async;
    QAction *actionExportImage;
    QAction *actionSnapshot_CH1;
    QAction *actionSnapshot_CH2;
    QAction *actionRecord_CH1;
    QAction *actionRecord_CH2;
    QAction *actionFirmware_Recovery;
    QAction *actionShow_Debug_Console;
    QAction *actionDAQ_Settings;
    QAction *actionAbout;
    QAction *actionOpen_DAQ_File;
    QAction *actionQuit;
    QAction *actionCalibrate_2;
    QAction *actionOffset_is_A0_from_Fourier_Series;
    QAction *actionFrom_GND;
    QAction *actionMean_Point_from_GND;
    QAction *actionSerial;
    QAction *actionI2C;
    QAction *actionShow_Range_Dialog_on_Main_Page;
    QAction *actionEven;
    QAction *actionOdd;
    QAction *actionEven_2;
    QAction *actionOdd_2;
    QAction *actionPinout;
    QAction *actionDocumentation;
    QAction *actionHexDisplay;
    QAction *actionHexDisplay_2;
    QAction *actionHide_Widget_Oscilloscope;
    QAction *actionHide_Widget_SignalGen;
    QAction *actionHide_Widget_Multimeter;
    QAction *actionHide_Widget_PowerSupply;
    QAction *actionHide_Widget_LogicAnalyzer;
    QAction *actionDark_Mode;
    QAction *actionFrequency_Spectrum;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCustomPlot *scopeAxes;
    QPushButton *realTimeButton;
    QLabel *cursorStatsLabel;
    functionGenControl *controller_fg;
    QTextEdit *debugConsole;
    QSlider *timeBaseSlider;
    QPlainTextEdit *console1;
    QPlainTextEdit *console2;
    QVBoxLayout *verticalLayout_5;
    deviceConnectedDisplay *deviceConnected;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *scopeGroup_CH1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_20;
    QCheckBox *pausedLabeL_CH1;
    QCheckBox *acCoupledLabel_CH1;
    QCheckBox *filterLabel_CH1;
    QCheckBox *doubleSampleLabel;
    QCheckBox *hideCH1Box;
    QVBoxLayout *verticalLayout_22;
    QLabel *label;
    espoSpinBox *offsetSpinBox_CH1;
    QLabel *label_2;
    QComboBox *attenuationComboBox_CH1;
    QGridLayout *gridLayout_2;
    QLabel *voltageInfoMaxLabel_CH1;
    QLCDNumber *voltageInfoMaxDisplay_CH1;
    QLabel *voltageInfoMinLabel_CH1;
    QLCDNumber *voltageInfoMinDisplay_CH1;
    QLabel *VoltageInfoMeanLabel_CH1;
    QLabel *voltageInfoRmsLabel_CH1;
    QLCDNumber *voltageInfoRmsDisplay_CH1;
    QLCDNumber *voltageInfoMeanDisplay_CH1;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *scopeGroup_CH2;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_23;
    QCheckBox *pausedLabel_CH2;
    QCheckBox *acCoupledLabel_CH2;
    QCheckBox *filterLabel_CH2;
    QCheckBox *xyDisplayLabel;
    QCheckBox *hideCH2Box;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_3;
    espoSpinBox *offsetSpinBox_CH2;
    QLabel *label_4;
    QComboBox *attenuationComboBox_CH2;
    QGridLayout *gridLayout_3;
    QLabel *voltageInfoMaxLabel_CH2;
    QLCDNumber *voltageInfoMaxDisplay_CH2;
    QLabel *voltageInfoMinLabel_CH2;
    QLCDNumber *voltageInfoMinDisplay_CH2;
    QLabel *VoltageInfoMeanLabel_CH2;
    QLabel *voltageInfoRmsLabel_CH2;
    QLCDNumber *voltageInfoRmsDisplay_CH2;
    QLCDNumber *voltageInfoMeanDisplay_CH2;
    QVBoxLayout *verticalLayout_25;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *cursorGroup;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *cursorHoriCheck;
    QCheckBox *cursorVertCheck;
    cursorEnabler *makeCursorsNicer;
    QGroupBox *triggerGroup;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_27;
    QLabel *label_5;
    QComboBox *triggerChannelSelect;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_6;
    QDoubleSpinBox *triggerLevelValue;
    QCheckBox *singleShotCheckBox;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *multimeterGroup;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_28;
    QCheckBox *multimeterPauseCheckBox;
    QLabel *multimeterModeLabel;
    QComboBox *multimeterModeSelect;
    QLabel *multimeterResistanceLabel;
    espoSpinBox *multimeterResistanceSelect;
    QLabel *multimeterRLabel;
    QComboBox *multimeterRComboBox;
    QGridLayout *gridLayout;
    QLabel *multimeterMinLabel;
    QLCDNumber *multimeterMaxDisplay;
    QLabel *multimeterMaxLabel;
    QLabel *multimeterMeanLabel;
    QLabel *multimeterRmsLabel;
    QLCDNumber *multimeterMinDisplay;
    QLCDNumber *multimeterMeanDisplay;
    QLCDNumber *multimeterRmsDisplay;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *signalGenGroup_CH1;
    QVBoxLayout *verticalLayout_19;
    QGridLayout *gridLayout_5;
    QLabel *frequencyLabel_CH1;
    espoSpinBox *amplitudeValue_CH1;
    espoSpinBox *frequencyValue_CH1;
    QLabel *amplitudeLabel_CH1;
    espoComboBox *waveformSelect_CH1;
    QLabel *waveformLabel_CH1;
    QLabel *dcOffsetLabel_CH1;
    espoSpinBox *dcOffsetValue_CH1;
    QGroupBox *signalGenGroup_CH2;
    QVBoxLayout *verticalLayout_21;
    QGridLayout *gridLayout_6;
    espoSpinBox *frequencyValue_CH2;
    QLabel *amplitudeLabel_CH2;
    QLabel *waveformLabel_CH2;
    QLabel *frequencyLabel_CH2;
    QLabel *dcOffsetLabel_CH2;
    espoSpinBox *amplitudeValue_CH2;
    espoComboBox *waveformSelect_CH2;
    espoSpinBox *dcOffsetValue_CH2;
    QSpacerItem *verticalSpacer_4;
    isoDriver *controller_iso;
    QVBoxLayout *verticalLayout_18;
    QGroupBox *psuGroup;
    QVBoxLayout *verticalLayout_15;
    espoSlider *psuSlider;
    timedTickBox *lockPsuCheckBox;
    QLCDNumber *psuDisplay;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *busSifferGroup_CH1;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *pause_LA;
    QGroupBox *serialDecodingCheck_CH1;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *busSnifferGroup_CH2;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *serialDecodingCheck_CH2;
    QVBoxLayout *verticalLayout_17;
    QGroupBox *digitalOutputGroup;
    QGridLayout *gridLayout_4;
    QCheckBox *digitalOutCheckbox_CH3;
    QCheckBox *digitalOutCheckbox_CH2;
    QCheckBox *digitalOutCheckbox_CH1;
    QCheckBox *digitalOutCheckbox_CH4;
    QPushButton *debugButton1;
    QPushButton *debugButton2;
    QPushButton *kickstartIsoButton;
    QPushButton *debugButton3;
    bufferControl *bufferDisplay;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTake_Snapshot;
    QMenu *menuRecord;
    QMenu *menuOscilloscope_2;
    QMenu *menuGain_2;
    noCloseMenu *menuCH1_Stats;
    noCloseMenu *menuCH2_Stats;
    QMenu *menuFrame_rate;
    QMenu *menuRange;
    QMenu *menuMultimeter_2;
    QMenu *menuV_2;
    QMenu *menuI_2;
    QMenu *menuRange_R;
    QMenu *menuRange_C;
    QMenu *menuBus_Sniffer;
    QMenu *menuUART_1;
    QMenu *menuBaud_Rate;
    QMenu *menuParity_Bit;
    QMenu *menuData_Bits;
    QMenu *menuUART_2;
    QMenu *menuBaud_Rate_2;
    QMenu *menuData_Bits_2;
    QMenu *menuParity_Bit_2;
    QMenu *menuProtocol;
    QMenu *menuPower_Supply;
    QMenu *menuConnection_Type;
    QMenu *menuHelp;
    QMenu *menuSignal_Generator;
    QMenu *menuOffset_Type;
    QMenu *menuAccessibility;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1493, 1346);
        MainWindow->setMinimumSize(QSize(800, 600));
        actionGainAuto = new QAction(MainWindow);
        actionGainAuto->setObjectName(QString::fromUtf8("actionGainAuto"));
        actionGainAuto->setCheckable(true);
        actionGain0_5 = new QAction(MainWindow);
        actionGain0_5->setObjectName(QString::fromUtf8("actionGain0_5"));
        actionGain0_5->setCheckable(true);
        actionGain1 = new QAction(MainWindow);
        actionGain1->setObjectName(QString::fromUtf8("actionGain1"));
        actionGain1->setCheckable(true);
        actionGain2 = new QAction(MainWindow);
        actionGain2->setObjectName(QString::fromUtf8("actionGain2"));
        actionGain2->setCheckable(true);
        actionGain4 = new QAction(MainWindow);
        actionGain4->setObjectName(QString::fromUtf8("actionGain4"));
        actionGain4->setCheckable(true);
        actionGain8 = new QAction(MainWindow);
        actionGain8->setObjectName(QString::fromUtf8("actionGain8"));
        actionGain8->setCheckable(true);
        actionGain16 = new QAction(MainWindow);
        actionGain16->setObjectName(QString::fromUtf8("actionGain16"));
        actionGain16->setCheckable(true);
        actionGain32 = new QAction(MainWindow);
        actionGain32->setObjectName(QString::fromUtf8("actionGain32"));
        actionGain32->setCheckable(true);
        actionGain64 = new QAction(MainWindow);
        actionGain64->setObjectName(QString::fromUtf8("actionGain64"));
        actionGain64->setCheckable(true);
        actionGain64->setMenuRole(QAction::TextHeuristicRole);
        actionCalibrate = new QAction(MainWindow);
        actionCalibrate->setObjectName(QString::fromUtf8("actionCalibrate"));
        actionCursor_Stats = new QAction(MainWindow);
        actionCursor_Stats->setObjectName(QString::fromUtf8("actionCursor_Stats"));
        actionCursor_Stats->setCheckable(true);
        actionCursor_Stats->setChecked(true);
        actionMax = new QAction(MainWindow);
        actionMax->setObjectName(QString::fromUtf8("actionMax"));
        actionMax->setCheckable(true);
        actionMin = new QAction(MainWindow);
        actionMin->setObjectName(QString::fromUtf8("actionMin"));
        actionMin->setCheckable(true);
        actionMean = new QAction(MainWindow);
        actionMean->setObjectName(QString::fromUtf8("actionMean"));
        actionMean->setCheckable(true);
        actionRMS = new QAction(MainWindow);
        actionRMS->setObjectName(QString::fromUtf8("actionRMS"));
        actionRMS->setCheckable(true);
        actionMax_2 = new QAction(MainWindow);
        actionMax_2->setObjectName(QString::fromUtf8("actionMax_2"));
        actionMax_2->setCheckable(true);
        actionMin_2 = new QAction(MainWindow);
        actionMin_2->setObjectName(QString::fromUtf8("actionMin_2"));
        actionMin_2->setCheckable(true);
        actionMean_2 = new QAction(MainWindow);
        actionMean_2->setObjectName(QString::fromUtf8("actionMean_2"));
        actionMean_2->setCheckable(true);
        actionRMS_2 = new QAction(MainWindow);
        actionRMS_2->setObjectName(QString::fromUtf8("actionRMS_2"));
        actionRMS_2->setCheckable(true);
        actionMV = new QAction(MainWindow);
        actionMV->setObjectName(QString::fromUtf8("actionMV"));
        actionMV->setCheckable(true);
        actionMV->setChecked(false);
        actionV = new QAction(MainWindow);
        actionV->setObjectName(QString::fromUtf8("actionV"));
        actionV->setCheckable(true);
        actionV->setChecked(false);
        actionAutoV = new QAction(MainWindow);
        actionAutoV->setObjectName(QString::fromUtf8("actionAutoV"));
        actionAutoV->setCheckable(true);
        actionAutoV->setChecked(true);
        actionAutoI = new QAction(MainWindow);
        actionAutoI->setObjectName(QString::fromUtf8("actionAutoI"));
        actionAutoI->setCheckable(true);
        actionAutoI->setChecked(true);
        actionMA = new QAction(MainWindow);
        actionMA->setObjectName(QString::fromUtf8("actionMA"));
        actionMA->setCheckable(true);
        actionMA->setChecked(false);
        actionA = new QAction(MainWindow);
        actionA->setObjectName(QString::fromUtf8("actionA"));
        actionA->setCheckable(true);
        action300 = new QAction(MainWindow);
        action300->setObjectName(QString::fromUtf8("action300"));
        action300->setCheckable(true);
        action600 = new QAction(MainWindow);
        action600->setObjectName(QString::fromUtf8("action600"));
        action600->setCheckable(true);
        action1200 = new QAction(MainWindow);
        action1200->setObjectName(QString::fromUtf8("action1200"));
        action1200->setCheckable(true);
        action2400 = new QAction(MainWindow);
        action2400->setObjectName(QString::fromUtf8("action2400"));
        action2400->setCheckable(true);
        action4800 = new QAction(MainWindow);
        action4800->setObjectName(QString::fromUtf8("action4800"));
        action4800->setCheckable(true);
        action9600 = new QAction(MainWindow);
        action9600->setObjectName(QString::fromUtf8("action9600"));
        action9600->setCheckable(true);
        action14400 = new QAction(MainWindow);
        action14400->setObjectName(QString::fromUtf8("action14400"));
        action14400->setCheckable(true);
        action19200 = new QAction(MainWindow);
        action19200->setObjectName(QString::fromUtf8("action19200"));
        action19200->setCheckable(true);
        action28800 = new QAction(MainWindow);
        action28800->setObjectName(QString::fromUtf8("action28800"));
        action28800->setCheckable(true);
        action38400 = new QAction(MainWindow);
        action38400->setObjectName(QString::fromUtf8("action38400"));
        action38400->setCheckable(true);
        action57600 = new QAction(MainWindow);
        action57600->setObjectName(QString::fromUtf8("action57600"));
        action57600->setCheckable(true);
        action115200 = new QAction(MainWindow);
        action115200->setObjectName(QString::fromUtf8("action115200"));
        action115200->setCheckable(true);
        action8 = new QAction(MainWindow);
        action8->setObjectName(QString::fromUtf8("action8"));
        action8->setCheckable(true);
        actionNone = new QAction(MainWindow);
        actionNone->setObjectName(QString::fromUtf8("actionNone"));
        actionNone->setCheckable(true);
        actionNone->setChecked(true);
        action300_2 = new QAction(MainWindow);
        action300_2->setObjectName(QString::fromUtf8("action300_2"));
        action300_2->setCheckable(true);
        action600_2 = new QAction(MainWindow);
        action600_2->setObjectName(QString::fromUtf8("action600_2"));
        action600_2->setCheckable(true);
        action1200_2 = new QAction(MainWindow);
        action1200_2->setObjectName(QString::fromUtf8("action1200_2"));
        action1200_2->setCheckable(true);
        action2400_2 = new QAction(MainWindow);
        action2400_2->setObjectName(QString::fromUtf8("action2400_2"));
        action2400_2->setCheckable(true);
        action4800_2 = new QAction(MainWindow);
        action4800_2->setObjectName(QString::fromUtf8("action4800_2"));
        action4800_2->setCheckable(true);
        action9600_2 = new QAction(MainWindow);
        action9600_2->setObjectName(QString::fromUtf8("action9600_2"));
        action9600_2->setCheckable(true);
        action14400_2 = new QAction(MainWindow);
        action14400_2->setObjectName(QString::fromUtf8("action14400_2"));
        action14400_2->setCheckable(true);
        action19200_2 = new QAction(MainWindow);
        action19200_2->setObjectName(QString::fromUtf8("action19200_2"));
        action19200_2->setCheckable(true);
        action28800_2 = new QAction(MainWindow);
        action28800_2->setObjectName(QString::fromUtf8("action28800_2"));
        action28800_2->setCheckable(true);
        action38400_2 = new QAction(MainWindow);
        action38400_2->setObjectName(QString::fromUtf8("action38400_2"));
        action38400_2->setCheckable(true);
        action57600_2 = new QAction(MainWindow);
        action57600_2->setObjectName(QString::fromUtf8("action57600_2"));
        action57600_2->setCheckable(true);
        action115200_2 = new QAction(MainWindow);
        action115200_2->setObjectName(QString::fromUtf8("action115200_2"));
        action115200_2->setCheckable(true);
        action8_2 = new QAction(MainWindow);
        action8_2->setObjectName(QString::fromUtf8("action8_2"));
        action8_2->setCheckable(true);
        actionNone_2 = new QAction(MainWindow);
        actionNone_2->setObjectName(QString::fromUtf8("actionNone_2"));
        actionNone_2->setCheckable(true);
        actionForce_Square = new QAction(MainWindow);
        actionForce_Square->setObjectName(QString::fromUtf8("actionForce_Square"));
        actionForce_Square->setCheckable(true);
        actionAutomatically_Enable_Cursors = new QAction(MainWindow);
        actionAutomatically_Enable_Cursors->setObjectName(QString::fromUtf8("actionAutomatically_Enable_Cursors"));
        actionAutomatically_Enable_Cursors->setCheckable(true);
        actionAutomatically_Enable_Cursors->setChecked(true);
        action60FPS = new QAction(MainWindow);
        action60FPS->setObjectName(QString::fromUtf8("action60FPS"));
        action60FPS->setCheckable(true);
        action60FPS->setChecked(true);
        action30FPS = new QAction(MainWindow);
        action30FPS->setObjectName(QString::fromUtf8("action30FPS"));
        action30FPS->setCheckable(true);
        action20FPS = new QAction(MainWindow);
        action20FPS->setObjectName(QString::fromUtf8("action20FPS"));
        action20FPS->setCheckable(true);
        action15FPS = new QAction(MainWindow);
        action15FPS->setObjectName(QString::fromUtf8("action15FPS"));
        action15FPS->setCheckable(true);
        action10FPS = new QAction(MainWindow);
        action10FPS->setObjectName(QString::fromUtf8("action10FPS"));
        action10FPS->setCheckable(true);
        action5FPS = new QAction(MainWindow);
        action5FPS->setObjectName(QString::fromUtf8("action5FPS"));
        action5FPS->setCheckable(true);
        actionAuto_Lock = new QAction(MainWindow);
        actionAuto_Lock->setObjectName(QString::fromUtf8("actionAuto_Lock"));
        actionAuto_Lock->setCheckable(true);
        actionAuto_Lock->setChecked(true);
        actionSnap_to_Cursors = new QAction(MainWindow);
        actionSnap_to_Cursors->setObjectName(QString::fromUtf8("actionSnap_to_Cursors"));
        actionEnter_Manually = new QAction(MainWindow);
        actionEnter_Manually->setObjectName(QString::fromUtf8("actionEnter_Manually"));
        actionAutoR = new QAction(MainWindow);
        actionAutoR->setObjectName(QString::fromUtf8("actionAutoR"));
        actionAutoR->setCheckable(true);
        actionAutoR->setChecked(true);
        actionOhm = new QAction(MainWindow);
        actionOhm->setObjectName(QString::fromUtf8("actionOhm"));
        actionOhm->setCheckable(true);
        actionKOhm = new QAction(MainWindow);
        actionKOhm->setObjectName(QString::fromUtf8("actionKOhm"));
        actionKOhm->setCheckable(true);
        actionAutoC = new QAction(MainWindow);
        actionAutoC->setObjectName(QString::fromUtf8("actionAutoC"));
        actionAutoC->setCheckable(true);
        actionAutoC->setChecked(true);
        actionNF = new QAction(MainWindow);
        actionNF->setObjectName(QString::fromUtf8("actionNF"));
        actionNF->setCheckable(true);
        action_F = new QAction(MainWindow);
        action_F->setObjectName(QString::fromUtf8("action_F"));
        action_F->setCheckable(true);
        actionLo_bw = new QAction(MainWindow);
        actionLo_bw->setObjectName(QString::fromUtf8("actionLo_bw"));
        actionLo_bw->setCheckable(true);
        actionLo_bw->setChecked(true);
        actionSingle_ep_msync = new QAction(MainWindow);
        actionSingle_ep_msync->setObjectName(QString::fromUtf8("actionSingle_ep_msync"));
        actionSingle_ep_msync->setCheckable(true);
        actionSingle_ep_async = new QAction(MainWindow);
        actionSingle_ep_async->setObjectName(QString::fromUtf8("actionSingle_ep_async"));
        actionSingle_ep_async->setCheckable(true);
        actionExportImage = new QAction(MainWindow);
        actionExportImage->setObjectName(QString::fromUtf8("actionExportImage"));
        actionSnapshot_CH1 = new QAction(MainWindow);
        actionSnapshot_CH1->setObjectName(QString::fromUtf8("actionSnapshot_CH1"));
        actionSnapshot_CH2 = new QAction(MainWindow);
        actionSnapshot_CH2->setObjectName(QString::fromUtf8("actionSnapshot_CH2"));
        actionRecord_CH1 = new QAction(MainWindow);
        actionRecord_CH1->setObjectName(QString::fromUtf8("actionRecord_CH1"));
        actionRecord_CH1->setCheckable(true);
        actionRecord_CH2 = new QAction(MainWindow);
        actionRecord_CH2->setObjectName(QString::fromUtf8("actionRecord_CH2"));
        actionRecord_CH2->setCheckable(true);
        actionFirmware_Recovery = new QAction(MainWindow);
        actionFirmware_Recovery->setObjectName(QString::fromUtf8("actionFirmware_Recovery"));
        actionShow_Debug_Console = new QAction(MainWindow);
        actionShow_Debug_Console->setObjectName(QString::fromUtf8("actionShow_Debug_Console"));
        actionShow_Debug_Console->setCheckable(true);
        actionDAQ_Settings = new QAction(MainWindow);
        actionDAQ_Settings->setObjectName(QString::fromUtf8("actionDAQ_Settings"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionOpen_DAQ_File = new QAction(MainWindow);
        actionOpen_DAQ_File->setObjectName(QString::fromUtf8("actionOpen_DAQ_File"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionCalibrate_2 = new QAction(MainWindow);
        actionCalibrate_2->setObjectName(QString::fromUtf8("actionCalibrate_2"));
        actionOffset_is_A0_from_Fourier_Series = new QAction(MainWindow);
        actionOffset_is_A0_from_Fourier_Series->setObjectName(QString::fromUtf8("actionOffset_is_A0_from_Fourier_Series"));
        actionFrom_GND = new QAction(MainWindow);
        actionFrom_GND->setObjectName(QString::fromUtf8("actionFrom_GND"));
        actionMean_Point_from_GND = new QAction(MainWindow);
        actionMean_Point_from_GND->setObjectName(QString::fromUtf8("actionMean_Point_from_GND"));
        actionSerial = new QAction(MainWindow);
        actionSerial->setObjectName(QString::fromUtf8("actionSerial"));
        actionSerial->setCheckable(true);
        actionSerial->setChecked(true);
        actionI2C = new QAction(MainWindow);
        actionI2C->setObjectName(QString::fromUtf8("actionI2C"));
        actionI2C->setCheckable(true);
        actionShow_Range_Dialog_on_Main_Page = new QAction(MainWindow);
        actionShow_Range_Dialog_on_Main_Page->setObjectName(QString::fromUtf8("actionShow_Range_Dialog_on_Main_Page"));
        actionShow_Range_Dialog_on_Main_Page->setCheckable(true);
        actionEven = new QAction(MainWindow);
        actionEven->setObjectName(QString::fromUtf8("actionEven"));
        actionEven->setCheckable(true);
        actionOdd = new QAction(MainWindow);
        actionOdd->setObjectName(QString::fromUtf8("actionOdd"));
        actionOdd->setCheckable(true);
        actionEven_2 = new QAction(MainWindow);
        actionEven_2->setObjectName(QString::fromUtf8("actionEven_2"));
        actionEven_2->setCheckable(true);
        actionOdd_2 = new QAction(MainWindow);
        actionOdd_2->setObjectName(QString::fromUtf8("actionOdd_2"));
        actionOdd_2->setCheckable(true);
        actionPinout = new QAction(MainWindow);
        actionPinout->setObjectName(QString::fromUtf8("actionPinout"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QString::fromUtf8("actionDocumentation"));
        actionHexDisplay = new QAction(MainWindow);
        actionHexDisplay->setObjectName(QString::fromUtf8("actionHexDisplay"));
        actionHexDisplay->setCheckable(true);
        actionHexDisplay_2 = new QAction(MainWindow);
        actionHexDisplay_2->setObjectName(QString::fromUtf8("actionHexDisplay_2"));
        actionHexDisplay_2->setCheckable(true);
        actionHide_Widget_Oscilloscope = new QAction(MainWindow);
        actionHide_Widget_Oscilloscope->setObjectName(QString::fromUtf8("actionHide_Widget_Oscilloscope"));
        actionHide_Widget_Oscilloscope->setCheckable(true);
        actionHide_Widget_SignalGen = new QAction(MainWindow);
        actionHide_Widget_SignalGen->setObjectName(QString::fromUtf8("actionHide_Widget_SignalGen"));
        actionHide_Widget_SignalGen->setCheckable(true);
        actionHide_Widget_Multimeter = new QAction(MainWindow);
        actionHide_Widget_Multimeter->setObjectName(QString::fromUtf8("actionHide_Widget_Multimeter"));
        actionHide_Widget_Multimeter->setCheckable(true);
        actionHide_Widget_PowerSupply = new QAction(MainWindow);
        actionHide_Widget_PowerSupply->setObjectName(QString::fromUtf8("actionHide_Widget_PowerSupply"));
        actionHide_Widget_PowerSupply->setCheckable(true);
        actionHide_Widget_LogicAnalyzer = new QAction(MainWindow);
        actionHide_Widget_LogicAnalyzer->setObjectName(QString::fromUtf8("actionHide_Widget_LogicAnalyzer"));
        actionHide_Widget_LogicAnalyzer->setCheckable(true);
        actionDark_Mode = new QAction(MainWindow);
        actionDark_Mode->setObjectName(QString::fromUtf8("actionDark_Mode"));
        actionDark_Mode->setCheckable(true);
        actionFrequency_Spectrum = new QAction(MainWindow);
        actionFrequency_Spectrum->setObjectName(QString::fromUtf8("actionFrequency_Spectrum"));
        actionFrequency_Spectrum->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        scopeAxes = new QCustomPlot(centralWidget);
        scopeAxes->setObjectName(QString::fromUtf8("scopeAxes"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scopeAxes->sizePolicy().hasHeightForWidth());
        scopeAxes->setSizePolicy(sizePolicy);
        scopeAxes->setMinimumSize(QSize(320, 240));
        scopeAxes->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(scopeAxes);

        realTimeButton = new QPushButton(centralWidget);
        realTimeButton->setObjectName(QString::fromUtf8("realTimeButton"));

        verticalLayout->addWidget(realTimeButton);

        cursorStatsLabel = new QLabel(centralWidget);
        cursorStatsLabel->setObjectName(QString::fromUtf8("cursorStatsLabel"));
        cursorStatsLabel->setMaximumSize(QSize(16777215, 48));
        cursorStatsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(cursorStatsLabel);

        controller_fg = new functionGenControl(centralWidget);
        controller_fg->setObjectName(QString::fromUtf8("controller_fg"));

        verticalLayout->addWidget(controller_fg);

        debugConsole = new QTextEdit(centralWidget);
        debugConsole->setObjectName(QString::fromUtf8("debugConsole"));

        verticalLayout->addWidget(debugConsole);

        timeBaseSlider = new QSlider(centralWidget);
        timeBaseSlider->setObjectName(QString::fromUtf8("timeBaseSlider"));
        timeBaseSlider->setMinimum(-60);
        timeBaseSlider->setMaximum(10);
        timeBaseSlider->setPageStep(10);
        timeBaseSlider->setValue(-20);
        timeBaseSlider->setSliderPosition(-20);
        timeBaseSlider->setTracking(true);
        timeBaseSlider->setOrientation(Qt::Horizontal);
        timeBaseSlider->setTickPosition(QSlider::TicksBelow);
        timeBaseSlider->setTickInterval(10);

        verticalLayout->addWidget(timeBaseSlider);

        console1 = new QPlainTextEdit(centralWidget);
        console1->setObjectName(QString::fromUtf8("console1"));
        console1->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(console1->sizePolicy().hasHeightForWidth());
        console1->setSizePolicy(sizePolicy1);
        console1->setMinimumSize(QSize(0, 0));
        console1->setMaximumSize(QSize(16777215, 16777215));
        console1->setReadOnly(true);

        verticalLayout->addWidget(console1);

        console2 = new QPlainTextEdit(centralWidget);
        console2->setObjectName(QString::fromUtf8("console2"));
        sizePolicy1.setHeightForWidth(console2->sizePolicy().hasHeightForWidth());
        console2->setSizePolicy(sizePolicy1);
        console2->setMaximumSize(QSize(16777215, 16777215));
        console2->setReadOnly(true);

        verticalLayout->addWidget(console2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        deviceConnected = new deviceConnectedDisplay(centralWidget);
        deviceConnected->setObjectName(QString::fromUtf8("deviceConnected"));
        deviceConnected->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(deviceConnected);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        scopeGroup_CH1 = new QGroupBox(centralWidget);
        scopeGroup_CH1->setObjectName(QString::fromUtf8("scopeGroup_CH1"));
        scopeGroup_CH1->setFlat(false);
        scopeGroup_CH1->setCheckable(true);
        scopeGroup_CH1->setChecked(true);
        verticalLayout_2 = new QVBoxLayout(scopeGroup_CH1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        pausedLabeL_CH1 = new QCheckBox(scopeGroup_CH1);
        pausedLabeL_CH1->setObjectName(QString::fromUtf8("pausedLabeL_CH1"));

        verticalLayout_20->addWidget(pausedLabeL_CH1);

        acCoupledLabel_CH1 = new QCheckBox(scopeGroup_CH1);
        acCoupledLabel_CH1->setObjectName(QString::fromUtf8("acCoupledLabel_CH1"));

        verticalLayout_20->addWidget(acCoupledLabel_CH1);

        filterLabel_CH1 = new QCheckBox(scopeGroup_CH1);
        filterLabel_CH1->setObjectName(QString::fromUtf8("filterLabel_CH1"));

        verticalLayout_20->addWidget(filterLabel_CH1);

        doubleSampleLabel = new QCheckBox(scopeGroup_CH1);
        doubleSampleLabel->setObjectName(QString::fromUtf8("doubleSampleLabel"));

        verticalLayout_20->addWidget(doubleSampleLabel);

        hideCH1Box = new QCheckBox(scopeGroup_CH1);
        hideCH1Box->setObjectName(QString::fromUtf8("hideCH1Box"));

        verticalLayout_20->addWidget(hideCH1Box);


        horizontalLayout_4->addLayout(verticalLayout_20);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        label = new QLabel(scopeGroup_CH1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_22->addWidget(label);

        offsetSpinBox_CH1 = new espoSpinBox(scopeGroup_CH1);
        offsetSpinBox_CH1->setObjectName(QString::fromUtf8("offsetSpinBox_CH1"));
        offsetSpinBox_CH1->setDecimals(2);
        offsetSpinBox_CH1->setMinimum(-20.000000000000000);
        offsetSpinBox_CH1->setMaximum(20.000000000000000);

        verticalLayout_22->addWidget(offsetSpinBox_CH1);

        label_2 = new QLabel(scopeGroup_CH1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_22->addWidget(label_2);

        attenuationComboBox_CH1 = new QComboBox(scopeGroup_CH1);
        attenuationComboBox_CH1->addItem(QString());
        attenuationComboBox_CH1->addItem(QString());
        attenuationComboBox_CH1->addItem(QString());
        attenuationComboBox_CH1->setObjectName(QString::fromUtf8("attenuationComboBox_CH1"));

        verticalLayout_22->addWidget(attenuationComboBox_CH1);


        horizontalLayout_4->addLayout(verticalLayout_22);


        verticalLayout_2->addLayout(horizontalLayout_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        voltageInfoMaxLabel_CH1 = new QLabel(scopeGroup_CH1);
        voltageInfoMaxLabel_CH1->setObjectName(QString::fromUtf8("voltageInfoMaxLabel_CH1"));

        gridLayout_2->addWidget(voltageInfoMaxLabel_CH1, 0, 0, 1, 1);

        voltageInfoMaxDisplay_CH1 = new QLCDNumber(scopeGroup_CH1);
        voltageInfoMaxDisplay_CH1->setObjectName(QString::fromUtf8("voltageInfoMaxDisplay_CH1"));
        voltageInfoMaxDisplay_CH1->setMinimumSize(QSize(0, 24));
        voltageInfoMaxDisplay_CH1->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(voltageInfoMaxDisplay_CH1, 0, 1, 1, 1);

        voltageInfoMinLabel_CH1 = new QLabel(scopeGroup_CH1);
        voltageInfoMinLabel_CH1->setObjectName(QString::fromUtf8("voltageInfoMinLabel_CH1"));

        gridLayout_2->addWidget(voltageInfoMinLabel_CH1, 1, 0, 1, 1);

        voltageInfoMinDisplay_CH1 = new QLCDNumber(scopeGroup_CH1);
        voltageInfoMinDisplay_CH1->setObjectName(QString::fromUtf8("voltageInfoMinDisplay_CH1"));
        voltageInfoMinDisplay_CH1->setMinimumSize(QSize(0, 24));
        voltageInfoMinDisplay_CH1->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(voltageInfoMinDisplay_CH1, 1, 1, 1, 1);

        VoltageInfoMeanLabel_CH1 = new QLabel(scopeGroup_CH1);
        VoltageInfoMeanLabel_CH1->setObjectName(QString::fromUtf8("VoltageInfoMeanLabel_CH1"));

        gridLayout_2->addWidget(VoltageInfoMeanLabel_CH1, 2, 0, 1, 1);

        voltageInfoRmsLabel_CH1 = new QLabel(scopeGroup_CH1);
        voltageInfoRmsLabel_CH1->setObjectName(QString::fromUtf8("voltageInfoRmsLabel_CH1"));

        gridLayout_2->addWidget(voltageInfoRmsLabel_CH1, 3, 0, 1, 1);

        voltageInfoRmsDisplay_CH1 = new QLCDNumber(scopeGroup_CH1);
        voltageInfoRmsDisplay_CH1->setObjectName(QString::fromUtf8("voltageInfoRmsDisplay_CH1"));
        voltageInfoRmsDisplay_CH1->setMinimumSize(QSize(0, 24));
        voltageInfoRmsDisplay_CH1->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(voltageInfoRmsDisplay_CH1, 3, 1, 1, 1);

        voltageInfoMeanDisplay_CH1 = new QLCDNumber(scopeGroup_CH1);
        voltageInfoMeanDisplay_CH1->setObjectName(QString::fromUtf8("voltageInfoMeanDisplay_CH1"));
        voltageInfoMeanDisplay_CH1->setMinimumSize(QSize(0, 24));
        voltageInfoMeanDisplay_CH1->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(voltageInfoMeanDisplay_CH1, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout_9->addWidget(scopeGroup_CH1);


        horizontalLayout_13->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        scopeGroup_CH2 = new QGroupBox(centralWidget);
        scopeGroup_CH2->setObjectName(QString::fromUtf8("scopeGroup_CH2"));
        scopeGroup_CH2->setEnabled(true);
        scopeGroup_CH2->setFlat(false);
        scopeGroup_CH2->setCheckable(true);
        scopeGroup_CH2->setChecked(false);
        verticalLayout_11 = new QVBoxLayout(scopeGroup_CH2);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        pausedLabel_CH2 = new QCheckBox(scopeGroup_CH2);
        pausedLabel_CH2->setObjectName(QString::fromUtf8("pausedLabel_CH2"));

        verticalLayout_23->addWidget(pausedLabel_CH2);

        acCoupledLabel_CH2 = new QCheckBox(scopeGroup_CH2);
        acCoupledLabel_CH2->setObjectName(QString::fromUtf8("acCoupledLabel_CH2"));

        verticalLayout_23->addWidget(acCoupledLabel_CH2);

        filterLabel_CH2 = new QCheckBox(scopeGroup_CH2);
        filterLabel_CH2->setObjectName(QString::fromUtf8("filterLabel_CH2"));

        verticalLayout_23->addWidget(filterLabel_CH2);

        xyDisplayLabel = new QCheckBox(scopeGroup_CH2);
        xyDisplayLabel->setObjectName(QString::fromUtf8("xyDisplayLabel"));

        verticalLayout_23->addWidget(xyDisplayLabel);

        hideCH2Box = new QCheckBox(scopeGroup_CH2);
        hideCH2Box->setObjectName(QString::fromUtf8("hideCH2Box"));

        verticalLayout_23->addWidget(hideCH2Box);


        horizontalLayout_6->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        label_3 = new QLabel(scopeGroup_CH2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_24->addWidget(label_3);

        offsetSpinBox_CH2 = new espoSpinBox(scopeGroup_CH2);
        offsetSpinBox_CH2->setObjectName(QString::fromUtf8("offsetSpinBox_CH2"));
        offsetSpinBox_CH2->setMinimum(-20.000000000000000);
        offsetSpinBox_CH2->setMaximum(20.000000000000000);

        verticalLayout_24->addWidget(offsetSpinBox_CH2);

        label_4 = new QLabel(scopeGroup_CH2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_24->addWidget(label_4);

        attenuationComboBox_CH2 = new QComboBox(scopeGroup_CH2);
        attenuationComboBox_CH2->addItem(QString());
        attenuationComboBox_CH2->addItem(QString());
        attenuationComboBox_CH2->addItem(QString());
        attenuationComboBox_CH2->setObjectName(QString::fromUtf8("attenuationComboBox_CH2"));

        verticalLayout_24->addWidget(attenuationComboBox_CH2);


        horizontalLayout_6->addLayout(verticalLayout_24);


        verticalLayout_11->addLayout(horizontalLayout_6);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        voltageInfoMaxLabel_CH2 = new QLabel(scopeGroup_CH2);
        voltageInfoMaxLabel_CH2->setObjectName(QString::fromUtf8("voltageInfoMaxLabel_CH2"));

        gridLayout_3->addWidget(voltageInfoMaxLabel_CH2, 0, 0, 1, 1);

        voltageInfoMaxDisplay_CH2 = new QLCDNumber(scopeGroup_CH2);
        voltageInfoMaxDisplay_CH2->setObjectName(QString::fromUtf8("voltageInfoMaxDisplay_CH2"));
        voltageInfoMaxDisplay_CH2->setMinimumSize(QSize(0, 24));
        voltageInfoMaxDisplay_CH2->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(voltageInfoMaxDisplay_CH2, 0, 1, 1, 1);

        voltageInfoMinLabel_CH2 = new QLabel(scopeGroup_CH2);
        voltageInfoMinLabel_CH2->setObjectName(QString::fromUtf8("voltageInfoMinLabel_CH2"));

        gridLayout_3->addWidget(voltageInfoMinLabel_CH2, 1, 0, 1, 1);

        voltageInfoMinDisplay_CH2 = new QLCDNumber(scopeGroup_CH2);
        voltageInfoMinDisplay_CH2->setObjectName(QString::fromUtf8("voltageInfoMinDisplay_CH2"));
        voltageInfoMinDisplay_CH2->setMinimumSize(QSize(0, 24));
        voltageInfoMinDisplay_CH2->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(voltageInfoMinDisplay_CH2, 1, 1, 1, 1);

        VoltageInfoMeanLabel_CH2 = new QLabel(scopeGroup_CH2);
        VoltageInfoMeanLabel_CH2->setObjectName(QString::fromUtf8("VoltageInfoMeanLabel_CH2"));

        gridLayout_3->addWidget(VoltageInfoMeanLabel_CH2, 2, 0, 1, 1);

        voltageInfoRmsLabel_CH2 = new QLabel(scopeGroup_CH2);
        voltageInfoRmsLabel_CH2->setObjectName(QString::fromUtf8("voltageInfoRmsLabel_CH2"));

        gridLayout_3->addWidget(voltageInfoRmsLabel_CH2, 3, 0, 1, 1);

        voltageInfoRmsDisplay_CH2 = new QLCDNumber(scopeGroup_CH2);
        voltageInfoRmsDisplay_CH2->setObjectName(QString::fromUtf8("voltageInfoRmsDisplay_CH2"));
        voltageInfoRmsDisplay_CH2->setMinimumSize(QSize(0, 24));
        voltageInfoRmsDisplay_CH2->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(voltageInfoRmsDisplay_CH2, 3, 1, 1, 1);

        voltageInfoMeanDisplay_CH2 = new QLCDNumber(scopeGroup_CH2);
        voltageInfoMeanDisplay_CH2->setObjectName(QString::fromUtf8("voltageInfoMeanDisplay_CH2"));
        voltageInfoMeanDisplay_CH2->setMinimumSize(QSize(0, 24));
        voltageInfoMeanDisplay_CH2->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(voltageInfoMeanDisplay_CH2, 2, 1, 1, 1);


        verticalLayout_11->addLayout(gridLayout_3);


        verticalLayout_10->addWidget(scopeGroup_CH2);


        horizontalLayout_13->addLayout(verticalLayout_10);


        verticalLayout_5->addLayout(horizontalLayout_13);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        cursorGroup = new QGroupBox(centralWidget);
        cursorGroup->setObjectName(QString::fromUtf8("cursorGroup"));
        cursorGroup->setEnabled(true);
        cursorGroup->setCheckable(false);
        cursorGroup->setChecked(false);
        verticalLayout_8 = new QVBoxLayout(cursorGroup);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        cursorHoriCheck = new QCheckBox(cursorGroup);
        cursorHoriCheck->setObjectName(QString::fromUtf8("cursorHoriCheck"));

        verticalLayout_8->addWidget(cursorHoriCheck);

        cursorVertCheck = new QCheckBox(cursorGroup);
        cursorVertCheck->setObjectName(QString::fromUtf8("cursorVertCheck"));

        verticalLayout_8->addWidget(cursorVertCheck);

        makeCursorsNicer = new cursorEnabler(cursorGroup);
        makeCursorsNicer->setObjectName(QString::fromUtf8("makeCursorsNicer"));

        verticalLayout_8->addWidget(makeCursorsNicer);


        horizontalLayout_10->addWidget(cursorGroup);

        triggerGroup = new QGroupBox(centralWidget);
        triggerGroup->setObjectName(QString::fromUtf8("triggerGroup"));
        triggerGroup->setEnabled(true);
        triggerGroup->setCheckable(true);
        triggerGroup->setChecked(false);
        verticalLayout_14 = new QVBoxLayout(triggerGroup);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        label_5 = new QLabel(triggerGroup);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_27->addWidget(label_5);

        triggerChannelSelect = new QComboBox(triggerGroup);
        triggerChannelSelect->addItem(QString());
        triggerChannelSelect->addItem(QString());
        triggerChannelSelect->addItem(QString());
        triggerChannelSelect->addItem(QString());
        triggerChannelSelect->setObjectName(QString::fromUtf8("triggerChannelSelect"));

        verticalLayout_27->addWidget(triggerChannelSelect);


        horizontalLayout_11->addLayout(verticalLayout_27);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        label_6 = new QLabel(triggerGroup);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_26->addWidget(label_6);

        triggerLevelValue = new QDoubleSpinBox(triggerGroup);
        triggerLevelValue->setObjectName(QString::fromUtf8("triggerLevelValue"));
        triggerLevelValue->setMinimum(-20.000000000000000);
        triggerLevelValue->setMaximum(20.000000000000000);
        triggerLevelValue->setSingleStep(0.100000000000000);

        verticalLayout_26->addWidget(triggerLevelValue);


        horizontalLayout_11->addLayout(verticalLayout_26);


        verticalLayout_14->addLayout(horizontalLayout_11);

        singleShotCheckBox = new QCheckBox(triggerGroup);
        singleShotCheckBox->setObjectName(QString::fromUtf8("singleShotCheckBox"));

        verticalLayout_14->addWidget(singleShotCheckBox);


        horizontalLayout_10->addWidget(triggerGroup);


        verticalLayout_25->addLayout(horizontalLayout_10);


        verticalLayout_5->addLayout(verticalLayout_25);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        multimeterGroup = new QGroupBox(centralWidget);
        multimeterGroup->setObjectName(QString::fromUtf8("multimeterGroup"));
        multimeterGroup->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(multimeterGroup->sizePolicy().hasHeightForWidth());
        multimeterGroup->setSizePolicy(sizePolicy2);
        multimeterGroup->setCheckable(true);
        multimeterGroup->setChecked(false);
        horizontalLayout_14 = new QHBoxLayout(multimeterGroup);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        multimeterPauseCheckBox = new QCheckBox(multimeterGroup);
        multimeterPauseCheckBox->setObjectName(QString::fromUtf8("multimeterPauseCheckBox"));

        verticalLayout_28->addWidget(multimeterPauseCheckBox);

        multimeterModeLabel = new QLabel(multimeterGroup);
        multimeterModeLabel->setObjectName(QString::fromUtf8("multimeterModeLabel"));

        verticalLayout_28->addWidget(multimeterModeLabel);

        multimeterModeSelect = new QComboBox(multimeterGroup);
        multimeterModeSelect->addItem(QString());
        multimeterModeSelect->addItem(QString());
        multimeterModeSelect->addItem(QString());
        multimeterModeSelect->addItem(QString());
        multimeterModeSelect->setObjectName(QString::fromUtf8("multimeterModeSelect"));

        verticalLayout_28->addWidget(multimeterModeSelect);

        multimeterResistanceLabel = new QLabel(multimeterGroup);
        multimeterResistanceLabel->setObjectName(QString::fromUtf8("multimeterResistanceLabel"));

        verticalLayout_28->addWidget(multimeterResistanceLabel);

        multimeterResistanceSelect = new espoSpinBox(multimeterGroup);
        multimeterResistanceSelect->setObjectName(QString::fromUtf8("multimeterResistanceSelect"));
        multimeterResistanceSelect->setDecimals(0);
        multimeterResistanceSelect->setMaximum(1000000.000000000000000);

        verticalLayout_28->addWidget(multimeterResistanceSelect);

        multimeterRLabel = new QLabel(multimeterGroup);
        multimeterRLabel->setObjectName(QString::fromUtf8("multimeterRLabel"));

        verticalLayout_28->addWidget(multimeterRLabel);

        multimeterRComboBox = new QComboBox(multimeterGroup);
        multimeterRComboBox->addItem(QString());
        multimeterRComboBox->addItem(QString());
        multimeterRComboBox->setObjectName(QString::fromUtf8("multimeterRComboBox"));

        verticalLayout_28->addWidget(multimeterRComboBox);


        horizontalLayout_14->addLayout(verticalLayout_28);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        multimeterMinLabel = new QLabel(multimeterGroup);
        multimeterMinLabel->setObjectName(QString::fromUtf8("multimeterMinLabel"));

        gridLayout->addWidget(multimeterMinLabel, 1, 0, 1, 1);

        multimeterMaxDisplay = new QLCDNumber(multimeterGroup);
        multimeterMaxDisplay->setObjectName(QString::fromUtf8("multimeterMaxDisplay"));
        multimeterMaxDisplay->setMinimumSize(QSize(0, 24));
        multimeterMaxDisplay->setFrameShape(QFrame::NoFrame);
        multimeterMaxDisplay->setDigitCount(4);

        gridLayout->addWidget(multimeterMaxDisplay, 0, 1, 1, 1);

        multimeterMaxLabel = new QLabel(multimeterGroup);
        multimeterMaxLabel->setObjectName(QString::fromUtf8("multimeterMaxLabel"));

        gridLayout->addWidget(multimeterMaxLabel, 0, 0, 1, 1);

        multimeterMeanLabel = new QLabel(multimeterGroup);
        multimeterMeanLabel->setObjectName(QString::fromUtf8("multimeterMeanLabel"));

        gridLayout->addWidget(multimeterMeanLabel, 2, 0, 1, 1);

        multimeterRmsLabel = new QLabel(multimeterGroup);
        multimeterRmsLabel->setObjectName(QString::fromUtf8("multimeterRmsLabel"));

        gridLayout->addWidget(multimeterRmsLabel, 3, 0, 1, 1);

        multimeterMinDisplay = new QLCDNumber(multimeterGroup);
        multimeterMinDisplay->setObjectName(QString::fromUtf8("multimeterMinDisplay"));
        multimeterMinDisplay->setMinimumSize(QSize(0, 24));
        multimeterMinDisplay->setFrameShape(QFrame::NoFrame);
        multimeterMinDisplay->setDigitCount(4);

        gridLayout->addWidget(multimeterMinDisplay, 1, 1, 1, 1);

        multimeterMeanDisplay = new QLCDNumber(multimeterGroup);
        multimeterMeanDisplay->setObjectName(QString::fromUtf8("multimeterMeanDisplay"));
        multimeterMeanDisplay->setMinimumSize(QSize(0, 24));
        multimeterMeanDisplay->setFrameShape(QFrame::NoFrame);
        multimeterMeanDisplay->setDigitCount(4);

        gridLayout->addWidget(multimeterMeanDisplay, 2, 1, 1, 1);

        multimeterRmsDisplay = new QLCDNumber(multimeterGroup);
        multimeterRmsDisplay->setObjectName(QString::fromUtf8("multimeterRmsDisplay"));
        multimeterRmsDisplay->setMinimumSize(QSize(0, 24));
        multimeterRmsDisplay->setFrameShape(QFrame::NoFrame);
        multimeterRmsDisplay->setDigitCount(4);

        gridLayout->addWidget(multimeterRmsDisplay, 3, 1, 1, 1);


        horizontalLayout_14->addLayout(gridLayout);


        verticalLayout_5->addWidget(multimeterGroup);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        signalGenGroup_CH1 = new QGroupBox(centralWidget);
        signalGenGroup_CH1->setObjectName(QString::fromUtf8("signalGenGroup_CH1"));
        signalGenGroup_CH1->setEnabled(true);
        sizePolicy1.setHeightForWidth(signalGenGroup_CH1->sizePolicy().hasHeightForWidth());
        signalGenGroup_CH1->setSizePolicy(sizePolicy1);
        signalGenGroup_CH1->setCheckable(false);
        signalGenGroup_CH1->setChecked(false);
        verticalLayout_19 = new QVBoxLayout(signalGenGroup_CH1);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frequencyLabel_CH1 = new QLabel(signalGenGroup_CH1);
        frequencyLabel_CH1->setObjectName(QString::fromUtf8("frequencyLabel_CH1"));

        gridLayout_5->addWidget(frequencyLabel_CH1, 2, 0, 1, 1);

        amplitudeValue_CH1 = new espoSpinBox(signalGenGroup_CH1);
        amplitudeValue_CH1->setObjectName(QString::fromUtf8("amplitudeValue_CH1"));
        amplitudeValue_CH1->setMaximum(9.600000000000000);
        amplitudeValue_CH1->setSingleStep(0.100000000000000);

        gridLayout_5->addWidget(amplitudeValue_CH1, 3, 1, 1, 1);

        frequencyValue_CH1 = new espoSpinBox(signalGenGroup_CH1);
        frequencyValue_CH1->setObjectName(QString::fromUtf8("frequencyValue_CH1"));
        frequencyValue_CH1->setSuffix(QString::fromUtf8("Hz"));
        frequencyValue_CH1->setDecimals(2);
        frequencyValue_CH1->setMinimum(0.000000000000000);
        frequencyValue_CH1->setMaximum(1000000.000000000000000);
        frequencyValue_CH1->setSingleStep(100.000000000000000);
        frequencyValue_CH1->setValue(1000.000000000000000);

        gridLayout_5->addWidget(frequencyValue_CH1, 2, 1, 1, 1);

        amplitudeLabel_CH1 = new QLabel(signalGenGroup_CH1);
        amplitudeLabel_CH1->setObjectName(QString::fromUtf8("amplitudeLabel_CH1"));

        gridLayout_5->addWidget(amplitudeLabel_CH1, 3, 0, 1, 1);

        waveformSelect_CH1 = new espoComboBox(signalGenGroup_CH1);
        waveformSelect_CH1->setObjectName(QString::fromUtf8("waveformSelect_CH1"));

        gridLayout_5->addWidget(waveformSelect_CH1, 1, 1, 1, 1);

        waveformLabel_CH1 = new QLabel(signalGenGroup_CH1);
        waveformLabel_CH1->setObjectName(QString::fromUtf8("waveformLabel_CH1"));

        gridLayout_5->addWidget(waveformLabel_CH1, 1, 0, 1, 1);

        dcOffsetLabel_CH1 = new QLabel(signalGenGroup_CH1);
        dcOffsetLabel_CH1->setObjectName(QString::fromUtf8("dcOffsetLabel_CH1"));

        gridLayout_5->addWidget(dcOffsetLabel_CH1, 4, 0, 1, 1);

        dcOffsetValue_CH1 = new espoSpinBox(signalGenGroup_CH1);
        dcOffsetValue_CH1->setObjectName(QString::fromUtf8("dcOffsetValue_CH1"));
        dcOffsetValue_CH1->setMaximum(9.600000000000000);
        dcOffsetValue_CH1->setSingleStep(0.100000000000000);

        gridLayout_5->addWidget(dcOffsetValue_CH1, 4, 1, 1, 1);


        verticalLayout_19->addLayout(gridLayout_5);


        horizontalLayout_5->addWidget(signalGenGroup_CH1);

        signalGenGroup_CH2 = new QGroupBox(centralWidget);
        signalGenGroup_CH2->setObjectName(QString::fromUtf8("signalGenGroup_CH2"));
        signalGenGroup_CH2->setEnabled(true);
        sizePolicy1.setHeightForWidth(signalGenGroup_CH2->sizePolicy().hasHeightForWidth());
        signalGenGroup_CH2->setSizePolicy(sizePolicy1);
        signalGenGroup_CH2->setCheckable(false);
        signalGenGroup_CH2->setChecked(false);
        verticalLayout_21 = new QVBoxLayout(signalGenGroup_CH2);
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frequencyValue_CH2 = new espoSpinBox(signalGenGroup_CH2);
        frequencyValue_CH2->setObjectName(QString::fromUtf8("frequencyValue_CH2"));
        frequencyValue_CH2->setEnabled(true);
        frequencyValue_CH2->setSuffix(QString::fromUtf8("Hz"));
        frequencyValue_CH2->setDecimals(2);
        frequencyValue_CH2->setMaximum(1000000.000000000000000);
        frequencyValue_CH2->setSingleStep(100.000000000000000);
        frequencyValue_CH2->setValue(1000.000000000000000);

        gridLayout_6->addWidget(frequencyValue_CH2, 1, 1, 1, 1);

        amplitudeLabel_CH2 = new QLabel(signalGenGroup_CH2);
        amplitudeLabel_CH2->setObjectName(QString::fromUtf8("amplitudeLabel_CH2"));
        amplitudeLabel_CH2->setEnabled(true);

        gridLayout_6->addWidget(amplitudeLabel_CH2, 2, 0, 1, 1);

        waveformLabel_CH2 = new QLabel(signalGenGroup_CH2);
        waveformLabel_CH2->setObjectName(QString::fromUtf8("waveformLabel_CH2"));
        waveformLabel_CH2->setEnabled(true);

        gridLayout_6->addWidget(waveformLabel_CH2, 0, 0, 1, 1);

        frequencyLabel_CH2 = new QLabel(signalGenGroup_CH2);
        frequencyLabel_CH2->setObjectName(QString::fromUtf8("frequencyLabel_CH2"));
        frequencyLabel_CH2->setEnabled(true);

        gridLayout_6->addWidget(frequencyLabel_CH2, 1, 0, 1, 1);

        dcOffsetLabel_CH2 = new QLabel(signalGenGroup_CH2);
        dcOffsetLabel_CH2->setObjectName(QString::fromUtf8("dcOffsetLabel_CH2"));
        dcOffsetLabel_CH2->setEnabled(true);

        gridLayout_6->addWidget(dcOffsetLabel_CH2, 3, 0, 1, 1);

        amplitudeValue_CH2 = new espoSpinBox(signalGenGroup_CH2);
        amplitudeValue_CH2->setObjectName(QString::fromUtf8("amplitudeValue_CH2"));
        amplitudeValue_CH2->setEnabled(true);
        amplitudeValue_CH2->setMaximum(10.000000000000000);
        amplitudeValue_CH2->setSingleStep(0.100000000000000);

        gridLayout_6->addWidget(amplitudeValue_CH2, 2, 1, 1, 1);

        waveformSelect_CH2 = new espoComboBox(signalGenGroup_CH2);
        waveformSelect_CH2->setObjectName(QString::fromUtf8("waveformSelect_CH2"));
        waveformSelect_CH2->setEnabled(true);
        waveformSelect_CH2->setEditable(false);

        gridLayout_6->addWidget(waveformSelect_CH2, 0, 1, 1, 1);

        dcOffsetValue_CH2 = new espoSpinBox(signalGenGroup_CH2);
        dcOffsetValue_CH2->setObjectName(QString::fromUtf8("dcOffsetValue_CH2"));
        dcOffsetValue_CH2->setEnabled(true);
        dcOffsetValue_CH2->setMaximum(10.000000000000000);
        dcOffsetValue_CH2->setSingleStep(0.100000000000000);

        gridLayout_6->addWidget(dcOffsetValue_CH2, 3, 1, 1, 1);


        verticalLayout_21->addLayout(gridLayout_6);


        horizontalLayout_5->addWidget(signalGenGroup_CH2);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        controller_iso = new isoDriver(centralWidget);
        controller_iso->setObjectName(QString::fromUtf8("controller_iso"));

        verticalLayout_5->addWidget(controller_iso);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        psuGroup = new QGroupBox(centralWidget);
        psuGroup->setObjectName(QString::fromUtf8("psuGroup"));
        psuGroup->setAutoFillBackground(false);
        verticalLayout_15 = new QVBoxLayout(psuGroup);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        psuSlider = new espoSlider(psuGroup);
        psuSlider->setObjectName(QString::fromUtf8("psuSlider"));
        psuSlider->setEnabled(false);
        psuSlider->setMinimum(90);
        psuSlider->setMaximum(240);
        psuSlider->setSingleStep(1);
        psuSlider->setOrientation(Qt::Vertical);
        psuSlider->setTickPosition(QSlider::TicksBelow);
        psuSlider->setTickInterval(20);

        verticalLayout_15->addWidget(psuSlider);

        lockPsuCheckBox = new timedTickBox(psuGroup);
        lockPsuCheckBox->setObjectName(QString::fromUtf8("lockPsuCheckBox"));
        lockPsuCheckBox->setChecked(true);

        verticalLayout_15->addWidget(lockPsuCheckBox);

        psuDisplay = new QLCDNumber(psuGroup);
        psuDisplay->setObjectName(QString::fromUtf8("psuDisplay"));
        psuDisplay->setMinimumSize(QSize(108, 36));
        psuDisplay->setMaximumSize(QSize(108, 36));
        psuDisplay->setSmallDecimalPoint(true);
        psuDisplay->setDigitCount(4);
        psuDisplay->setProperty("value", QVariant(5.000000000000000));
        psuDisplay->setProperty("intValue", QVariant(5));

        verticalLayout_15->addWidget(psuDisplay);


        verticalLayout_18->addWidget(psuGroup);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        busSifferGroup_CH1 = new QGroupBox(centralWidget);
        busSifferGroup_CH1->setObjectName(QString::fromUtf8("busSifferGroup_CH1"));
        busSifferGroup_CH1->setCheckable(true);
        busSifferGroup_CH1->setChecked(false);
        verticalLayout_7 = new QVBoxLayout(busSifferGroup_CH1);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        pause_LA = new QCheckBox(busSifferGroup_CH1);
        pause_LA->setObjectName(QString::fromUtf8("pause_LA"));
        pause_LA->setEnabled(false);

        verticalLayout_7->addWidget(pause_LA);

        serialDecodingCheck_CH1 = new QGroupBox(busSifferGroup_CH1);
        serialDecodingCheck_CH1->setObjectName(QString::fromUtf8("serialDecodingCheck_CH1"));
        serialDecodingCheck_CH1->setFlat(true);
        serialDecodingCheck_CH1->setCheckable(true);
        serialDecodingCheck_CH1->setChecked(false);
        verticalLayout_6 = new QVBoxLayout(serialDecodingCheck_CH1);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 6, 0, 0);

        verticalLayout_7->addWidget(serialDecodingCheck_CH1);


        verticalLayout_3->addWidget(busSifferGroup_CH1);

        busSnifferGroup_CH2 = new QGroupBox(centralWidget);
        busSnifferGroup_CH2->setObjectName(QString::fromUtf8("busSnifferGroup_CH2"));
        busSnifferGroup_CH2->setEnabled(false);
        busSnifferGroup_CH2->setCheckable(true);
        busSnifferGroup_CH2->setChecked(false);
        verticalLayout_16 = new QVBoxLayout(busSnifferGroup_CH2);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        serialDecodingCheck_CH2 = new QGroupBox(busSnifferGroup_CH2);
        serialDecodingCheck_CH2->setObjectName(QString::fromUtf8("serialDecodingCheck_CH2"));
        serialDecodingCheck_CH2->setFlat(true);
        serialDecodingCheck_CH2->setCheckable(true);
        serialDecodingCheck_CH2->setChecked(false);
        verticalLayout_17 = new QVBoxLayout(serialDecodingCheck_CH2);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 6, 0, 0);

        verticalLayout_16->addWidget(serialDecodingCheck_CH2);


        verticalLayout_3->addWidget(busSnifferGroup_CH2);

        digitalOutputGroup = new QGroupBox(centralWidget);
        digitalOutputGroup->setObjectName(QString::fromUtf8("digitalOutputGroup"));
        gridLayout_4 = new QGridLayout(digitalOutputGroup);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        digitalOutCheckbox_CH3 = new QCheckBox(digitalOutputGroup);
        digitalOutCheckbox_CH3->setObjectName(QString::fromUtf8("digitalOutCheckbox_CH3"));

        gridLayout_4->addWidget(digitalOutCheckbox_CH3, 1, 0, 1, 1);

        digitalOutCheckbox_CH2 = new QCheckBox(digitalOutputGroup);
        digitalOutCheckbox_CH2->setObjectName(QString::fromUtf8("digitalOutCheckbox_CH2"));

        gridLayout_4->addWidget(digitalOutCheckbox_CH2, 0, 1, 1, 1);

        digitalOutCheckbox_CH1 = new QCheckBox(digitalOutputGroup);
        digitalOutCheckbox_CH1->setObjectName(QString::fromUtf8("digitalOutCheckbox_CH1"));

        gridLayout_4->addWidget(digitalOutCheckbox_CH1, 0, 0, 1, 1);

        digitalOutCheckbox_CH4 = new QCheckBox(digitalOutputGroup);
        digitalOutCheckbox_CH4->setObjectName(QString::fromUtf8("digitalOutCheckbox_CH4"));

        gridLayout_4->addWidget(digitalOutCheckbox_CH4, 1, 1, 1, 1);

        digitalOutCheckbox_CH2->raise();
        digitalOutCheckbox_CH1->raise();
        digitalOutCheckbox_CH3->raise();
        digitalOutCheckbox_CH4->raise();

        verticalLayout_3->addWidget(digitalOutputGroup);

        debugButton1 = new QPushButton(centralWidget);
        debugButton1->setObjectName(QString::fromUtf8("debugButton1"));

        verticalLayout_3->addWidget(debugButton1);

        debugButton2 = new QPushButton(centralWidget);
        debugButton2->setObjectName(QString::fromUtf8("debugButton2"));

        verticalLayout_3->addWidget(debugButton2);

        kickstartIsoButton = new QPushButton(centralWidget);
        kickstartIsoButton->setObjectName(QString::fromUtf8("kickstartIsoButton"));

        verticalLayout_3->addWidget(kickstartIsoButton);

        debugButton3 = new QPushButton(centralWidget);
        debugButton3->setObjectName(QString::fromUtf8("debugButton3"));

        verticalLayout_3->addWidget(debugButton3);

        bufferDisplay = new bufferControl(centralWidget);
        bufferDisplay->setObjectName(QString::fromUtf8("bufferDisplay"));
        bufferDisplay->setMinimumSize(QSize(96, 36));
        bufferDisplay->setMaximumSize(QSize(96, 36));
        bufferDisplay->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(bufferDisplay);


        verticalLayout_18->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_18);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1493, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTake_Snapshot = new QMenu(menuFile);
        menuTake_Snapshot->setObjectName(QString::fromUtf8("menuTake_Snapshot"));
        menuRecord = new QMenu(menuFile);
        menuRecord->setObjectName(QString::fromUtf8("menuRecord"));
        menuOscilloscope_2 = new QMenu(menuBar);
        menuOscilloscope_2->setObjectName(QString::fromUtf8("menuOscilloscope_2"));
        menuGain_2 = new QMenu(menuOscilloscope_2);
        menuGain_2->setObjectName(QString::fromUtf8("menuGain_2"));
        menuCH1_Stats = new noCloseMenu(menuOscilloscope_2);
        menuCH1_Stats->setObjectName(QString::fromUtf8("menuCH1_Stats"));
        menuCH2_Stats = new noCloseMenu(menuOscilloscope_2);
        menuCH2_Stats->setObjectName(QString::fromUtf8("menuCH2_Stats"));
        menuFrame_rate = new QMenu(menuOscilloscope_2);
        menuFrame_rate->setObjectName(QString::fromUtf8("menuFrame_rate"));
        menuRange = new QMenu(menuOscilloscope_2);
        menuRange->setObjectName(QString::fromUtf8("menuRange"));
        menuMultimeter_2 = new QMenu(menuBar);
        menuMultimeter_2->setObjectName(QString::fromUtf8("menuMultimeter_2"));
        menuV_2 = new QMenu(menuMultimeter_2);
        menuV_2->setObjectName(QString::fromUtf8("menuV_2"));
        menuV_2->setGeometry(QRect(0, 0, 160, 120));
        menuI_2 = new QMenu(menuMultimeter_2);
        menuI_2->setObjectName(QString::fromUtf8("menuI_2"));
        menuRange_R = new QMenu(menuMultimeter_2);
        menuRange_R->setObjectName(QString::fromUtf8("menuRange_R"));
        menuRange_C = new QMenu(menuMultimeter_2);
        menuRange_C->setObjectName(QString::fromUtf8("menuRange_C"));
        menuBus_Sniffer = new QMenu(menuBar);
        menuBus_Sniffer->setObjectName(QString::fromUtf8("menuBus_Sniffer"));
        menuUART_1 = new QMenu(menuBus_Sniffer);
        menuUART_1->setObjectName(QString::fromUtf8("menuUART_1"));
        menuBaud_Rate = new QMenu(menuUART_1);
        menuBaud_Rate->setObjectName(QString::fromUtf8("menuBaud_Rate"));
        menuParity_Bit = new QMenu(menuUART_1);
        menuParity_Bit->setObjectName(QString::fromUtf8("menuParity_Bit"));
        menuData_Bits = new QMenu(menuUART_1);
        menuData_Bits->setObjectName(QString::fromUtf8("menuData_Bits"));
        menuUART_2 = new QMenu(menuBus_Sniffer);
        menuUART_2->setObjectName(QString::fromUtf8("menuUART_2"));
        menuBaud_Rate_2 = new QMenu(menuUART_2);
        menuBaud_Rate_2->setObjectName(QString::fromUtf8("menuBaud_Rate_2"));
        menuData_Bits_2 = new QMenu(menuUART_2);
        menuData_Bits_2->setObjectName(QString::fromUtf8("menuData_Bits_2"));
        menuParity_Bit_2 = new QMenu(menuUART_2);
        menuParity_Bit_2->setObjectName(QString::fromUtf8("menuParity_Bit_2"));
        menuProtocol = new QMenu(menuBus_Sniffer);
        menuProtocol->setObjectName(QString::fromUtf8("menuProtocol"));
        menuPower_Supply = new QMenu(menuBar);
        menuPower_Supply->setObjectName(QString::fromUtf8("menuPower_Supply"));
        menuConnection_Type = new QMenu(menuBar);
        menuConnection_Type->setObjectName(QString::fromUtf8("menuConnection_Type"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuSignal_Generator = new QMenu(menuBar);
        menuSignal_Generator->setObjectName(QString::fromUtf8("menuSignal_Generator"));
        menuOffset_Type = new QMenu(menuSignal_Generator);
        menuOffset_Type->setObjectName(QString::fromUtf8("menuOffset_Type"));
        menuAccessibility = new QMenu(menuBar);
        menuAccessibility->setObjectName(QString::fromUtf8("menuAccessibility"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOscilloscope_2->menuAction());
        menuBar->addAction(menuSignal_Generator->menuAction());
        menuBar->addAction(menuMultimeter_2->menuAction());
        menuBar->addAction(menuBus_Sniffer->menuAction());
        menuBar->addAction(menuPower_Supply->menuAction());
        menuBar->addAction(menuConnection_Type->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuAccessibility->menuAction());
        menuFile->addAction(actionDAQ_Settings);
        menuFile->addAction(menuRecord->menuAction());
        menuFile->addAction(actionOpen_DAQ_File);
        menuFile->addAction(menuTake_Snapshot->menuAction());
        menuFile->addAction(actionExportImage);
        menuFile->addAction(actionQuit);
        menuTake_Snapshot->addAction(actionSnapshot_CH1);
        menuTake_Snapshot->addAction(actionSnapshot_CH2);
        menuRecord->addAction(actionRecord_CH1);
        menuRecord->addAction(actionRecord_CH2);
        menuOscilloscope_2->addAction(menuRange->menuAction());
        menuOscilloscope_2->addSeparator();
        menuOscilloscope_2->addAction(menuFrame_rate->menuAction());
        menuOscilloscope_2->addSeparator();
        menuOscilloscope_2->addAction(menuGain_2->menuAction());
        menuOscilloscope_2->addSeparator();
        menuOscilloscope_2->addAction(menuCH1_Stats->menuAction());
        menuOscilloscope_2->addAction(menuCH2_Stats->menuAction());
        menuOscilloscope_2->addAction(actionCursor_Stats);
        menuOscilloscope_2->addSeparator();
        menuOscilloscope_2->addAction(actionCalibrate);
        menuOscilloscope_2->addAction(actionForce_Square);
        menuOscilloscope_2->addAction(actionAutomatically_Enable_Cursors);
        menuOscilloscope_2->addAction(actionShow_Range_Dialog_on_Main_Page);
        menuOscilloscope_2->addSeparator();
        menuOscilloscope_2->addAction(actionHide_Widget_Oscilloscope);
        menuOscilloscope_2->addAction(actionFrequency_Spectrum);
        menuGain_2->addAction(actionGainAuto);
        menuGain_2->addAction(actionGain0_5);
        menuGain_2->addAction(actionGain1);
        menuGain_2->addAction(actionGain2);
        menuGain_2->addAction(actionGain4);
        menuGain_2->addAction(actionGain8);
        menuGain_2->addAction(actionGain16);
        menuGain_2->addAction(actionGain32);
        menuGain_2->addAction(actionGain64);
        menuCH1_Stats->addAction(actionMax);
        menuCH1_Stats->addAction(actionMin);
        menuCH1_Stats->addAction(actionMean);
        menuCH1_Stats->addAction(actionRMS);
        menuCH2_Stats->addAction(actionMax_2);
        menuCH2_Stats->addAction(actionMin_2);
        menuCH2_Stats->addAction(actionMean_2);
        menuCH2_Stats->addAction(actionRMS_2);
        menuFrame_rate->addAction(action60FPS);
        menuFrame_rate->addAction(action30FPS);
        menuFrame_rate->addAction(action20FPS);
        menuFrame_rate->addAction(action15FPS);
        menuFrame_rate->addAction(action10FPS);
        menuFrame_rate->addAction(action5FPS);
        menuRange->addAction(actionSnap_to_Cursors);
        menuRange->addAction(actionEnter_Manually);
        menuMultimeter_2->addSeparator();
        menuMultimeter_2->addAction(menuV_2->menuAction());
        menuMultimeter_2->addAction(menuI_2->menuAction());
        menuMultimeter_2->addAction(menuRange_R->menuAction());
        menuMultimeter_2->addAction(menuRange_C->menuAction());
        menuMultimeter_2->addSeparator();
        menuMultimeter_2->addAction(actionHide_Widget_Multimeter);
        menuV_2->addAction(actionAutoV);
        menuV_2->addAction(actionMV);
        menuV_2->addAction(actionV);
        menuI_2->addAction(actionAutoI);
        menuI_2->addAction(actionMA);
        menuI_2->addAction(actionA);
        menuRange_R->addAction(actionAutoR);
        menuRange_R->addAction(actionOhm);
        menuRange_R->addAction(actionKOhm);
        menuRange_C->addAction(actionAutoC);
        menuRange_C->addAction(actionNF);
        menuRange_C->addAction(action_F);
        menuBus_Sniffer->addAction(menuProtocol->menuAction());
        menuBus_Sniffer->addAction(menuUART_1->menuAction());
        menuBus_Sniffer->addAction(menuUART_2->menuAction());
        menuBus_Sniffer->addSeparator();
        menuBus_Sniffer->addAction(actionHide_Widget_LogicAnalyzer);
        menuUART_1->addAction(menuBaud_Rate->menuAction());
        menuUART_1->addAction(menuData_Bits->menuAction());
        menuUART_1->addAction(menuParity_Bit->menuAction());
        menuUART_1->addAction(actionHexDisplay);
        menuBaud_Rate->addAction(action300);
        menuBaud_Rate->addAction(action600);
        menuBaud_Rate->addAction(action1200);
        menuBaud_Rate->addAction(action2400);
        menuBaud_Rate->addAction(action4800);
        menuBaud_Rate->addAction(action9600);
        menuBaud_Rate->addAction(action14400);
        menuBaud_Rate->addAction(action19200);
        menuBaud_Rate->addAction(action28800);
        menuBaud_Rate->addAction(action38400);
        menuBaud_Rate->addAction(action57600);
        menuBaud_Rate->addAction(action115200);
        menuParity_Bit->addAction(actionNone);
        menuParity_Bit->addAction(actionEven);
        menuParity_Bit->addAction(actionOdd);
        menuData_Bits->addAction(action8);
        menuUART_2->addAction(menuBaud_Rate_2->menuAction());
        menuUART_2->addAction(menuData_Bits_2->menuAction());
        menuUART_2->addAction(menuParity_Bit_2->menuAction());
        menuUART_2->addAction(actionHexDisplay_2);
        menuBaud_Rate_2->addAction(action300_2);
        menuBaud_Rate_2->addAction(action600_2);
        menuBaud_Rate_2->addAction(action1200_2);
        menuBaud_Rate_2->addAction(action2400_2);
        menuBaud_Rate_2->addAction(action4800_2);
        menuBaud_Rate_2->addAction(action9600_2);
        menuBaud_Rate_2->addAction(action14400_2);
        menuBaud_Rate_2->addAction(action19200_2);
        menuBaud_Rate_2->addAction(action28800_2);
        menuBaud_Rate_2->addAction(action38400_2);
        menuBaud_Rate_2->addAction(action57600_2);
        menuBaud_Rate_2->addAction(action115200_2);
        menuData_Bits_2->addAction(action8_2);
        menuParity_Bit_2->addAction(actionNone_2);
        menuParity_Bit_2->addAction(actionEven_2);
        menuParity_Bit_2->addAction(actionOdd_2);
        menuProtocol->addAction(actionSerial);
        menuProtocol->addAction(actionI2C);
        menuPower_Supply->addAction(actionAuto_Lock);
        menuPower_Supply->addAction(actionCalibrate_2);
        menuPower_Supply->addSeparator();
        menuPower_Supply->addAction(actionHide_Widget_PowerSupply);
        menuConnection_Type->addAction(actionLo_bw);
        menuConnection_Type->addAction(actionSingle_ep_msync);
        menuConnection_Type->addAction(actionSingle_ep_async);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionPinout);
        menuHelp->addAction(actionFirmware_Recovery);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionShow_Debug_Console);
        menuSignal_Generator->addAction(menuOffset_Type->menuAction());
        menuSignal_Generator->addSeparator();
        menuSignal_Generator->addAction(actionHide_Widget_SignalGen);
        menuOffset_Type->addAction(actionFrom_GND);
        menuOffset_Type->addAction(actionMean_Point_from_GND);
        menuAccessibility->addAction(actionDark_Mode);

        retranslateUi(MainWindow);
        QObject::connect(scopeGroup_CH1, SIGNAL(toggled(bool)), bufferDisplay, SLOT(scopeIn_CH1(bool)));
        QObject::connect(scopeGroup_CH2, SIGNAL(toggled(bool)), bufferDisplay, SLOT(scopeIn_CH2(bool)));
        QObject::connect(signalGenGroup_CH2, SIGNAL(toggled(bool)), bufferDisplay, SLOT(signalGenIn(bool)));
        QObject::connect(bufferDisplay, SIGNAL(busSnifferOut_CH2(bool)), busSnifferGroup_CH2, SLOT(setEnabled(bool)));
        QObject::connect(bufferDisplay, SIGNAL(signalGenOut(bool)), signalGenGroup_CH2, SLOT(setEnabled(bool)));
        QObject::connect(bufferDisplay, SIGNAL(scopeOut_CH1(bool)), scopeGroup_CH1, SLOT(setEnabled(bool)));
        QObject::connect(bufferDisplay, SIGNAL(scopeOut_CH2(bool)), scopeGroup_CH2, SLOT(setEnabled(bool)));
        QObject::connect(bufferDisplay, SIGNAL(busSnifferUncheck(bool)), busSnifferGroup_CH2, SLOT(setChecked(bool)));
        QObject::connect(bufferDisplay, SIGNAL(scopeUncheck(bool)), scopeGroup_CH2, SLOT(setChecked(bool)));
        QObject::connect(doubleSampleLabel, SIGNAL(toggled(bool)), bufferDisplay, SLOT(scopeDsrIn(bool)));
        QObject::connect(bufferDisplay, SIGNAL(scopeDsrUncheck(bool)), doubleSampleLabel, SLOT(setChecked(bool)));
        QObject::connect(bufferDisplay, SIGNAL(scopeDsrOut(bool)), doubleSampleLabel, SLOT(setEnabled(bool)));
        QObject::connect(psuSlider, SIGNAL(valueChanged(int)), psuSlider, SLOT(selfMoved(int)));
        QObject::connect(psuSlider, SIGNAL(lcdOut(QString)), psuDisplay, SLOT(display(QString)));
        QObject::connect(amplitudeValue_CH1, SIGNAL(valueChanged(double)), dcOffsetValue_CH1, SLOT(maximumChanged(double)));
        QObject::connect(amplitudeValue_CH2, SIGNAL(valueChanged(double)), dcOffsetValue_CH2, SLOT(maximumChanged(double)));
        QObject::connect(dcOffsetValue_CH1, SIGNAL(valueChanged(double)), amplitudeValue_CH1, SLOT(maximumChanged(double)));
        QObject::connect(dcOffsetValue_CH2, SIGNAL(valueChanged(double)), amplitudeValue_CH2, SLOT(maximumChanged(double)));
        QObject::connect(waveformSelect_CH1, SIGNAL(currentTextChanged(QString)), controller_fg, SLOT(waveformName_CH1(QString)));
        QObject::connect(waveformSelect_CH2, SIGNAL(currentTextChanged(QString)), controller_fg, SLOT(waveformName_CH2(QString)));
        QObject::connect(amplitudeValue_CH1, SIGNAL(valueChanged(double)), controller_fg, SLOT(amplitudeUpdate_CH1(double)));
        QObject::connect(dcOffsetValue_CH1, SIGNAL(valueChanged(double)), controller_fg, SLOT(offsetUpdate_CH1(double)));
        QObject::connect(bufferDisplay, SIGNAL(busSnifferOut_CH1(bool)), busSifferGroup_CH1, SLOT(setEnabled(bool)));
        QObject::connect(bufferDisplay, SIGNAL(busSnifferOut_CH2(bool)), busSnifferGroup_CH2, SLOT(setEnabled(bool)));
        QObject::connect(busSifferGroup_CH1, SIGNAL(toggled(bool)), bufferDisplay, SLOT(busSnifferIn_CH1(bool)));
        QObject::connect(busSnifferGroup_CH2, SIGNAL(toggled(bool)), bufferDisplay, SLOT(busSnifferIn_CH2(bool)));
        QObject::connect(digitalOutCheckbox_CH1, SIGNAL(toggled(bool)), bufferDisplay, SLOT(digIn_CH1(bool)));
        QObject::connect(digitalOutCheckbox_CH2, SIGNAL(toggled(bool)), bufferDisplay, SLOT(digIn_CH2(bool)));
        QObject::connect(digitalOutCheckbox_CH3, SIGNAL(toggled(bool)), bufferDisplay, SLOT(digIn_CH3(bool)));
        QObject::connect(digitalOutCheckbox_CH4, SIGNAL(toggled(bool)), bufferDisplay, SLOT(digIn_CH4(bool)));
        QObject::connect(amplitudeValue_CH2, SIGNAL(valueChanged(double)), controller_fg, SLOT(amplitudeUpdate_CH2(double)));
        QObject::connect(dcOffsetValue_CH2, SIGNAL(valueChanged(double)), controller_fg, SLOT(offsetUpdate_CH2(double)));
        QObject::connect(timeBaseSlider, SIGNAL(valueChanged(int)), controller_iso, SLOT(setWindow(int)));
        QObject::connect(scopeAxes, SIGNAL(mouseWheel(QWheelEvent*)), controller_iso, SLOT(setVoltageRange(QWheelEvent*)));
        QObject::connect(pausedLabeL_CH1, SIGNAL(toggled(bool)), controller_iso, SLOT(pauseEnable_CH1(bool)));
        QObject::connect(pausedLabel_CH2, SIGNAL(toggled(bool)), controller_iso, SLOT(pauseEnable_CH2(bool)));
        QObject::connect(pausedLabeL_CH1, SIGNAL(toggled(bool)), pausedLabel_CH2, SLOT(setChecked(bool)));
        QObject::connect(pausedLabel_CH2, SIGNAL(toggled(bool)), pausedLabeL_CH1, SLOT(setChecked(bool)));
        QObject::connect(controller_iso, SIGNAL(disableWindow(bool)), MainWindow, SLOT(setEnabled(bool)));
        QObject::connect(scopeAxes, SIGNAL(mouseRelease(QMouseEvent*)), controller_iso, SLOT(graphMouseRelease(QMouseEvent*)));
        QObject::connect(cursorHoriCheck, SIGNAL(toggled(bool)), controller_iso, SLOT(cursorEnableHori(bool)));
        QObject::connect(cursorVertCheck, SIGNAL(toggled(bool)), controller_iso, SLOT(cursorEnableVert(bool)));
        QObject::connect(scopeAxes, SIGNAL(mouseMove(QMouseEvent*)), controller_iso, SLOT(graphMouseMove(QMouseEvent*)));
        QObject::connect(controller_iso, SIGNAL(setCursorStatsVisible(bool)), cursorStatsLabel, SLOT(setVisible(bool)));
        QObject::connect(lockPsuCheckBox, SIGNAL(toggled(bool)), psuSlider, SLOT(setDisabled(bool)));
        QObject::connect(triggerGroup, SIGNAL(toggled(bool)), controller_iso, SLOT(setTriggerEnabled(bool)));
        QObject::connect(triggerLevelValue, SIGNAL(valueChanged(double)), controller_iso, SLOT(setTriggerLevel(double)));
        QObject::connect(controller_iso, SIGNAL(singleShotTriggered(bool)), pausedLabeL_CH1, SLOT(setChecked(bool)));
        QObject::connect(singleShotCheckBox, SIGNAL(toggled(bool)), controller_iso, SLOT(setSingleShotEnabled(bool)));
        QObject::connect(triggerChannelSelect, SIGNAL(currentIndexChanged(int)), controller_iso, SLOT(setTriggerMode(int)));
        QObject::connect(acCoupledLabel_CH1, SIGNAL(toggled(bool)), controller_iso, SLOT(setAC_CH1(bool)));
        QObject::connect(acCoupledLabel_CH2, SIGNAL(toggled(bool)), controller_iso, SLOT(setAC_CH2(bool)));
        QObject::connect(multimeterGroup, SIGNAL(toggled(bool)), bufferDisplay, SLOT(multimeterIn(bool)));
        QObject::connect(bufferDisplay, SIGNAL(multimeterOut(bool)), multimeterGroup, SLOT(setEnabled(bool)));
        QObject::connect(multimeterModeSelect, SIGNAL(currentIndexChanged(int)), controller_iso, SLOT(setMultimeterType(int)));
        QObject::connect(multimeterResistanceSelect, SIGNAL(valueChanged(double)), controller_iso, SLOT(setSeriesResistance(double)));
        QObject::connect(serialDecodingCheck_CH1, SIGNAL(toggled(bool)), controller_iso, SLOT(setSerialDecodeEnabled_CH1(bool)));
        QObject::connect(serialDecodingCheck_CH2, SIGNAL(toggled(bool)), controller_iso, SLOT(setSerialDecodeEnabled_CH2(bool)));
        QObject::connect(serialDecodingCheck_CH1, SIGNAL(toggled(bool)), console1, SLOT(setVisible(bool)));
        QObject::connect(serialDecodingCheck_CH2, SIGNAL(toggled(bool)), console2, SLOT(setVisible(bool)));
        QObject::connect(controller_iso, SIGNAL(changeTimeAxis(bool)), MainWindow, SLOT(timeBaseNeedsChanging(bool)));
        QObject::connect(xyDisplayLabel, SIGNAL(toggled(bool)), controller_iso, SLOT(setXYmode(bool)));
        QObject::connect(busSnifferGroup_CH2, SIGNAL(toggled(bool)), signalGenGroup_CH2, SLOT(setDisabled(bool)));
        QObject::connect(scopeAxes, SIGNAL(mousePress(QMouseEvent*)), makeCursorsNicer, SLOT(clickDetected(QMouseEvent*)));
        QObject::connect(makeCursorsNicer, SIGNAL(tickHori(bool)), cursorHoriCheck, SLOT(setChecked(bool)));
        QObject::connect(makeCursorsNicer, SIGNAL(tickVert(bool)), cursorVertCheck, SLOT(setChecked(bool)));
        QObject::connect(makeCursorsNicer, SIGNAL(passOnSignal(QMouseEvent*)), controller_iso, SLOT(graphMousePress(QMouseEvent*)));
        QObject::connect(controller_iso, SIGNAL(sendTriggerValue(double)), triggerLevelValue, SLOT(setValue(double)));
        QObject::connect(triggerGroup, SIGNAL(toggled(bool)), controller_iso, SLOT(triggerGroupStateChange(bool)));
        QObject::connect(controller_iso, SIGNAL(disableWindow(bool)), deviceConnected, SLOT(connectedStatusChanged(bool)));
        QObject::connect(multimeterPauseCheckBox, SIGNAL(toggled(bool)), controller_iso, SLOT(pauseEnable_multimeter(bool)));
        QObject::connect(controller_iso, SIGNAL(sendVmax_CH1(double)), voltageInfoMaxDisplay_CH1, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(sendVmin_CH1(double)), voltageInfoMinDisplay_CH1, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(sendVmean_CH1(double)), voltageInfoMeanDisplay_CH1, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(sendVmax_CH2(double)), voltageInfoMaxDisplay_CH2, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(sendVmin_CH2(double)), voltageInfoMinDisplay_CH2, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(sendVmean_CH2(double)), voltageInfoMeanDisplay_CH2, SLOT(display(double)));
        QObject::connect(lockPsuCheckBox, SIGNAL(toggled(bool)), lockPsuCheckBox, SLOT(resetTimer(bool)));
        QObject::connect(lockPsuCheckBox, SIGNAL(toggled(bool)), lockPsuCheckBox, SLOT(resetTimer()));
        QObject::connect(psuSlider, SIGNAL(sliderMoved(int)), lockPsuCheckBox, SLOT(resetTimer()));
        QObject::connect(pause_LA, SIGNAL(toggled(bool)), pausedLabeL_CH1, SLOT(setChecked(bool)));
        QObject::connect(pausedLabeL_CH1, SIGNAL(toggled(bool)), pause_LA, SLOT(setChecked(bool)));
        QObject::connect(controller_fg, SIGNAL(setMaxFreq_CH2(double)), frequencyValue_CH2, SLOT(setMax(double)));
        QObject::connect(controller_fg, SIGNAL(setMinFreq_CH2(double)), frequencyValue_CH2, SLOT(setMin(double)));
        QObject::connect(frequencyValue_CH2, SIGNAL(valueChanged(double)), controller_fg, SLOT(freqUpdate_CH2(double)));
        QObject::connect(frequencyValue_CH1, SIGNAL(valueChanged(double)), controller_fg, SLOT(freqUpdate_CH1(double)));
        QObject::connect(controller_fg, SIGNAL(setMaxFreq_CH1(double)), frequencyValue_CH1, SLOT(setMax(double)));
        QObject::connect(controller_fg, SIGNAL(setMinFreq_CH1(double)), frequencyValue_CH1, SLOT(setMin(double)));
        QObject::connect(frequencyValue_CH1, SIGNAL(valueChanged(double)), frequencyValue_CH1, SLOT(changeStepping(double)));
        QObject::connect(frequencyValue_CH2, SIGNAL(valueChanged(double)), frequencyValue_CH2, SLOT(changeStepping(double)));
        QObject::connect(debugButton2, SIGNAL(clicked()), MainWindow, SLOT(reinitUsb()));
        QObject::connect(multimeterRComboBox, SIGNAL(currentIndexChanged(int)), MainWindow, SLOT(rSourceIndexChanged(int)));
        QObject::connect(controller_iso, SIGNAL(multimeterREnabled(int)), MainWindow, SLOT(rSourceIndexChanged(int)));
        QObject::connect(multimeterRComboBox, SIGNAL(currentIndexChanged(int)), controller_iso, SLOT(rSourceChanged(int)));
        QObject::connect(multimeterGroup, SIGNAL(toggled(bool)), MainWindow, SLOT(multimeterStateChange(bool)));
        QObject::connect(controller_iso, SIGNAL(multimeterRMS(double)), multimeterRmsDisplay, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(sendMultimeterLabel1(QString)), multimeterMaxLabel, SLOT(setText(QString)));
        QObject::connect(controller_iso, SIGNAL(sendMultimeterLabel3(QString)), multimeterMeanLabel, SLOT(setText(QString)));
        QObject::connect(controller_iso, SIGNAL(multimeterMax(double)), multimeterMaxDisplay, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(multimeterMean(double)), multimeterMeanDisplay, SLOT(display(double)));
        QObject::connect(controller_iso, SIGNAL(sendMultimeterLabel2(QString)), multimeterMinLabel, SLOT(setText(QString)));
        QObject::connect(controller_iso, SIGNAL(sendMultimeterLabel4(QString)), multimeterRmsLabel, SLOT(setText(QString)));
        QObject::connect(controller_iso, SIGNAL(multimeterMin(double)), multimeterMinDisplay, SLOT(display(double)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "EspoTek Labrador", nullptr));
        actionGainAuto->setText(QCoreApplication::translate("MainWindow", "&Auto", nullptr));
        actionGain0_5->setText(QCoreApplication::translate("MainWindow", "&0.5", nullptr));
        actionGain1->setText(QCoreApplication::translate("MainWindow", "&1", nullptr));
        actionGain2->setText(QCoreApplication::translate("MainWindow", "&2", nullptr));
        actionGain4->setText(QCoreApplication::translate("MainWindow", "&4", nullptr));
        actionGain8->setText(QCoreApplication::translate("MainWindow", "&8", nullptr));
        actionGain16->setText(QCoreApplication::translate("MainWindow", "16", nullptr));
        actionGain32->setText(QCoreApplication::translate("MainWindow", "&32", nullptr));
        actionGain64->setText(QCoreApplication::translate("MainWindow", "&64", nullptr));
        actionCalibrate->setText(QCoreApplication::translate("MainWindow", "Ca&librate", nullptr));
        actionCursor_Stats->setText(QCoreApplication::translate("MainWindow", "C&ursor Stats", nullptr));
        actionMax->setText(QCoreApplication::translate("MainWindow", "&Max", nullptr));
        actionMin->setText(QCoreApplication::translate("MainWindow", "M&in", nullptr));
        actionMean->setText(QCoreApplication::translate("MainWindow", "M&ean", nullptr));
        actionRMS->setText(QCoreApplication::translate("MainWindow", "&RMS", nullptr));
        actionMax_2->setText(QCoreApplication::translate("MainWindow", "&Max", nullptr));
        actionMin_2->setText(QCoreApplication::translate("MainWindow", "M&in", nullptr));
        actionMean_2->setText(QCoreApplication::translate("MainWindow", "M&ean", nullptr));
        actionRMS_2->setText(QCoreApplication::translate("MainWindow", "&RMS", nullptr));
        actionMV->setText(QCoreApplication::translate("MainWindow", "&mV", nullptr));
        actionV->setText(QCoreApplication::translate("MainWindow", "&V", nullptr));
        actionAutoV->setText(QCoreApplication::translate("MainWindow", "&Auto", nullptr));
        actionAutoI->setText(QCoreApplication::translate("MainWindow", "&Auto", nullptr));
        actionMA->setText(QCoreApplication::translate("MainWindow", "&mA", nullptr));
        actionA->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        action300->setText(QCoreApplication::translate("MainWindow", "&300", nullptr));
        action600->setText(QCoreApplication::translate("MainWindow", "&600", nullptr));
        action1200->setText(QCoreApplication::translate("MainWindow", "&1200", nullptr));
        action2400->setText(QCoreApplication::translate("MainWindow", "&2400", nullptr));
        action4800->setText(QCoreApplication::translate("MainWindow", "&4800", nullptr));
        action9600->setText(QCoreApplication::translate("MainWindow", "&9600", nullptr));
        action14400->setText(QCoreApplication::translate("MainWindow", "144&00", nullptr));
        action19200->setText(QCoreApplication::translate("MainWindow", "19200", nullptr));
        action28800->setText(QCoreApplication::translate("MainWindow", "2&8800", nullptr));
        action38400->setText(QCoreApplication::translate("MainWindow", "38400", nullptr));
        action57600->setText(QCoreApplication::translate("MainWindow", "&57600", nullptr));
        action115200->setText(QCoreApplication::translate("MainWindow", "115200", nullptr));
        action8->setText(QCoreApplication::translate("MainWindow", "&8", nullptr));
        actionNone->setText(QCoreApplication::translate("MainWindow", "&None", nullptr));
        action300_2->setText(QCoreApplication::translate("MainWindow", "&300", nullptr));
        action600_2->setText(QCoreApplication::translate("MainWindow", "&600", nullptr));
        action1200_2->setText(QCoreApplication::translate("MainWindow", "&1200", nullptr));
        action2400_2->setText(QCoreApplication::translate("MainWindow", "&2400", nullptr));
        action4800_2->setText(QCoreApplication::translate("MainWindow", "&4800", nullptr));
        action9600_2->setText(QCoreApplication::translate("MainWindow", "&9600", nullptr));
        action14400_2->setText(QCoreApplication::translate("MainWindow", "144&00", nullptr));
        action19200_2->setText(QCoreApplication::translate("MainWindow", "19200", nullptr));
        action28800_2->setText(QCoreApplication::translate("MainWindow", "2&8800", nullptr));
        action38400_2->setText(QCoreApplication::translate("MainWindow", "38400", nullptr));
        action57600_2->setText(QCoreApplication::translate("MainWindow", "&57600", nullptr));
        action115200_2->setText(QCoreApplication::translate("MainWindow", "115200", nullptr));
        action8_2->setText(QCoreApplication::translate("MainWindow", "&8", nullptr));
        actionNone_2->setText(QCoreApplication::translate("MainWindow", "&None", nullptr));
        actionForce_Square->setText(QCoreApplication::translate("MainWindow", "Force Square &Display (Not Officially Supported)", nullptr));
        actionAutomatically_Enable_Cursors->setText(QCoreApplication::translate("MainWindow", "&Enable Cursors on Click", nullptr));
        action60FPS->setText(QCoreApplication::translate("MainWindow", "&60FPS", nullptr));
        action30FPS->setText(QCoreApplication::translate("MainWindow", "&30FPS", nullptr));
        action20FPS->setText(QCoreApplication::translate("MainWindow", "&20FPS", nullptr));
        action15FPS->setText(QCoreApplication::translate("MainWindow", "&15FPS", nullptr));
        action10FPS->setText(QCoreApplication::translate("MainWindow", "1&0FPS", nullptr));
        action5FPS->setText(QCoreApplication::translate("MainWindow", "&5FPS", nullptr));
        actionAuto_Lock->setText(QCoreApplication::translate("MainWindow", "&Auto Lock", nullptr));
        actionSnap_to_Cursors->setText(QCoreApplication::translate("MainWindow", "&Snap to Cursors", nullptr));
        actionEnter_Manually->setText(QCoreApplication::translate("MainWindow", "&Enter Manually", nullptr));
        actionAutoR->setText(QCoreApplication::translate("MainWindow", "&Auto", nullptr));
        actionOhm->setText(QCoreApplication::translate("MainWindow", "\316\251", nullptr));
        actionKOhm->setText(QCoreApplication::translate("MainWindow", "&k\316\251", nullptr));
        actionAutoC->setText(QCoreApplication::translate("MainWindow", "&Auto", nullptr));
        actionNF->setText(QCoreApplication::translate("MainWindow", "&nF", nullptr));
        action_F->setText(QCoreApplication::translate("MainWindow", "\316\274&F", nullptr));
        actionLo_bw->setText(QCoreApplication::translate("MainWindow", "&lo-bw", nullptr));
        actionSingle_ep_msync->setText(QCoreApplication::translate("MainWindow", "&single-ep-msync", nullptr));
        actionSingle_ep_async->setText(QCoreApplication::translate("MainWindow", "single-&ep-async", nullptr));
        actionExportImage->setText(QCoreApplication::translate("MainWindow", "&Export Current View", nullptr));
        actionSnapshot_CH1->setText(QCoreApplication::translate("MainWindow", "&CH1", nullptr));
        actionSnapshot_CH2->setText(QCoreApplication::translate("MainWindow", "C&H2", nullptr));
        actionRecord_CH1->setText(QCoreApplication::translate("MainWindow", "&CH1", nullptr));
        actionRecord_CH2->setText(QCoreApplication::translate("MainWindow", "C&H2", nullptr));
        actionFirmware_Recovery->setText(QCoreApplication::translate("MainWindow", "&Firmware Recovery", nullptr));
        actionShow_Debug_Console->setText(QCoreApplication::translate("MainWindow", "&Show Debug Console", nullptr));
        actionDAQ_Settings->setText(QCoreApplication::translate("MainWindow", "&DAQ Settings", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
        actionOpen_DAQ_File->setText(QCoreApplication::translate("MainWindow", "DAQ &Playback", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        actionCalibrate_2->setText(QCoreApplication::translate("MainWindow", "&Calibrate", nullptr));
        actionOffset_is_A0_from_Fourier_Series->setText(QCoreApplication::translate("MainWindow", "Offset is A0 from Fourier Series", nullptr));
        actionFrom_GND->setText(QCoreApplication::translate("MainWindow", "&Lowest Point from GND", nullptr));
        actionMean_Point_from_GND->setText(QCoreApplication::translate("MainWindow", "&Mean Point from GND", nullptr));
        actionSerial->setText(QCoreApplication::translate("MainWindow", "&Serial", nullptr));
        actionI2C->setText(QCoreApplication::translate("MainWindow", "&I2C", nullptr));
        actionShow_Range_Dialog_on_Main_Page->setText(QCoreApplication::translate("MainWindow", "&Show Range Dialog on Main Page", nullptr));
        actionEven->setText(QCoreApplication::translate("MainWindow", "&Even", nullptr));
        actionOdd->setText(QCoreApplication::translate("MainWindow", "&Odd", nullptr));
        actionEven_2->setText(QCoreApplication::translate("MainWindow", "&Even", nullptr));
        actionOdd_2->setText(QCoreApplication::translate("MainWindow", "&Odd", nullptr));
        actionPinout->setText(QCoreApplication::translate("MainWindow", "&Pinout", nullptr));
        actionDocumentation->setText(QCoreApplication::translate("MainWindow", "&Documentation", nullptr));
        actionHexDisplay->setText(QCoreApplication::translate("MainWindow", "Hex Display", nullptr));
        actionHexDisplay_2->setText(QCoreApplication::translate("MainWindow", "Hex Display", nullptr));
        actionHide_Widget_Oscilloscope->setText(QCoreApplication::translate("MainWindow", "Hide Widget", nullptr));
        actionHide_Widget_SignalGen->setText(QCoreApplication::translate("MainWindow", "Hide Widget", nullptr));
        actionHide_Widget_Multimeter->setText(QCoreApplication::translate("MainWindow", "Hide Widget", nullptr));
        actionHide_Widget_PowerSupply->setText(QCoreApplication::translate("MainWindow", "Hide Widget", nullptr));
        actionHide_Widget_LogicAnalyzer->setText(QCoreApplication::translate("MainWindow", "Hide Widget", nullptr));
        actionDark_Mode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        actionFrequency_Spectrum->setText(QCoreApplication::translate("MainWindow", "Frequency Spectrum", nullptr));
        realTimeButton->setText(QCoreApplication::translate("MainWindow", "Return to Real Time Display", nullptr));
        cursorStatsLabel->setText(QCoreApplication::translate("MainWindow", "cursorStatsLabel", nullptr));
        controller_fg->setText(QCoreApplication::translate("MainWindow", "SALUTON MI ESTAS FUNCTION GENERATOR CONTROLLER", nullptr));
        deviceConnected->setText(QCoreApplication::translate("MainWindow", "Device Not Connected!", nullptr));
        scopeGroup_CH1->setTitle(QCoreApplication::translate("MainWindow", "Oscilloscope CH&1", nullptr));
        pausedLabeL_CH1->setText(QCoreApplication::translate("MainWindow", "Paused", nullptr));
        acCoupledLabel_CH1->setText(QCoreApplication::translate("MainWindow", "AC Coupled", nullptr));
        filterLabel_CH1->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        doubleSampleLabel->setText(QCoreApplication::translate("MainWindow", "Double Sample Rate", nullptr));
        hideCH1Box->setText(QCoreApplication::translate("MainWindow", "Hide", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        offsetSpinBox_CH1->setSuffix(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Attenuation", nullptr));
        attenuationComboBox_CH1->setItemText(0, QCoreApplication::translate("MainWindow", "1x", nullptr));
        attenuationComboBox_CH1->setItemText(1, QCoreApplication::translate("MainWindow", "5x", nullptr));
        attenuationComboBox_CH1->setItemText(2, QCoreApplication::translate("MainWindow", "10x", nullptr));

        voltageInfoMaxLabel_CH1->setText(QCoreApplication::translate("MainWindow", " Max", nullptr));
        voltageInfoMinLabel_CH1->setText(QCoreApplication::translate("MainWindow", " Min", nullptr));
        VoltageInfoMeanLabel_CH1->setText(QCoreApplication::translate("MainWindow", " Mean", nullptr));
        voltageInfoRmsLabel_CH1->setText(QCoreApplication::translate("MainWindow", " RMS", nullptr));
        scopeGroup_CH2->setTitle(QCoreApplication::translate("MainWindow", "Oscilloscope CH&2", nullptr));
        pausedLabel_CH2->setText(QCoreApplication::translate("MainWindow", "Paused", nullptr));
        acCoupledLabel_CH2->setText(QCoreApplication::translate("MainWindow", "AC Coupled", nullptr));
        filterLabel_CH2->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        xyDisplayLabel->setText(QCoreApplication::translate("MainWindow", "X-Y Display", nullptr));
        hideCH2Box->setText(QCoreApplication::translate("MainWindow", "Hide", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        offsetSpinBox_CH2->setSuffix(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Attenuation", nullptr));
        attenuationComboBox_CH2->setItemText(0, QCoreApplication::translate("MainWindow", "1x", nullptr));
        attenuationComboBox_CH2->setItemText(1, QCoreApplication::translate("MainWindow", "5x", nullptr));
        attenuationComboBox_CH2->setItemText(2, QCoreApplication::translate("MainWindow", "10x", nullptr));

        voltageInfoMaxLabel_CH2->setText(QCoreApplication::translate("MainWindow", " Max", nullptr));
        voltageInfoMinLabel_CH2->setText(QCoreApplication::translate("MainWindow", " Min", nullptr));
        VoltageInfoMeanLabel_CH2->setText(QCoreApplication::translate("MainWindow", " Mean", nullptr));
        voltageInfoRmsLabel_CH2->setText(QCoreApplication::translate("MainWindow", " RMS", nullptr));
        cursorGroup->setTitle(QCoreApplication::translate("MainWindow", "Cursor", nullptr));
        cursorHoriCheck->setText(QCoreApplication::translate("MainWindow", "Horizontal", nullptr));
        cursorVertCheck->setText(QCoreApplication::translate("MainWindow", "Vertical", nullptr));
        makeCursorsNicer->setText(QCoreApplication::translate("MainWindow", "CURSOR ENABLER", nullptr));
        triggerGroup->setTitle(QCoreApplication::translate("MainWindow", "Trigger", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        triggerChannelSelect->setItemText(0, QCoreApplication::translate("MainWindow", "CH1 (Rising)", nullptr));
        triggerChannelSelect->setItemText(1, QCoreApplication::translate("MainWindow", "CH1 (Falling)", nullptr));
        triggerChannelSelect->setItemText(2, QCoreApplication::translate("MainWindow", "CH2 (Rising)", nullptr));
        triggerChannelSelect->setItemText(3, QCoreApplication::translate("MainWindow", "CH2 (Falling)", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        singleShotCheckBox->setText(QCoreApplication::translate("MainWindow", "Single Shot", nullptr));
        multimeterGroup->setTitle(QCoreApplication::translate("MainWindow", "Multimeter++", nullptr));
        multimeterPauseCheckBox->setText(QCoreApplication::translate("MainWindow", "Paused", nullptr));
        multimeterModeLabel->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        multimeterModeSelect->setItemText(0, QCoreApplication::translate("MainWindow", "V", nullptr));
        multimeterModeSelect->setItemText(1, QCoreApplication::translate("MainWindow", "I", nullptr));
        multimeterModeSelect->setItemText(2, QCoreApplication::translate("MainWindow", "R", nullptr));
        multimeterModeSelect->setItemText(3, QCoreApplication::translate("MainWindow", "C", nullptr));

        multimeterResistanceLabel->setText(QCoreApplication::translate("MainWindow", "Reference Resistance", nullptr));
        multimeterResistanceSelect->setSuffix(QCoreApplication::translate("MainWindow", "\316\251", nullptr));
        multimeterRLabel->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        multimeterRComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Signal Gen CH2", nullptr));
        multimeterRComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Power Supply", nullptr));

        multimeterMinLabel->setText(QCoreApplication::translate("MainWindow", " Min", nullptr));
        multimeterMaxLabel->setText(QCoreApplication::translate("MainWindow", " Max", nullptr));
        multimeterMeanLabel->setText(QCoreApplication::translate("MainWindow", " Mean", nullptr));
        multimeterRmsLabel->setText(QCoreApplication::translate("MainWindow", " RMS", nullptr));
        signalGenGroup_CH1->setTitle(QCoreApplication::translate("MainWindow", "Signal Gen CH1", nullptr));
        frequencyLabel_CH1->setText(QCoreApplication::translate("MainWindow", "Frequency", nullptr));
        amplitudeValue_CH1->setSuffix(QCoreApplication::translate("MainWindow", "V", nullptr));
        amplitudeLabel_CH1->setText(QCoreApplication::translate("MainWindow", "Amplitude", nullptr));
        waveformLabel_CH1->setText(QCoreApplication::translate("MainWindow", "Waveform", nullptr));
        dcOffsetLabel_CH1->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        dcOffsetValue_CH1->setSuffix(QCoreApplication::translate("MainWindow", "V", nullptr));
        signalGenGroup_CH2->setTitle(QCoreApplication::translate("MainWindow", "Signal Gen CH2", nullptr));
        amplitudeLabel_CH2->setText(QCoreApplication::translate("MainWindow", "Amplitude", nullptr));
        waveformLabel_CH2->setText(QCoreApplication::translate("MainWindow", "Waveform", nullptr));
        frequencyLabel_CH2->setText(QCoreApplication::translate("MainWindow", "Frequency", nullptr));
        dcOffsetLabel_CH2->setText(QCoreApplication::translate("MainWindow", "Offset", nullptr));
        amplitudeValue_CH2->setSuffix(QCoreApplication::translate("MainWindow", "V", nullptr));
        dcOffsetValue_CH2->setSuffix(QCoreApplication::translate("MainWindow", "V", nullptr));
        controller_iso->setText(QCoreApplication::translate("MainWindow", "SALUTON MI ESTAS ISO DRIVER", nullptr));
        psuGroup->setTitle(QCoreApplication::translate("MainWindow", "PSU", nullptr));
        lockPsuCheckBox->setText(QCoreApplication::translate("MainWindow", "Lock PSU", nullptr));
        busSifferGroup_CH1->setTitle(QCoreApplication::translate("MainWindow", "Logic Analy&zer CH1", nullptr));
        pause_LA->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        serialDecodingCheck_CH1->setTitle(QCoreApplication::translate("MainWindow", "Serial Decoding", nullptr));
        busSnifferGroup_CH2->setTitle(QCoreApplication::translate("MainWindow", "Logic Analyzer CH&2", nullptr));
        serialDecodingCheck_CH2->setTitle(QCoreApplication::translate("MainWindow", "Serial Decoding", nullptr));
        digitalOutputGroup->setTitle(QCoreApplication::translate("MainWindow", "Digital Output", nullptr));
        digitalOutCheckbox_CH3->setText(QCoreApplication::translate("MainWindow", "Pin 3", nullptr));
        digitalOutCheckbox_CH2->setText(QCoreApplication::translate("MainWindow", "Pin 2", nullptr));
        digitalOutCheckbox_CH1->setText(QCoreApplication::translate("MainWindow", "Pin 1", nullptr));
        digitalOutCheckbox_CH4->setText(QCoreApplication::translate("MainWindow", "Pin 4", nullptr));
        debugButton1->setText(QCoreApplication::translate("MainWindow", "Debug!", nullptr));
        debugButton2->setText(QCoreApplication::translate("MainWindow", "ReinitUsb()", nullptr));
        kickstartIsoButton->setText(QCoreApplication::translate("MainWindow", "kickstartIso()", nullptr));
        debugButton3->setText(QCoreApplication::translate("MainWindow", "Jump to Bootloader", nullptr));
        bufferDisplay->setText(QCoreApplication::translate("MainWindow", "BUFFER IMAGE HERE", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTake_Snapshot->setTitle(QCoreApplication::translate("MainWindow", "&Take Snapshot", nullptr));
        menuRecord->setTitle(QCoreApplication::translate("MainWindow", "&Enable DAQ", nullptr));
        menuOscilloscope_2->setTitle(QCoreApplication::translate("MainWindow", "Oscilloscope", nullptr));
        menuGain_2->setTitle(QCoreApplication::translate("MainWindow", "&Gain", nullptr));
        menuCH1_Stats->setTitle(QCoreApplication::translate("MainWindow", "&CH1 Stats", nullptr));
        menuCH2_Stats->setTitle(QCoreApplication::translate("MainWindow", "C&H2 Stats", nullptr));
        menuFrame_rate->setTitle(QCoreApplication::translate("MainWindow", "&Frame rate", nullptr));
        menuRange->setTitle(QCoreApplication::translate("MainWindow", "&Range", nullptr));
        menuMultimeter_2->setTitle(QCoreApplication::translate("MainWindow", "&Multimeter", nullptr));
        menuV_2->setTitle(QCoreApplication::translate("MainWindow", "&Range (V)", nullptr));
        menuI_2->setTitle(QCoreApplication::translate("MainWindow", "Range (&I)", nullptr));
        menuRange_R->setTitle(QCoreApplication::translate("MainWindow", "Ra&nge (R)", nullptr));
        menuRange_C->setTitle(QCoreApplication::translate("MainWindow", "Range (&C)", nullptr));
        menuBus_Sniffer->setTitle(QCoreApplication::translate("MainWindow", "&Logic Analyzer", nullptr));
        menuUART_1->setTitle(QCoreApplication::translate("MainWindow", "&UART 1", nullptr));
        menuBaud_Rate->setTitle(QCoreApplication::translate("MainWindow", "&Baud Rate", nullptr));
        menuParity_Bit->setTitle(QCoreApplication::translate("MainWindow", "&Parity Bit", nullptr));
        menuData_Bits->setTitle(QCoreApplication::translate("MainWindow", "&Data Bits", nullptr));
        menuUART_2->setTitle(QCoreApplication::translate("MainWindow", "UART &2", nullptr));
        menuBaud_Rate_2->setTitle(QCoreApplication::translate("MainWindow", "&Baud Rate", nullptr));
        menuData_Bits_2->setTitle(QCoreApplication::translate("MainWindow", "&Data Bits", nullptr));
        menuParity_Bit_2->setTitle(QCoreApplication::translate("MainWindow", "&Parity Bit", nullptr));
        menuProtocol->setTitle(QCoreApplication::translate("MainWindow", "&Protocol", nullptr));
        menuPower_Supply->setTitle(QCoreApplication::translate("MainWindow", "Power S&upply", nullptr));
        menuConnection_Type->setTitle(QCoreApplication::translate("MainWindow", "&Connection Type", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuSignal_Generator->setTitle(QCoreApplication::translate("MainWindow", "Signal &Generator", nullptr));
        menuOffset_Type->setTitle(QCoreApplication::translate("MainWindow", "&Offset Type", nullptr));
        menuAccessibility->setTitle(QCoreApplication::translate("MainWindow", "Accessibility", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
