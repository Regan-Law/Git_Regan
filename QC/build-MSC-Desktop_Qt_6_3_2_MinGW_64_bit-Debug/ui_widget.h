/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <lunarcalendarwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *ckShowLunar;
    QSpacerItem *horizontalSpacer_2;
    QLabel *todaysweather;
    QLabel *weatherinformation;
    QSpacerItem *horizontalSpacer;
    LunarCalendarWidget *widget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *editcase;
    QPushButton *deletecase;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *caselabel;
    QTextBrowser *caseinfo;
    QTextEdit *searchinfo;
    QLabel *searchlabel;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *search;
    QPushButton *next;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *timelabel;
    QDateTimeEdit *timeselect;
    QLCDNumber *currenttime;
    QLabel *today;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(971, 644);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/resource/calendaricon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 991, 651));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"border-image: url(:/background/resource/background.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalWidget = new QWidget(frame);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(30, 560, 631, 61));
        horizontalWidget->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ckShowLunar = new QCheckBox(horizontalWidget);
        ckShowLunar->setObjectName(QString::fromUtf8("ckShowLunar"));
        ckShowLunar->setChecked(true);

        horizontalLayout->addWidget(ckShowLunar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        todaysweather = new QLabel(horizontalWidget);
        todaysweather->setObjectName(QString::fromUtf8("todaysweather"));
        todaysweather->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(todaysweather, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        weatherinformation = new QLabel(horizontalWidget);
        weatherinformation->setObjectName(QString::fromUtf8("weatherinformation"));
        weatherinformation->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(weatherinformation, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new LunarCalendarWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 631, 511));
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(690, 450, 261, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        editcase = new QPushButton(horizontalLayoutWidget_2);
        editcase->setObjectName(QString::fromUtf8("editcase"));

        horizontalLayout_2->addWidget(editcase);

        deletecase = new QPushButton(horizontalLayoutWidget_2);
        deletecase->setObjectName(QString::fromUtf8("deletecase"));

        horizontalLayout_2->addWidget(deletecase);

        verticalLayoutWidget_2 = new QWidget(frame);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(690, 170, 261, 281));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        caselabel = new QLabel(verticalLayoutWidget_2);
        caselabel->setObjectName(QString::fromUtf8("caselabel"));

        verticalLayout_3->addWidget(caselabel);

        caseinfo = new QTextBrowser(verticalLayoutWidget_2);
        caseinfo->setObjectName(QString::fromUtf8("caseinfo"));
        caseinfo->setOpenExternalLinks(true);
        caseinfo->setOpenLinks(true);

        verticalLayout_3->addWidget(caseinfo);

        searchinfo = new QTextEdit(frame);
        searchinfo->setObjectName(QString::fromUtf8("searchinfo"));
        searchinfo->setGeometry(QRect(770, 100, 181, 31));
        searchlabel = new QLabel(frame);
        searchlabel->setObjectName(QString::fromUtf8("searchlabel"));
        searchlabel->setGeometry(QRect(680, 100, 91, 31));
        searchlabel->setStyleSheet(QString::fromUtf8("font: 11pt \"\351\273\221\344\275\223\";"));
        horizontalLayoutWidget_3 = new QWidget(frame);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(690, 140, 261, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        search = new QPushButton(horizontalLayoutWidget_3);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout_3->addWidget(search);

        next = new QPushButton(horizontalLayoutWidget_3);
        next->setObjectName(QString::fromUtf8("next"));

        horizontalLayout_3->addWidget(next);

        horizontalLayoutWidget_4 = new QWidget(frame);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(690, 560, 261, 61));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalLayoutWidget_5 = new QWidget(frame);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(690, 510, 261, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        timelabel = new QLabel(horizontalLayoutWidget_5);
        timelabel->setObjectName(QString::fromUtf8("timelabel"));
        timelabel->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        timelabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(timelabel);

        timeselect = new QDateTimeEdit(horizontalLayoutWidget_5);
        timeselect->setObjectName(QString::fromUtf8("timeselect"));
        timeselect->setCalendarPopup(true);

        horizontalLayout_5->addWidget(timeselect);

        currenttime = new QLCDNumber(frame);
        currenttime->setObjectName(QString::fromUtf8("currenttime"));
        currenttime->setGeometry(QRect(770, 30, 181, 51));
        today = new QLabel(frame);
        today->setObjectName(QString::fromUtf8("today"));
        today->setEnabled(true);
        today->setGeometry(QRect(670, 30, 101, 51));
        today->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Microsoft YaHei UI\";"));
        today->setTextFormat(Qt::AutoText);
        today->setAlignment(Qt::AlignCenter);
        today->setWordWrap(false);
        today->setIndent(-1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\244\232\345\212\237\350\203\275\345\255\246\347\224\237\346\227\245\345\216\206", nullptr));
        ckShowLunar->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\345\206\234\345\216\206", nullptr));
        todaysweather->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\215\227\344\272\254\344\273\212\346\227\245\345\244\251\346\260\224\357\274\232</p></body></html>", nullptr));
        weatherinformation->setText(QCoreApplication::translate("Widget", "weather", nullptr));
        editcase->setText(QCoreApplication::translate("Widget", "\347\274\226\350\276\221", nullptr));
        deletecase->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        caselabel->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\345\244\207\345\277\230\345\275\225</span></p></body></html>", nullptr));
        searchlabel->setText(QCoreApplication::translate("Widget", "\345\244\207\345\277\230\345\275\225\346\220\234\347\264\242", nullptr));
        search->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        next->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\344\270\252", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\217\220\351\206\222", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\217\226\346\266\210\346\217\220\351\206\222", nullptr));
        timelabel->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\346\217\220\351\206\222", nullptr));
        today->setText(QCoreApplication::translate("Widget", "\344\273\212\346\227\245\346\227\245\346\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
