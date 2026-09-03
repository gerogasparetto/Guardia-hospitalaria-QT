#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QQueue>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

struct Paciente
{
    QString nombreApellido;
    int edad;
    char genero;
    QString dni;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdmision_clicked();
    void on_btnVerProximo_clicked();
    void on_btnAtender_clicked();
    void on_btnSalir_clicked();

private:
    Ui::MainWindow *ui;

    QQueue<Paciente> colaEspera;
    QList<Paciente> listaAtendidos;

    void actualizarPantalla();
};

#endif // MAINWINDOW_H
