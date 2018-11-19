#ifndef VENTANA_PRINCIPAL_H
#define VENTANA_PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class ventana_principal;
}

class ventana_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventana_principal(QWidget *parent = nullptr);
    ~ventana_principal();

private:
    Ui::ventana_principal *ui;
};

#endif // VENTANA_PRINCIPAL_H
