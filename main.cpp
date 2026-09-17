#include "mainwindow.h"

#include <QApplication>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);

    // Estilo global de la aplicación: usa la misma paleta de colores que la
    // ventana principal, para que los QMessageBox y QInputDialog (incluidos
    // los del login, que no tienen la ventana principal como padre) se vean
    // consistentes con el resto de la interfaz.
    aplicacion.setStyleSheet(
        "QMessageBox, QInputDialog {"
        "    background-color: rgb(232, 248, 248);"
        "}"
        "QMessageBox QLabel, QInputDialog QLabel {"
        "    color: rgb(0, 0, 0);"
        "    background-color: transparent;"
        "}"
        "QMessageBox QPushButton, QInputDialog QPushButton {"
        "    background-color: rgb(190, 232, 232);"
        "    color: rgb(0, 0, 0);"
        "    min-width: 70px;"
        "    padding: 4px 10px;"
        "}"
        "QInputDialog QLineEdit {"
        "    background-color: white;"
        "    color: rgb(0, 0, 0);"
        "}"
    );

    bool accesoConcedido = false;

    while (!accesoConcedido)
    {
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

        if (usuario == "grupo2" && clave == "utnfrh")
        {
            accesoConcedido = true;
        }
        else
        {
            QMessageBox::critical(
                nullptr,
                "Acceso denegado",
                "Usuario o contraseña incorrectos."
            );

            // No se cierra el programa: el bucle vuelve a pedir usuario y
            // contraseña.
        }
    }

    MainWindow ventana;
    ventana.show();

    return aplicacion.exec();
}
