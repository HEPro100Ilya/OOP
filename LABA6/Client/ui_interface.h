/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QGridLayout *gridLayout_3;
    QPushButton *ShowMatrix;
    QPushButton *Transponed;
    QRadioButton *r_mode;
    QRadioButton *i_mode;
    QTableWidget *tableWidget;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *output;
    QRadioButton *c_mode;
    QFrame *detframe;
    QGridLayout *gridLayout_2;
    QLabel *Det;
    QFrame *rangframe;
    QGridLayout *gridLayout;
    QLabel *Rang_2;
    QPushButton *Determenant;
    QPushButton *Rang;
    QLineEdit *Cols;
    QLineEdit *Rows;
    QPushButton *SizeChange;
    QPushButton *DataMatrixShow;
    QPushButton *pushButton;

    void setupUi(QWidget *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->resize(1034, 592);
        Interface->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(Interface);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ShowMatrix = new QPushButton(Interface);
        ShowMatrix->setObjectName(QString::fromUtf8("ShowMatrix"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        ShowMatrix->setFont(font);

        gridLayout_3->addWidget(ShowMatrix, 3, 5, 1, 1);

        Transponed = new QPushButton(Interface);
        Transponed->setObjectName(QString::fromUtf8("Transponed"));
        Transponed->setFont(font);

        gridLayout_3->addWidget(Transponed, 4, 5, 1, 1);

        r_mode = new QRadioButton(Interface);
        r_mode->setObjectName(QString::fromUtf8("r_mode"));
        r_mode->setFont(font);

        gridLayout_3->addWidget(r_mode, 7, 1, 1, 1);

        i_mode = new QRadioButton(Interface);
        i_mode->setObjectName(QString::fromUtf8("i_mode"));
        i_mode->setFont(font);

        gridLayout_3->addWidget(i_mode, 7, 5, 1, 1);

        tableWidget = new QTableWidget(Interface);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setFrameShape(QFrame::StyledPanel);
        tableWidget->setLineWidth(1);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(28);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);

        gridLayout_3->addWidget(tableWidget, 0, 1, 1, 3);

        frame_2 = new QFrame(Interface);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(2);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        output = new QLabel(frame_2);
        output->setObjectName(QString::fromUtf8("output"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Cascadia Mono SemiBold"));
        font1.setPointSize(12);
        font1.setBold(true);
        output->setFont(font1);
        output->setMargin(0);

        horizontalLayout_2->addWidget(output);


        gridLayout_3->addWidget(frame_2, 0, 4, 1, 2);

        c_mode = new QRadioButton(Interface);
        c_mode->setObjectName(QString::fromUtf8("c_mode"));
        c_mode->setFont(font);

        gridLayout_3->addWidget(c_mode, 7, 3, 1, 1);

        detframe = new QFrame(Interface);
        detframe->setObjectName(QString::fromUtf8("detframe"));
        detframe->setFrameShape(QFrame::Box);
        detframe->setFrameShadow(QFrame::Plain);
        detframe->setLineWidth(2);
        gridLayout_2 = new QGridLayout(detframe);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Det = new QLabel(detframe);
        Det->setObjectName(QString::fromUtf8("Det"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        Det->setFont(font2);

        gridLayout_2->addWidget(Det, 0, 0, 1, 1);


        gridLayout_3->addWidget(detframe, 4, 1, 1, 1);

        rangframe = new QFrame(Interface);
        rangframe->setObjectName(QString::fromUtf8("rangframe"));
        rangframe->setFrameShape(QFrame::Box);
        rangframe->setFrameShadow(QFrame::Plain);
        rangframe->setLineWidth(2);
        gridLayout = new QGridLayout(rangframe);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Rang_2 = new QLabel(rangframe);
        Rang_2->setObjectName(QString::fromUtf8("Rang_2"));
        Rang_2->setFont(font2);

        gridLayout->addWidget(Rang_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(rangframe, 5, 1, 1, 1);

        Determenant = new QPushButton(Interface);
        Determenant->setObjectName(QString::fromUtf8("Determenant"));
        Determenant->setFont(font);

        gridLayout_3->addWidget(Determenant, 4, 3, 1, 1);

        Rang = new QPushButton(Interface);
        Rang->setObjectName(QString::fromUtf8("Rang"));
        Rang->setFont(font);

        gridLayout_3->addWidget(Rang, 5, 3, 1, 1);

        Cols = new QLineEdit(Interface);
        Cols->setObjectName(QString::fromUtf8("Cols"));

        gridLayout_3->addWidget(Cols, 1, 1, 1, 1);

        Rows = new QLineEdit(Interface);
        Rows->setObjectName(QString::fromUtf8("Rows"));

        gridLayout_3->addWidget(Rows, 1, 3, 1, 1);

        SizeChange = new QPushButton(Interface);
        SizeChange->setObjectName(QString::fromUtf8("SizeChange"));
        SizeChange->setFont(font);

        gridLayout_3->addWidget(SizeChange, 1, 5, 1, 1);

        DataMatrixShow = new QPushButton(Interface);
        DataMatrixShow->setObjectName(QString::fromUtf8("DataMatrixShow"));
        DataMatrixShow->setFont(font);

        gridLayout_3->addWidget(DataMatrixShow, 3, 1, 1, 2);

        pushButton = new QPushButton(Interface);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(pushButton, 5, 5, 1, 1);


        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QWidget *Interface)
    {
        Interface->setWindowTitle(QCoreApplication::translate("Interface", "Practice\342\204\2266", nullptr));
        ShowMatrix->setText(QCoreApplication::translate("Interface", "Create and show matrix", nullptr));
        Transponed->setText(QCoreApplication::translate("Interface", "Transpond", nullptr));
        r_mode->setText(QCoreApplication::translate("Interface", "Rational", nullptr));
        i_mode->setText(QCoreApplication::translate("Interface", "Real", nullptr));
        output->setText(QString());
        c_mode->setText(QCoreApplication::translate("Interface", "Complex", nullptr));
        Det->setText(QString());
        Rang_2->setText(QString());
        Determenant->setText(QCoreApplication::translate("Interface", "Determenant", nullptr));
        Rang->setText(QCoreApplication::translate("Interface", "Rang", nullptr));
        Cols->setText(QCoreApplication::translate("Interface", "3", nullptr));
        Rows->setText(QCoreApplication::translate("Interface", "3", nullptr));
        SizeChange->setText(QCoreApplication::translate("Interface", "AcceptSize", nullptr));
        DataMatrixShow->setText(QCoreApplication::translate("Interface", "Save new value", nullptr));
        pushButton->setText(QCoreApplication::translate("Interface", "Save data type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
