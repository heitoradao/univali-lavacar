/********************************************************************************
** Form generated from reading UI file 'configuracaoinicialdialog.ui'
**
** Created: Fri Sep 21 10:33:23 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURACAOINICIALDIALOG_H
#define UI_CONFIGURACAOINICIALDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfiguracaoInicialDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelTempoSimulacao;
    QSpinBox *spinBox;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *ConfiguracaoInicialDialog)
    {
        if (ConfiguracaoInicialDialog->objectName().isEmpty())
            ConfiguracaoInicialDialog->setObjectName(QString::fromUtf8("ConfiguracaoInicialDialog"));
        ConfiguracaoInicialDialog->resize(287, 148);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfiguracaoInicialDialog->sizePolicy().hasHeightForWidth());
        ConfiguracaoInicialDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ConfiguracaoInicialDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelTempoSimulacao = new QLabel(ConfiguracaoInicialDialog);
        labelTempoSimulacao->setObjectName(QString::fromUtf8("labelTempoSimulacao"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTempoSimulacao);

        spinBox = new QSpinBox(ConfiguracaoInicialDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox->setMaximum(999999);
        spinBox->setValue(15);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBox);

        label = new QLabel(ConfiguracaoInicialDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(ConfiguracaoInicialDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        label_2 = new QLabel(ConfiguracaoInicialDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        comboBox_2 = new QComboBox(ConfiguracaoInicialDialog);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_2);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ConfiguracaoInicialDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConfiguracaoInicialDialog);

        QMetaObject::connectSlotsByName(ConfiguracaoInicialDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfiguracaoInicialDialog)
    {
        ConfiguracaoInicialDialog->setWindowTitle(QApplication::translate("ConfiguracaoInicialDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        labelTempoSimulacao->setText(QApplication::translate("ConfiguracaoInicialDialog", "tempo de simulacao", 0, QApplication::UnicodeUTF8));
        spinBox->setSuffix(QApplication::translate("ConfiguracaoInicialDialog", " s", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfiguracaoInicialDialog", "Tipo de distribuicao TEC", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConfiguracaoInicialDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ConfiguracaoInicialDialog", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfiguracaoInicialDialog: public Ui_ConfiguracaoInicialDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURACAOINICIALDIALOG_H
