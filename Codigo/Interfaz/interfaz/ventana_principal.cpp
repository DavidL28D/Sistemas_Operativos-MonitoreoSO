#include "ventana_principal.h"
#include "ui_ventana_principal.h"

ventana_principal::ventana_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventana_principal)
{
    ui->setupUi(this);
}

ventana_principal::~ventana_principal()
{
    delete ui;
}
