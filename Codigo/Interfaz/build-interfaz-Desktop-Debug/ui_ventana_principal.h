/********************************************************************************
** Form generated from reading UI file 'ventana_principal.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_PRINCIPAL_H
#define UI_VENTANA_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventana_principal
{
public:
    QWidget *central_widget;
    QGridLayout *gridLayout_3;
    QTabWidget *pestanas;
    QWidget *informacion;
    QGridLayout *gridLayout_2;
    QSpacerItem *informacion_spacer5;
    QSpacerItem *informacion_spacer2;
    QSpacerItem *informacion_spacer4;
    QGridLayout *infomacion_layout;
    QVBoxLayout *red_layout;
    QLabel *red_label;
    QTextEdit *red_data;
    QVBoxLayout *disco_layout;
    QLabel *disco_label;
    QTextEdit *disco_data;
    QVBoxLayout *memoria_layout;
    QLabel *memoria_label;
    QTextEdit *memoria_data;
    QSpacerItem *informacion_spacer1;
    QVBoxLayout *sistema_layout;
    QLabel *sistema_label;
    QTextEdit *sistema_data;
    QSpacerItem *informacion_spacer0;
    QSpacerItem *informacion_spacer3;
    QWidget *lanzador;
    QGridLayout *gridLayout;
    QSpacerItem *lanzar_spacer3;
    QVBoxLayout *lanzador_layout;
    QVBoxLayout *lanzar_layout;
    QLabel *lanzar_label;
    QHBoxLayout *lanzar_control_layout;
    QTextEdit *lanzar_text;
    QSpacerItem *lanzar_spacer;
    QPushButton *lanzar_button;
    QSpacerItem *lanzar_spacer1;
    QVBoxLayout *conocer_layout;
    QLabel *conocer_label;
    QHBoxLayout *conocer_control_layout;
    QTextEdit *conocer_text;
    QSpacerItem *conocer_spacer;
    QPushButton *conocer_button;
    QSpacerItem *lanzar_spacer0;
    QVBoxLayout *terminar_layout;
    QLabel *terminar_label;
    QHBoxLayout *terminar_control_layout;
    QTextEdit *terminar_text;
    QSpacerItem *terminar_spacer;
    QPushButton *terminar_button;
    QSpacerItem *lanzar_spacer2;
    QSpacerItem *lanzar_spacer4;
    QSpacerItem *lanzar_spacer5;
    QWidget *acerca;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *acerca_layout;
    QVBoxLayout *realizado_layout;
    QSpacerItem *acerca_spacer3;
    QLabel *Realizado;
    QSpacerItem *acerca_spacer0;
    QLabel *david;
    QSpacerItem *acerca_spacer1;
    QLabel *yeison;
    QSpacerItem *acerca_spacer2;
    QLabel *adriana;
    QSpacerItem *acerca_spcacer4;
    QVBoxLayout *identificador_layout;
    QSpacerItem *acerca_spacer5;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *desarrollado;
    QSpacerItem *acerca_space6;

    void setupUi(QMainWindow *ventana_principal)
    {
        if (ventana_principal->objectName().isEmpty())
            ventana_principal->setObjectName(QStringLiteral("ventana_principal"));
        ventana_principal->setEnabled(true);
        ventana_principal->resize(700, 600);
        ventana_principal->setMinimumSize(QSize(700, 600));
        ventana_principal->setMaximumSize(QSize(700, 600));
        central_widget = new QWidget(ventana_principal);
        central_widget->setObjectName(QStringLiteral("central_widget"));
        gridLayout_3 = new QGridLayout(central_widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pestanas = new QTabWidget(central_widget);
        pestanas->setObjectName(QStringLiteral("pestanas"));
        pestanas->setMaximumSize(QSize(700, 600));
        pestanas->setStyleSheet(QStringLiteral(""));
        informacion = new QWidget();
        informacion->setObjectName(QStringLiteral("informacion"));
        gridLayout_2 = new QGridLayout(informacion);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        informacion_spacer5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(informacion_spacer5, 2, 1, 1, 1);

        informacion_spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(informacion_spacer2, 1, 0, 1, 1);

        informacion_spacer4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(informacion_spacer4, 0, 1, 1, 1);

        infomacion_layout = new QGridLayout();
        infomacion_layout->setObjectName(QStringLiteral("infomacion_layout"));
        red_layout = new QVBoxLayout();
        red_layout->setObjectName(QStringLiteral("red_layout"));
        red_label = new QLabel(informacion);
        red_label->setObjectName(QStringLiteral("red_label"));
        red_label->setMinimumSize(QSize(300, 30));

        red_layout->addWidget(red_label);

        red_data = new QTextEdit(informacion);
        red_data->setObjectName(QStringLiteral("red_data"));

        red_layout->addWidget(red_data);


        infomacion_layout->addLayout(red_layout, 0, 2, 1, 1);

        disco_layout = new QVBoxLayout();
        disco_layout->setObjectName(QStringLiteral("disco_layout"));
        disco_label = new QLabel(informacion);
        disco_label->setObjectName(QStringLiteral("disco_label"));
        disco_label->setMinimumSize(QSize(300, 30));

        disco_layout->addWidget(disco_label);

        disco_data = new QTextEdit(informacion);
        disco_data->setObjectName(QStringLiteral("disco_data"));

        disco_layout->addWidget(disco_data);


        infomacion_layout->addLayout(disco_layout, 2, 0, 1, 1);

        memoria_layout = new QVBoxLayout();
        memoria_layout->setObjectName(QStringLiteral("memoria_layout"));
        memoria_label = new QLabel(informacion);
        memoria_label->setObjectName(QStringLiteral("memoria_label"));
        memoria_label->setMinimumSize(QSize(300, 30));

        memoria_layout->addWidget(memoria_label);

        memoria_data = new QTextEdit(informacion);
        memoria_data->setObjectName(QStringLiteral("memoria_data"));

        memoria_layout->addWidget(memoria_data);


        infomacion_layout->addLayout(memoria_layout, 0, 0, 1, 1);

        informacion_spacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infomacion_layout->addItem(informacion_spacer1, 1, 0, 1, 1);

        sistema_layout = new QVBoxLayout();
        sistema_layout->setObjectName(QStringLiteral("sistema_layout"));
        sistema_label = new QLabel(informacion);
        sistema_label->setObjectName(QStringLiteral("sistema_label"));
        sistema_label->setMinimumSize(QSize(300, 30));

        sistema_layout->addWidget(sistema_label);

        sistema_data = new QTextEdit(informacion);
        sistema_data->setObjectName(QStringLiteral("sistema_data"));

        sistema_layout->addWidget(sistema_data);


        infomacion_layout->addLayout(sistema_layout, 2, 2, 1, 1);

        informacion_spacer0 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        infomacion_layout->addItem(informacion_spacer0, 2, 1, 1, 1);


        gridLayout_2->addLayout(infomacion_layout, 1, 1, 1, 1);

        informacion_spacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(informacion_spacer3, 1, 2, 1, 1);

        pestanas->addTab(informacion, QString());
        lanzador = new QWidget();
        lanzador->setObjectName(QStringLiteral("lanzador"));
        gridLayout = new QGridLayout(lanzador);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lanzar_spacer3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(lanzar_spacer3, 1, 2, 1, 1);

        lanzador_layout = new QVBoxLayout();
        lanzador_layout->setObjectName(QStringLiteral("lanzador_layout"));
        lanzar_layout = new QVBoxLayout();
        lanzar_layout->setObjectName(QStringLiteral("lanzar_layout"));
        lanzar_label = new QLabel(lanzador);
        lanzar_label->setObjectName(QStringLiteral("lanzar_label"));

        lanzar_layout->addWidget(lanzar_label);

        lanzar_control_layout = new QHBoxLayout();
        lanzar_control_layout->setObjectName(QStringLiteral("lanzar_control_layout"));
        lanzar_text = new QTextEdit(lanzador);
        lanzar_text->setObjectName(QStringLiteral("lanzar_text"));
        lanzar_text->setMaximumSize(QSize(300, 40));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lanzar_text->setFont(font);

        lanzar_control_layout->addWidget(lanzar_text);

        lanzar_spacer = new QSpacerItem(40, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        lanzar_control_layout->addItem(lanzar_spacer);

        lanzar_button = new QPushButton(lanzador);
        lanzar_button->setObjectName(QStringLiteral("lanzar_button"));

        lanzar_control_layout->addWidget(lanzar_button);


        lanzar_layout->addLayout(lanzar_control_layout);


        lanzador_layout->addLayout(lanzar_layout);

        lanzar_spacer1 = new QSpacerItem(388, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        lanzador_layout->addItem(lanzar_spacer1);

        conocer_layout = new QVBoxLayout();
        conocer_layout->setObjectName(QStringLiteral("conocer_layout"));
        conocer_label = new QLabel(lanzador);
        conocer_label->setObjectName(QStringLiteral("conocer_label"));

        conocer_layout->addWidget(conocer_label);

        conocer_control_layout = new QHBoxLayout();
        conocer_control_layout->setObjectName(QStringLiteral("conocer_control_layout"));
        conocer_text = new QTextEdit(lanzador);
        conocer_text->setObjectName(QStringLiteral("conocer_text"));
        conocer_text->setMaximumSize(QSize(300, 40));
        conocer_text->setFont(font);

        conocer_control_layout->addWidget(conocer_text);

        conocer_spacer = new QSpacerItem(40, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        conocer_control_layout->addItem(conocer_spacer);

        conocer_button = new QPushButton(lanzador);
        conocer_button->setObjectName(QStringLiteral("conocer_button"));

        conocer_control_layout->addWidget(conocer_button);


        conocer_layout->addLayout(conocer_control_layout);


        lanzador_layout->addLayout(conocer_layout);

        lanzar_spacer0 = new QSpacerItem(388, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        lanzador_layout->addItem(lanzar_spacer0);

        terminar_layout = new QVBoxLayout();
        terminar_layout->setObjectName(QStringLiteral("terminar_layout"));
        terminar_label = new QLabel(lanzador);
        terminar_label->setObjectName(QStringLiteral("terminar_label"));

        terminar_layout->addWidget(terminar_label);

        terminar_control_layout = new QHBoxLayout();
        terminar_control_layout->setObjectName(QStringLiteral("terminar_control_layout"));
        terminar_text = new QTextEdit(lanzador);
        terminar_text->setObjectName(QStringLiteral("terminar_text"));
        terminar_text->setMaximumSize(QSize(300, 40));
        terminar_text->setFont(font);

        terminar_control_layout->addWidget(terminar_text);

        terminar_spacer = new QSpacerItem(40, 30, QSizePolicy::Fixed, QSizePolicy::Minimum);

        terminar_control_layout->addItem(terminar_spacer);

        terminar_button = new QPushButton(lanzador);
        terminar_button->setObjectName(QStringLiteral("terminar_button"));

        terminar_control_layout->addWidget(terminar_button);


        terminar_layout->addLayout(terminar_control_layout);


        lanzador_layout->addLayout(terminar_layout);


        gridLayout->addLayout(lanzador_layout, 1, 1, 1, 1);

        lanzar_spacer2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(lanzar_spacer2, 1, 0, 1, 1);

        lanzar_spacer4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(lanzar_spacer4, 2, 1, 1, 1);

        lanzar_spacer5 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(lanzar_spacer5, 0, 1, 1, 1);

        pestanas->addTab(lanzador, QString());
        acerca = new QWidget();
        acerca->setObjectName(QStringLiteral("acerca"));
        verticalLayout_3 = new QVBoxLayout(acerca);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        acerca_layout = new QHBoxLayout();
        acerca_layout->setObjectName(QStringLiteral("acerca_layout"));
        realizado_layout = new QVBoxLayout();
        realizado_layout->setObjectName(QStringLiteral("realizado_layout"));
        acerca_spacer3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        realizado_layout->addItem(acerca_spacer3);

        Realizado = new QLabel(acerca);
        Realizado->setObjectName(QStringLiteral("Realizado"));
        Realizado->setTextFormat(Qt::AutoText);
        Realizado->setScaledContents(false);
        Realizado->setAlignment(Qt::AlignCenter);

        realizado_layout->addWidget(Realizado);

        acerca_spacer0 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        realizado_layout->addItem(acerca_spacer0);

        david = new QLabel(acerca);
        david->setObjectName(QStringLiteral("david"));

        realizado_layout->addWidget(david);

        acerca_spacer1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        realizado_layout->addItem(acerca_spacer1);

        yeison = new QLabel(acerca);
        yeison->setObjectName(QStringLiteral("yeison"));

        realizado_layout->addWidget(yeison);

        acerca_spacer2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        realizado_layout->addItem(acerca_spacer2);

        adriana = new QLabel(acerca);
        adriana->setObjectName(QStringLiteral("adriana"));

        realizado_layout->addWidget(adriana);

        acerca_spcacer4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        realizado_layout->addItem(acerca_spcacer4);


        acerca_layout->addLayout(realizado_layout);

        identificador_layout = new QVBoxLayout();
        identificador_layout->setObjectName(QStringLiteral("identificador_layout"));
        acerca_spacer5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        identificador_layout->addItem(acerca_spacer5);

        label = new QLabel(acerca);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/unet.png")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        identificador_layout->addWidget(label);

        verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        identificador_layout->addItem(verticalSpacer);

        desarrollado = new QLabel(acerca);
        desarrollado->setObjectName(QStringLiteral("desarrollado"));

        identificador_layout->addWidget(desarrollado);

        acerca_space6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        identificador_layout->addItem(acerca_space6);


        acerca_layout->addLayout(identificador_layout);


        verticalLayout_3->addLayout(acerca_layout);

        pestanas->addTab(acerca, QString());

        gridLayout_3->addWidget(pestanas, 0, 1, 1, 1);

        ventana_principal->setCentralWidget(central_widget);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(ventana_principal);

        pestanas->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ventana_principal);
    } // setupUi

    void retranslateUi(QMainWindow *ventana_principal)
    {
        ventana_principal->setWindowTitle(QApplication::translate("ventana_principal", "Monitoreo", nullptr));
        red_label->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Datos de Red</span></p></body></html>", nullptr));
        disco_label->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Datos del Disco</span></p></body></html>", nullptr));
        memoria_label->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Datos del Memoria</span></p></body></html>", nullptr));
        sistema_label->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Datos del Sistema</span></p></body></html>", nullptr));
        pestanas->setTabText(pestanas->indexOf(informacion), QApplication::translate("ventana_principal", "Informaci\303\263n del Sistema", nullptr));
        lanzar_label->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">LANZAR APLICACION</span></p></body></html>", nullptr));
        lanzar_button->setText(QApplication::translate("ventana_principal", "INICIAR", nullptr));
        conocer_label->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">CONOCER UN PID DE UN PROCESO</span></p></body></html>", nullptr));
        conocer_button->setText(QApplication::translate("ventana_principal", "OBTEBER PID", nullptr));
        terminar_label->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">TERMINAR APLICACION (INGRESE PID)</span></p></body></html>", nullptr));
        terminar_button->setText(QApplication::translate("ventana_principal", "TERMINAR", nullptr));
        pestanas->setTabText(pestanas->indexOf(lanzador), QApplication::translate("ventana_principal", "Lanzador de Aplicaciones", nullptr));
        Realizado->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; text-decoration: underline;\">REALIZADO POR</span></p></body></html>", nullptr));
        david->setText(QApplication::translate("ventana_principal", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:10pt; font-weight:456; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">David Chac\303\263n</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">25.023.230</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">davidl.chacong@unet.edu.ve</span></p></body></html>", nullptr));
        yeison->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Yeison Fuentes</span></p><p align=\"center\"><span style=\" font-size:12pt;\">23.498.281</span></p><p align=\"center\"><span style=\" font-size:12pt;\">yeison.fuentes@unet.edu.ve</span></p></body></html>", nullptr));
        adriana->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Adriana Delgado</span></p><p align=\"center\"><span style=\" font-size:12pt;\">24.776.202</span></p><p align=\"center\"><span style=\" font-size:12pt;\">adrianae.delgadoc@unet.edu.ve</span></p></body></html>", nullptr));
        label->setText(QString());
        desarrollado->setText(QApplication::translate("ventana_principal", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">Programa realizado con fines </span></p><p align=\"center\"><span style=\" font-size:11pt;\">academicos para la materia </span></p><p align=\"center\"><span style=\" font-size:11pt;\">de Sistemas Operativos de la </span></p><p align=\"center\"><span style=\" font-size:11pt;\">carrera de Ingenier\303\255a en Inform\303\241tica</span></p></body></html>", nullptr));
        pestanas->setTabText(pestanas->indexOf(acerca), QApplication::translate("ventana_principal", "Acerca de", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ventana_principal: public Ui_ventana_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_PRINCIPAL_H
