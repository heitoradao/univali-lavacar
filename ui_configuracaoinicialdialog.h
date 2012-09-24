/********************************************************************************
** Form generated from reading UI file 'configuracaoinicialdialog.ui'
**
** Created: Sun Sep 23 22:39:47 2012
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
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfiguracaoInicialDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBoxTs;
    QFormLayout *formLayout;
    QLabel *labelTsDistribuicao;
    QLabel *labelTsParametro1;
    QSpinBox *spinBoxTsParametro1;
    QLabel *labellabelTsParametro2;
    QSpinBox *spinBoxTsParametro2;
    QLabel *labelTsParametro3;
    QSpinBox *spinBoxTsParametro3;
    QComboBox *comboBoxTsDistribuicao;
    QGroupBox *groupBoxTec;
    QFormLayout *formLayout_2;
    QLabel *labelTecDistribuicao;
    QComboBox *comboBoxTecDistribuicao;
    QLabel *labelTecParametro1;
    QSpinBox *spinBoxTecParametro1;
    QLabel *labelTecParametro2;
    QSpinBox *spinBoxTecParametro2;
    QLabel *labelTecParametro3;
    QSpinBox *spinBoxTecParametro3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBoxControleTempo;
    QFormLayout *formLayout_3;
    QLabel *labelTempoSimulacao;
    QSpinBox *spinBoxTempoSimulacao;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonAleatoria;
    QRadioButton *radioButtonDeterministica;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfiguracaoInicialDialog)
    {
        if (ConfiguracaoInicialDialog->objectName().isEmpty())
            ConfiguracaoInicialDialog->setObjectName(QString::fromUtf8("ConfiguracaoInicialDialog"));
        ConfiguracaoInicialDialog->resize(492, 270);
        verticalLayout_2 = new QVBoxLayout(ConfiguracaoInicialDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBoxTs = new QGroupBox(ConfiguracaoInicialDialog);
        groupBoxTs->setObjectName(QString::fromUtf8("groupBoxTs"));
        formLayout = new QFormLayout(groupBoxTs);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelTsDistribuicao = new QLabel(groupBoxTs);
        labelTsDistribuicao->setObjectName(QString::fromUtf8("labelTsDistribuicao"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelTsDistribuicao);

        labelTsParametro1 = new QLabel(groupBoxTs);
        labelTsParametro1->setObjectName(QString::fromUtf8("labelTsParametro1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelTsParametro1);

        spinBoxTsParametro1 = new QSpinBox(groupBoxTs);
        spinBoxTsParametro1->setObjectName(QString::fromUtf8("spinBoxTsParametro1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxTsParametro1);

        labellabelTsParametro2 = new QLabel(groupBoxTs);
        labellabelTsParametro2->setObjectName(QString::fromUtf8("labellabelTsParametro2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labellabelTsParametro2);

        spinBoxTsParametro2 = new QSpinBox(groupBoxTs);
        spinBoxTsParametro2->setObjectName(QString::fromUtf8("spinBoxTsParametro2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxTsParametro2);

        labelTsParametro3 = new QLabel(groupBoxTs);
        labelTsParametro3->setObjectName(QString::fromUtf8("labelTsParametro3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelTsParametro3);

        spinBoxTsParametro3 = new QSpinBox(groupBoxTs);
        spinBoxTsParametro3->setObjectName(QString::fromUtf8("spinBoxTsParametro3"));

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxTsParametro3);

        comboBoxTsDistribuicao = new QComboBox(groupBoxTs);
        comboBoxTsDistribuicao->setObjectName(QString::fromUtf8("comboBoxTsDistribuicao"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxTsDistribuicao);


        horizontalLayout->addWidget(groupBoxTs);

        groupBoxTec = new QGroupBox(ConfiguracaoInicialDialog);
        groupBoxTec->setObjectName(QString::fromUtf8("groupBoxTec"));
        formLayout_2 = new QFormLayout(groupBoxTec);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        labelTecDistribuicao = new QLabel(groupBoxTec);
        labelTecDistribuicao->setObjectName(QString::fromUtf8("labelTecDistribuicao"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelTecDistribuicao);

        comboBoxTecDistribuicao = new QComboBox(groupBoxTec);
        comboBoxTecDistribuicao->setObjectName(QString::fromUtf8("comboBoxTecDistribuicao"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBoxTecDistribuicao);

        labelTecParametro1 = new QLabel(groupBoxTec);
        labelTecParametro1->setObjectName(QString::fromUtf8("labelTecParametro1"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelTecParametro1);

        spinBoxTecParametro1 = new QSpinBox(groupBoxTec);
        spinBoxTecParametro1->setObjectName(QString::fromUtf8("spinBoxTecParametro1"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBoxTecParametro1);

        labelTecParametro2 = new QLabel(groupBoxTec);
        labelTecParametro2->setObjectName(QString::fromUtf8("labelTecParametro2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelTecParametro2);

        spinBoxTecParametro2 = new QSpinBox(groupBoxTec);
        spinBoxTecParametro2->setObjectName(QString::fromUtf8("spinBoxTecParametro2"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinBoxTecParametro2);

        labelTecParametro3 = new QLabel(groupBoxTec);
        labelTecParametro3->setObjectName(QString::fromUtf8("labelTecParametro3"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelTecParametro3);

        spinBoxTecParametro3 = new QSpinBox(groupBoxTec);
        spinBoxTecParametro3->setObjectName(QString::fromUtf8("spinBoxTecParametro3"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, spinBoxTecParametro3);


        horizontalLayout->addWidget(groupBoxTec);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBoxControleTempo = new QGroupBox(ConfiguracaoInicialDialog);
        groupBoxControleTempo->setObjectName(QString::fromUtf8("groupBoxControleTempo"));
        formLayout_3 = new QFormLayout(groupBoxControleTempo);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        labelTempoSimulacao = new QLabel(groupBoxControleTempo);
        labelTempoSimulacao->setObjectName(QString::fromUtf8("labelTempoSimulacao"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelTempoSimulacao);

        spinBoxTempoSimulacao = new QSpinBox(groupBoxControleTempo);
        spinBoxTempoSimulacao->setObjectName(QString::fromUtf8("spinBoxTempoSimulacao"));
        spinBoxTempoSimulacao->setMaximum(9999999);
        spinBoxTempoSimulacao->setValue(30);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxTempoSimulacao);


        horizontalLayout_2->addWidget(groupBoxControleTempo);

        groupBox = new QGroupBox(ConfiguracaoInicialDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonAleatoria = new QRadioButton(groupBox);
        radioButtonAleatoria->setObjectName(QString::fromUtf8("radioButtonAleatoria"));

        verticalLayout->addWidget(radioButtonAleatoria);

        radioButtonDeterministica = new QRadioButton(groupBox);
        radioButtonDeterministica->setObjectName(QString::fromUtf8("radioButtonDeterministica"));
        radioButtonDeterministica->setChecked(true);

        verticalLayout->addWidget(radioButtonDeterministica);


        horizontalLayout_2->addWidget(groupBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(ConfiguracaoInicialDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        labelTsDistribuicao->setBuddy(comboBoxTsDistribuicao);
        labelTsParametro1->setBuddy(spinBoxTsParametro1);
        labellabelTsParametro2->setBuddy(spinBoxTsParametro2);
        labelTsParametro3->setBuddy(spinBoxTsParametro3);
        labelTecDistribuicao->setBuddy(comboBoxTecDistribuicao);
        labelTecParametro1->setBuddy(spinBoxTecParametro1);
        labelTecParametro2->setBuddy(spinBoxTecParametro2);
        labelTecParametro3->setBuddy(spinBoxTecParametro3);
        labelTempoSimulacao->setBuddy(spinBoxTempoSimulacao);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBoxTsDistribuicao, spinBoxTsParametro1);
        QWidget::setTabOrder(spinBoxTsParametro1, spinBoxTsParametro2);
        QWidget::setTabOrder(spinBoxTsParametro2, spinBoxTsParametro3);
        QWidget::setTabOrder(spinBoxTsParametro3, comboBoxTecDistribuicao);
        QWidget::setTabOrder(comboBoxTecDistribuicao, spinBoxTecParametro1);
        QWidget::setTabOrder(spinBoxTecParametro1, spinBoxTecParametro2);
        QWidget::setTabOrder(spinBoxTecParametro2, spinBoxTecParametro3);
        QWidget::setTabOrder(spinBoxTecParametro3, spinBoxTempoSimulacao);
        QWidget::setTabOrder(spinBoxTempoSimulacao, buttonBox);

        retranslateUi(ConfiguracaoInicialDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfiguracaoInicialDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfiguracaoInicialDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfiguracaoInicialDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfiguracaoInicialDialog)
    {
        ConfiguracaoInicialDialog->setWindowTitle(QApplication::translate("ConfiguracaoInicialDialog", "Configuracao", 0, QApplication::UnicodeUTF8));
        groupBoxTs->setTitle(QApplication::translate("ConfiguracaoInicialDialog", "T&S", 0, QApplication::UnicodeUTF8));
        labelTsDistribuicao->setText(QApplication::translate("ConfiguracaoInicialDialog", "distribui\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        labelTsParametro1->setText(QApplication::translate("ConfiguracaoInicialDialog", "parametro 1", 0, QApplication::UnicodeUTF8));
        labellabelTsParametro2->setText(QApplication::translate("ConfiguracaoInicialDialog", "parametro 2", 0, QApplication::UnicodeUTF8));
        labelTsParametro3->setText(QApplication::translate("ConfiguracaoInicialDialog", "parametro 3", 0, QApplication::UnicodeUTF8));
        comboBoxTsDistribuicao->clear();
        comboBoxTsDistribuicao->insertItems(0, QStringList()
         << QApplication::translate("ConfiguracaoInicialDialog", "constante", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "exponencial negativa", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "log", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "triangular", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "uniforme", 0, QApplication::UnicodeUTF8)
        );
        groupBoxTec->setTitle(QApplication::translate("ConfiguracaoInicialDialog", "T&EC", 0, QApplication::UnicodeUTF8));
        labelTecDistribuicao->setText(QApplication::translate("ConfiguracaoInicialDialog", "distribuicao", 0, QApplication::UnicodeUTF8));
        comboBoxTecDistribuicao->clear();
        comboBoxTecDistribuicao->insertItems(0, QStringList()
         << QApplication::translate("ConfiguracaoInicialDialog", "constante", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "exponencial negativa", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "log", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "triangular", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfiguracaoInicialDialog", "uniforme", 0, QApplication::UnicodeUTF8)
        );
        labelTecParametro1->setText(QApplication::translate("ConfiguracaoInicialDialog", "parametro 1", 0, QApplication::UnicodeUTF8));
        labelTecParametro2->setText(QApplication::translate("ConfiguracaoInicialDialog", "parametro 2", 0, QApplication::UnicodeUTF8));
        labelTecParametro3->setText(QApplication::translate("ConfiguracaoInicialDialog", "parametro 3", 0, QApplication::UnicodeUTF8));
        groupBoxControleTempo->setTitle(QApplication::translate("ConfiguracaoInicialDialog", "Controle de tempo", 0, QApplication::UnicodeUTF8));
        labelTempoSimulacao->setText(QApplication::translate("ConfiguracaoInicialDialog", "&tempo de simula\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        spinBoxTempoSimulacao->setSuffix(QApplication::translate("ConfiguracaoInicialDialog", " s", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ConfiguracaoInicialDialog", "Semente", 0, QApplication::UnicodeUTF8));
        radioButtonAleatoria->setText(QApplication::translate("ConfiguracaoInicialDialog", "aleat\303\263ria", 0, QApplication::UnicodeUTF8));
        radioButtonDeterministica->setText(QApplication::translate("ConfiguracaoInicialDialog", "determin\303\255stica", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfiguracaoInicialDialog: public Ui_ConfiguracaoInicialDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURACAOINICIALDIALOG_H
