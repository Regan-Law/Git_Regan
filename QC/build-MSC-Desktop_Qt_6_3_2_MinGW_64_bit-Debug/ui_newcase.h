/********************************************************************************
** Form generated from reading UI file 'newcase.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCASE_H
#define UI_NEWCASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newcase
{
public:
    QFrame *frame;
    QTextEdit *caseinfo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *mediacase;
    QPushButton *addmedia;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QWidget *newcase)
    {
        if (newcase->objectName().isEmpty())
            newcase->setObjectName(QString::fromUtf8("newcase"));
        newcase->resize(589, 341);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/resource/calendaricon.png"), QSize(), QIcon::Normal, QIcon::Off);
        newcase->setWindowIcon(icon);
        frame = new QFrame(newcase);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 591, 401));
        frame->setStyleSheet(QString::fromUtf8("#frame{background-image: url(:/background/resource/background.png);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        caseinfo = new QTextEdit(frame);
        caseinfo->setObjectName(QString::fromUtf8("caseinfo"));
        caseinfo->setGeometry(QRect(30, 10, 531, 171));
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 190, 531, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mediacase = new QTextBrowser(verticalLayoutWidget);
        mediacase->setObjectName(QString::fromUtf8("mediacase"));
        mediacase->setOpenExternalLinks(true);

        verticalLayout->addWidget(mediacase);

        addmedia = new QPushButton(verticalLayoutWidget);
        addmedia->setObjectName(QString::fromUtf8("addmedia"));

        verticalLayout->addWidget(addmedia);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        confirm = new QPushButton(verticalLayoutWidget);
        confirm->setObjectName(QString::fromUtf8("confirm"));

        horizontalLayout_2->addWidget(confirm);

        cancel = new QPushButton(verticalLayoutWidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_2->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(newcase);

        QMetaObject::connectSlotsByName(newcase);
    } // setupUi

    void retranslateUi(QWidget *newcase)
    {
        newcase->setWindowTitle(QCoreApplication::translate("newcase", "\345\244\207\345\277\230\345\275\225", nullptr));
        addmedia->setText(QCoreApplication::translate("newcase", "\346\267\273\345\212\240\345\244\232\345\252\222\344\275\223\346\226\207\344\273\266", nullptr));
        confirm->setText(QCoreApplication::translate("newcase", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("newcase", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newcase: public Ui_newcase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCASE_H
