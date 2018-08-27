/********************************************************************************
** Form generated from reading UI file 'mSurgical.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSURGICAL_H
#define UI_MSURGICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mSurgicalClass
{
public:
    QAction *actionLearn_Method;
    QAction *actionButtons;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *startBackButton;
    QStackedWidget *screensStackWidget;
    QWidget *welcomePage;
    QVBoxLayout *verticalLayout_3;
    QLabel *pressStartLabel;
    QWidget *menuPage;
    QVBoxLayout *verticalLayout_2;
    QPushButton *goToORButton;
    QPushButton *learnButton;
    QPushButton *hiscoresButton;
    QPushButton *changeSurgeonButton;
    QWidget *ORPage;
    QGridLayout *gridLayout_4;
    QLabel *nextLabel_3;
    QLabel *nextLabel;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QLabel *buttonSeqLabel0;
    QLabel *nextLabel_2;
    QFrame *line;
    QFrame *line_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *buttonSeqLabel1;
    QLabel *nextLabel_5;
    QWidget *monaLaserWidget;
    QGridLayout *gridLayout_9;
    QLabel *monaLaser;
    QLineEdit *tableSurgeryNeededEdit;
    QLabel *nextLabel_6;
    QWidget *tableWidget;
    QGridLayout *gridLayout_7;
    QLabel *tablePatient;
    QWidget *nextWidget;
    QGridLayout *gridLayout_8;
    QLabel *nextPatient;
    QLabel *nextLabel_4;
    QLineEdit *nextSurgeryNeededEdit;
    QProgressBar *tableProgressBar;
    QLabel *scoreLabel;
    QSpinBox *scoreBox;
    QWidget *learnPage;
    QGridLayout *gridLayout_3;
    QPushButton *surgeryPushButton1;
    QPushButton *surgeryPushButton2;
    QPushButton *surgeryPushButton3;
    QPushButton *surgeryPushButton4;
    QPushButton *surgeryPushButton5;
    QPushButton *surgeryPushButton6;
    QPushButton *surgeryPushButton7;
    QPushButton *surgeryPushButton8;
    QPushButton *surgeryPushButton9;
    QPushButton *surgeryPushButton10;
    QPushButton *surgeryPushButton11;
    QPushButton *surgeryPushButton12;
    QPushButton *surgeryPushButton13;
    QPushButton *surgeryPushButton14;
    QPushButton *surgeryPushButton15;
    QPushButton *surgeryPushButton16;
    QWidget *hiscoresPage;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *firstNameLineEdit;
    QLineEdit *secondNameLineEdit;
    QLineEdit *thirdNameLineEdit;
    QLineEdit *firstScoreLineEdit;
    QLineEdit *secondScoreLineEdit;
    QLineEdit *thirdScoreLineEdit;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mSurgicalClass)
    {
        if (mSurgicalClass->objectName().isEmpty())
            mSurgicalClass->setObjectName(QStringLiteral("mSurgicalClass"));
        mSurgicalClass->resize(600, 429);
        actionLearn_Method = new QAction(mSurgicalClass);
        actionLearn_Method->setObjectName(QStringLiteral("actionLearn_Method"));
        actionLearn_Method->setCheckable(false);
        actionButtons = new QAction(mSurgicalClass);
        actionButtons->setObjectName(QStringLiteral("actionButtons"));
        centralWidget = new QWidget(mSurgicalClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        startBackButton = new QPushButton(centralWidget);
        startBackButton->setObjectName(QStringLiteral("startBackButton"));

        gridLayout->addWidget(startBackButton, 1, 0, 1, 1, Qt::AlignHCenter);

        screensStackWidget = new QStackedWidget(centralWidget);
        screensStackWidget->setObjectName(QStringLiteral("screensStackWidget"));
        welcomePage = new QWidget();
        welcomePage->setObjectName(QStringLiteral("welcomePage"));
        verticalLayout_3 = new QVBoxLayout(welcomePage);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pressStartLabel = new QLabel(welcomePage);
        pressStartLabel->setObjectName(QStringLiteral("pressStartLabel"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        pressStartLabel->setFont(font);

        verticalLayout_3->addWidget(pressStartLabel, 0, Qt::AlignHCenter);

        screensStackWidget->addWidget(welcomePage);
        menuPage = new QWidget();
        menuPage->setObjectName(QStringLiteral("menuPage"));
        verticalLayout_2 = new QVBoxLayout(menuPage);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        goToORButton = new QPushButton(menuPage);
        goToORButton->setObjectName(QStringLiteral("goToORButton"));
        goToORButton->setMinimumSize(QSize(100, 40));

        verticalLayout_2->addWidget(goToORButton, 0, Qt::AlignHCenter);

        learnButton = new QPushButton(menuPage);
        learnButton->setObjectName(QStringLiteral("learnButton"));
        learnButton->setMinimumSize(QSize(100, 40));

        verticalLayout_2->addWidget(learnButton, 0, Qt::AlignHCenter);

        hiscoresButton = new QPushButton(menuPage);
        hiscoresButton->setObjectName(QStringLiteral("hiscoresButton"));
        hiscoresButton->setMinimumSize(QSize(100, 40));

        verticalLayout_2->addWidget(hiscoresButton, 0, Qt::AlignHCenter);

        changeSurgeonButton = new QPushButton(menuPage);
        changeSurgeonButton->setObjectName(QStringLiteral("changeSurgeonButton"));
        changeSurgeonButton->setMinimumSize(QSize(100, 40));

        verticalLayout_2->addWidget(changeSurgeonButton, 0, Qt::AlignHCenter);

        screensStackWidget->addWidget(menuPage);
        ORPage = new QWidget();
        ORPage->setObjectName(QStringLiteral("ORPage"));
        gridLayout_4 = new QGridLayout(ORPage);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        nextLabel_3 = new QLabel(ORPage);
        nextLabel_3->setObjectName(QStringLiteral("nextLabel_3"));
        QFont font1;
        font1.setPointSize(30);
        nextLabel_3->setFont(font1);

        gridLayout_4->addWidget(nextLabel_3, 1, 5, 1, 2, Qt::AlignHCenter);

        nextLabel = new QLabel(ORPage);
        nextLabel->setObjectName(QStringLiteral("nextLabel"));
        nextLabel->setFont(font1);

        gridLayout_4->addWidget(nextLabel, 1, 0, 1, 1, Qt::AlignHCenter);

        frame = new QFrame(ORPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(80, 80));
        frame->setStyleSheet(QStringLiteral("background-color:white"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(3);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        buttonSeqLabel0 = new QLabel(frame);
        buttonSeqLabel0->setObjectName(QStringLiteral("buttonSeqLabel0"));
        QFont font2;
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setWeight(75);
        buttonSeqLabel0->setFont(font2);

        gridLayout_5->addWidget(buttonSeqLabel0, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout_4->addWidget(frame, 5, 5, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        nextLabel_2 = new QLabel(ORPage);
        nextLabel_2->setObjectName(QStringLiteral("nextLabel_2"));
        nextLabel_2->setFont(font1);

        gridLayout_4->addWidget(nextLabel_2, 1, 2, 1, 2, Qt::AlignHCenter);

        line = new QFrame(ORPage);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::VLine);

        gridLayout_4->addWidget(line, 1, 1, 5, 1);

        line_2 = new QFrame(ORPage);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::VLine);

        gridLayout_4->addWidget(line_2, 1, 4, 5, 1);

        frame_2 = new QFrame(ORPage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMinimumSize(QSize(80, 80));
        frame_2->setStyleSheet(QStringLiteral("background-color:white"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(3);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        buttonSeqLabel1 = new QLabel(frame_2);
        buttonSeqLabel1->setObjectName(QStringLiteral("buttonSeqLabel1"));
        buttonSeqLabel1->setFont(font2);

        gridLayout_6->addWidget(buttonSeqLabel1, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        gridLayout_4->addWidget(frame_2, 5, 6, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        nextLabel_5 = new QLabel(ORPage);
        nextLabel_5->setObjectName(QStringLiteral("nextLabel_5"));
        QFont font3;
        font3.setPointSize(20);
        nextLabel_5->setFont(font3);

        gridLayout_4->addWidget(nextLabel_5, 4, 2, 1, 2, Qt::AlignHCenter);

        monaLaserWidget = new QWidget(ORPage);
        monaLaserWidget->setObjectName(QStringLiteral("monaLaserWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(monaLaserWidget->sizePolicy().hasHeightForWidth());
        monaLaserWidget->setSizePolicy(sizePolicy);
        gridLayout_9 = new QGridLayout(monaLaserWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        monaLaser = new QLabel(monaLaserWidget);
        monaLaser->setObjectName(QStringLiteral("monaLaser"));
        monaLaser->setPixmap(QPixmap(QString::fromUtf8("../../resource/monalaser.png")));
        monaLaser->setScaledContents(true);

        gridLayout_9->addWidget(monaLaser, 0, 0, 1, 1);


        gridLayout_4->addWidget(monaLaserWidget, 3, 5, 1, 2);

        tableSurgeryNeededEdit = new QLineEdit(ORPage);
        tableSurgeryNeededEdit->setObjectName(QStringLiteral("tableSurgeryNeededEdit"));
        tableSurgeryNeededEdit->setMinimumSize(QSize(186, 40));
        tableSurgeryNeededEdit->setReadOnly(true);

        gridLayout_4->addWidget(tableSurgeryNeededEdit, 5, 2, 1, 2);

        nextLabel_6 = new QLabel(ORPage);
        nextLabel_6->setObjectName(QStringLiteral("nextLabel_6"));
        nextLabel_6->setFont(font3);

        gridLayout_4->addWidget(nextLabel_6, 4, 5, 1, 2, Qt::AlignHCenter);

        tableWidget = new QWidget(ORPage);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(tableWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        tablePatient = new QLabel(tableWidget);
        tablePatient->setObjectName(QStringLiteral("tablePatient"));
        tablePatient->setPixmap(QPixmap(QString::fromUtf8("../../resource/patient.png")));
        tablePatient->setScaledContents(true);

        gridLayout_7->addWidget(tablePatient, 0, 0, 1, 1);


        gridLayout_4->addWidget(tableWidget, 3, 2, 1, 2);

        nextWidget = new QWidget(ORPage);
        nextWidget->setObjectName(QStringLiteral("nextWidget"));
        sizePolicy.setHeightForWidth(nextWidget->sizePolicy().hasHeightForWidth());
        nextWidget->setSizePolicy(sizePolicy);
        nextWidget->setMinimumSize(QSize(121, 141));
        gridLayout_8 = new QGridLayout(nextWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        nextPatient = new QLabel(nextWidget);
        nextPatient->setObjectName(QStringLiteral("nextPatient"));
        nextPatient->setPixmap(QPixmap(QString::fromUtf8("../../resource/patient.png")));
        nextPatient->setScaledContents(true);

        gridLayout_8->addWidget(nextPatient, 0, 0, 1, 1);


        gridLayout_4->addWidget(nextWidget, 3, 0, 1, 1);

        nextLabel_4 = new QLabel(ORPage);
        nextLabel_4->setObjectName(QStringLiteral("nextLabel_4"));
        nextLabel_4->setFont(font3);

        gridLayout_4->addWidget(nextLabel_4, 4, 0, 1, 1, Qt::AlignHCenter);

        nextSurgeryNeededEdit = new QLineEdit(ORPage);
        nextSurgeryNeededEdit->setObjectName(QStringLiteral("nextSurgeryNeededEdit"));
        nextSurgeryNeededEdit->setMinimumSize(QSize(182, 40));
        nextSurgeryNeededEdit->setReadOnly(true);

        gridLayout_4->addWidget(nextSurgeryNeededEdit, 5, 0, 1, 1);

        tableProgressBar = new QProgressBar(ORPage);
        tableProgressBar->setObjectName(QStringLiteral("tableProgressBar"));
        tableProgressBar->setStyleSheet(QStringLiteral(""));
        tableProgressBar->setMaximum(10);
        tableProgressBar->setValue(10);
        tableProgressBar->setAlignment(Qt::AlignCenter);
        tableProgressBar->setInvertedAppearance(false);
        tableProgressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_4->addWidget(tableProgressBar, 2, 2, 1, 2);

        scoreLabel = new QLabel(ORPage);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        scoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(scoreLabel, 0, 5, 1, 1);

        scoreBox = new QSpinBox(ORPage);
        scoreBox->setObjectName(QStringLiteral("scoreBox"));
        scoreBox->setAlignment(Qt::AlignCenter);
        scoreBox->setReadOnly(true);
        scoreBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        scoreBox->setMaximum(999999999);

        gridLayout_4->addWidget(scoreBox, 0, 6, 1, 1);

        screensStackWidget->addWidget(ORPage);
        learnPage = new QWidget();
        learnPage->setObjectName(QStringLiteral("learnPage"));
        gridLayout_3 = new QGridLayout(learnPage);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        surgeryPushButton1 = new QPushButton(learnPage);
        surgeryPushButton1->setObjectName(QStringLiteral("surgeryPushButton1"));

        gridLayout_3->addWidget(surgeryPushButton1, 0, 0, 1, 1);

        surgeryPushButton2 = new QPushButton(learnPage);
        surgeryPushButton2->setObjectName(QStringLiteral("surgeryPushButton2"));

        gridLayout_3->addWidget(surgeryPushButton2, 0, 1, 1, 1);

        surgeryPushButton3 = new QPushButton(learnPage);
        surgeryPushButton3->setObjectName(QStringLiteral("surgeryPushButton3"));

        gridLayout_3->addWidget(surgeryPushButton3, 1, 0, 1, 1);

        surgeryPushButton4 = new QPushButton(learnPage);
        surgeryPushButton4->setObjectName(QStringLiteral("surgeryPushButton4"));

        gridLayout_3->addWidget(surgeryPushButton4, 1, 1, 1, 1);

        surgeryPushButton5 = new QPushButton(learnPage);
        surgeryPushButton5->setObjectName(QStringLiteral("surgeryPushButton5"));

        gridLayout_3->addWidget(surgeryPushButton5, 2, 0, 1, 1);

        surgeryPushButton6 = new QPushButton(learnPage);
        surgeryPushButton6->setObjectName(QStringLiteral("surgeryPushButton6"));

        gridLayout_3->addWidget(surgeryPushButton6, 2, 1, 1, 1);

        surgeryPushButton7 = new QPushButton(learnPage);
        surgeryPushButton7->setObjectName(QStringLiteral("surgeryPushButton7"));

        gridLayout_3->addWidget(surgeryPushButton7, 3, 0, 1, 1);

        surgeryPushButton8 = new QPushButton(learnPage);
        surgeryPushButton8->setObjectName(QStringLiteral("surgeryPushButton8"));

        gridLayout_3->addWidget(surgeryPushButton8, 3, 1, 1, 1);

        surgeryPushButton9 = new QPushButton(learnPage);
        surgeryPushButton9->setObjectName(QStringLiteral("surgeryPushButton9"));

        gridLayout_3->addWidget(surgeryPushButton9, 4, 0, 1, 1);

        surgeryPushButton10 = new QPushButton(learnPage);
        surgeryPushButton10->setObjectName(QStringLiteral("surgeryPushButton10"));

        gridLayout_3->addWidget(surgeryPushButton10, 4, 1, 1, 1);

        surgeryPushButton11 = new QPushButton(learnPage);
        surgeryPushButton11->setObjectName(QStringLiteral("surgeryPushButton11"));

        gridLayout_3->addWidget(surgeryPushButton11, 5, 0, 1, 1);

        surgeryPushButton12 = new QPushButton(learnPage);
        surgeryPushButton12->setObjectName(QStringLiteral("surgeryPushButton12"));

        gridLayout_3->addWidget(surgeryPushButton12, 5, 1, 1, 1);

        surgeryPushButton13 = new QPushButton(learnPage);
        surgeryPushButton13->setObjectName(QStringLiteral("surgeryPushButton13"));

        gridLayout_3->addWidget(surgeryPushButton13, 6, 0, 1, 1);

        surgeryPushButton14 = new QPushButton(learnPage);
        surgeryPushButton14->setObjectName(QStringLiteral("surgeryPushButton14"));

        gridLayout_3->addWidget(surgeryPushButton14, 6, 1, 1, 1);

        surgeryPushButton15 = new QPushButton(learnPage);
        surgeryPushButton15->setObjectName(QStringLiteral("surgeryPushButton15"));

        gridLayout_3->addWidget(surgeryPushButton15, 7, 0, 1, 1);

        surgeryPushButton16 = new QPushButton(learnPage);
        surgeryPushButton16->setObjectName(QStringLiteral("surgeryPushButton16"));

        gridLayout_3->addWidget(surgeryPushButton16, 7, 1, 1, 1);

        screensStackWidget->addWidget(learnPage);
        hiscoresPage = new QWidget();
        hiscoresPage->setObjectName(QStringLiteral("hiscoresPage"));
        verticalLayout = new QVBoxLayout(hiscoresPage);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(hiscoresPage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        firstNameLineEdit = new QLineEdit(groupBox);
        firstNameLineEdit->setObjectName(QStringLiteral("firstNameLineEdit"));
        firstNameLineEdit->setAlignment(Qt::AlignCenter);
        firstNameLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(firstNameLineEdit, 0, 0, 1, 1);

        secondNameLineEdit = new QLineEdit(groupBox);
        secondNameLineEdit->setObjectName(QStringLiteral("secondNameLineEdit"));
        secondNameLineEdit->setAlignment(Qt::AlignCenter);
        secondNameLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(secondNameLineEdit, 1, 0, 1, 1);

        thirdNameLineEdit = new QLineEdit(groupBox);
        thirdNameLineEdit->setObjectName(QStringLiteral("thirdNameLineEdit"));
        thirdNameLineEdit->setAlignment(Qt::AlignCenter);
        thirdNameLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(thirdNameLineEdit, 2, 0, 1, 1);

        firstScoreLineEdit = new QLineEdit(groupBox);
        firstScoreLineEdit->setObjectName(QStringLiteral("firstScoreLineEdit"));
        firstScoreLineEdit->setAlignment(Qt::AlignCenter);
        firstScoreLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(firstScoreLineEdit, 0, 1, 1, 1);

        secondScoreLineEdit = new QLineEdit(groupBox);
        secondScoreLineEdit->setObjectName(QStringLiteral("secondScoreLineEdit"));
        secondScoreLineEdit->setAlignment(Qt::AlignCenter);
        secondScoreLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(secondScoreLineEdit, 1, 1, 1, 1);

        thirdScoreLineEdit = new QLineEdit(groupBox);
        thirdScoreLineEdit->setObjectName(QStringLiteral("thirdScoreLineEdit"));
        thirdScoreLineEdit->setAlignment(Qt::AlignCenter);
        thirdScoreLineEdit->setReadOnly(true);

        gridLayout_2->addWidget(thirdScoreLineEdit, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        screensStackWidget->addWidget(hiscoresPage);

        gridLayout->addWidget(screensStackWidget, 0, 0, 1, 1);

        mSurgicalClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mSurgicalClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        mSurgicalClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mSurgicalClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mSurgicalClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mSurgicalClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mSurgicalClass->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionButtons);
        menuOptions->addAction(actionLearn_Method);

        retranslateUi(mSurgicalClass);

        screensStackWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mSurgicalClass);
    } // setupUi

    void retranslateUi(QMainWindow *mSurgicalClass)
    {
        mSurgicalClass->setWindowTitle(QApplication::translate("mSurgicalClass", "mSurgical", nullptr));
        actionLearn_Method->setText(QApplication::translate("mSurgicalClass", "Learn Method", nullptr));
        actionButtons->setText(QApplication::translate("mSurgicalClass", "Buttons", nullptr));
        startBackButton->setText(QApplication::translate("mSurgicalClass", "Start", nullptr));
        pressStartLabel->setText(QApplication::translate("mSurgicalClass", "Press Start Button Below", nullptr));
#ifndef QT_NO_TOOLTIP
        goToORButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        goToORButton->setText(QApplication::translate("mSurgicalClass", "GO TO OR", nullptr));
#ifndef QT_NO_TOOLTIP
        learnButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        learnButton->setText(QApplication::translate("mSurgicalClass", "LEARN", nullptr));
#ifndef QT_NO_TOOLTIP
        hiscoresButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        hiscoresButton->setText(QApplication::translate("mSurgicalClass", "HIGH SCORES", nullptr));
#ifndef QT_NO_TOOLTIP
        changeSurgeonButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        changeSurgeonButton->setText(QApplication::translate("mSurgicalClass", "CHANGE SURGEON", nullptr));
        nextLabel_3->setText(QApplication::translate("mSurgicalClass", "Mona Laser", nullptr));
        nextLabel->setText(QApplication::translate("mSurgicalClass", "Next", nullptr));
        buttonSeqLabel0->setText(QString());
        nextLabel_2->setText(QApplication::translate("mSurgicalClass", "On Table", nullptr));
        buttonSeqLabel1->setText(QString());
        nextLabel_5->setText(QApplication::translate("mSurgicalClass", "Surgery Needed", nullptr));
        monaLaser->setText(QString());
        nextLabel_6->setText(QApplication::translate("mSurgicalClass", "Button Sequence", nullptr));
        tablePatient->setText(QString());
        nextPatient->setText(QString());
        nextLabel_4->setText(QApplication::translate("mSurgicalClass", "Surgery Needed", nullptr));
        tableProgressBar->setFormat(QApplication::translate("mSurgicalClass", "%v", nullptr));
        scoreLabel->setText(QApplication::translate("mSurgicalClass", "Score:", nullptr));
        surgeryPushButton1->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton2->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton3->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton4->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton5->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton6->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton7->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton8->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton9->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton10->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton11->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton12->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton13->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton14->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton15->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        surgeryPushButton16->setText(QApplication::translate("mSurgicalClass", "?", nullptr));
        groupBox->setTitle(QApplication::translate("mSurgicalClass", "Best Doctors", nullptr));
        menuOptions->setTitle(QApplication::translate("mSurgicalClass", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mSurgicalClass: public Ui_mSurgicalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSURGICAL_H
