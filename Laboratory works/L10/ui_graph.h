/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GraphQueue
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;

    void setupUi(QDialog *GraphQueue)
    {
        if (GraphQueue->objectName().isEmpty())
            GraphQueue->setObjectName(QString::fromUtf8("GraphQueue"));
        GraphQueue->resize(398, 394);
        verticalLayout = new QVBoxLayout(GraphQueue);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(GraphQueue);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(GraphQueue);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(GraphQueue);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(GraphQueue);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(GraphQueue);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        textEdit = new QTextEdit(GraphQueue);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);


        retranslateUi(GraphQueue);

        QMetaObject::connectSlotsByName(GraphQueue);
    } // setupUi

    void retranslateUi(QDialog *GraphQueue)
    {
        GraphQueue->setWindowTitle(QCoreApplication::translate("GraphQueue", "Queue", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("GraphQueue", "Add element", nullptr));
        pushButton_2->setText(QCoreApplication::translate("GraphQueue", "Remove element", nullptr));
        pushButton_4->setText(QCoreApplication::translate("GraphQueue", "Sort elements", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GraphQueue", "Remove all elements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphQueue: public Ui_GraphQueue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
