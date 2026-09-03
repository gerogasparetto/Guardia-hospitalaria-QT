#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);

    bool aceptado = false;

    QString usuario = QInputDialog::getText(
        nullptr,
        "Ingreso al sistema",
        "Usuario (en minúsculas y sin espacios):",
        QLineEdit::Normal,
        "",
        &aceptado
    );

    if (!aceptado)
        return 0;

    QString clave = QInputDialog::getText(
        nullptr,
        "Ingreso al sistema",
        "Contraseña:",
        QLineEdit::Password,
        "",
        &aceptado
    );

    if (!aceptado)
        return 0;

    if (usuario != "grupo2" || clave != "utnfrh")
    {
        QMessageBox::critical(
            nullptr,
            "Acceso denegado",
            "Usuario o contraseña incorrectos."
        );

        return 0;
    }

    MainWindow ventana;
    ventana.show();

    return aplicacion.exec();
}
