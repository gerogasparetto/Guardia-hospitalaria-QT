#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spnEdad->setRange(0, 120);

    ui->cmbGenero->addItem("Seleccione el género");
    ui->cmbGenero->addItem("F");
    ui->cmbGenero->addItem("M");

    ui->txtDni->setMaxLength(8);
    ui->txtDni->setValidator(new QIntValidator(0, 99999999, this));

    actualizarPantalla();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdmision_clicked()
{
    QString nombre = ui->txtNombre->text().trimmed();
    QString dni = ui->txtDni->text().trimmed();
    int edad = ui->spnEdad->value();

    if (nombre.isEmpty() || dni.isEmpty() || edad == 0 ||
        ui->cmbGenero->currentIndex() == 0)
    {
        QMessageBox::warning(
            this,
            "Datos incompletos",
            "Complete el nombre y apellido, la edad, el género y el DNI."
        );

        return;
    }

    Paciente nuevoPaciente;
    nuevoPaciente.nombreApellido = nombre;
    nuevoPaciente.edad = edad;
    nuevoPaciente.genero = ui->cmbGenero->currentText().at(0).toLatin1();
    nuevoPaciente.dni = dni;

    colaEspera.enqueue(nuevoPaciente);

    ui->txtNombre->clear();
    ui->spnEdad->setValue(0);
    ui->cmbGenero->setCurrentIndex(0);
    ui->txtDni->clear();

    actualizarPantalla();

    QMessageBox::information(
        this,
        "Paciente admitido",
        "El paciente fue agregado a la lista de espera."
    );
}

void MainWindow::on_btnVerProximo_clicked()
{
    if (colaEspera.isEmpty())
    {
        QMessageBox::information(
            this,
            "Lista vacía",
            "No hay pacientes en espera."
        );

        return;
    }

    const Paciente &paciente = colaEspera.head();

    QString datos =
        "Nombre: " + paciente.nombreApellido +
        "\nEdad: " + QString::number(paciente.edad) +
        "\nGénero: " + QString(QChar(paciente.genero)) +
        "\nDNI: " + paciente.dni;

    QMessageBox::information(
        this,
        "Próximo paciente",
        datos
    );
}

void MainWindow::on_btnAtender_clicked()
{
    if (colaEspera.isEmpty())
    {
        QMessageBox::warning(
            this,
            "Lista vacía",
            "No hay pacientes para atender."
        );

        return;
    }

    Paciente pacienteAtendido = colaEspera.dequeue();
    listaAtendidos.append(pacienteAtendido);

    actualizarPantalla();

    QString datos =
        "Paciente atendido:\n\n" +
        pacienteAtendido.nombreApellido +
        "\nDNI: " + pacienteAtendido.dni;

    QMessageBox::information(
        this,
        "Atención",
        datos
    );
}

void MainWindow::on_btnSalir_clicked()
{
    close();
}

void MainWindow::actualizarPantalla()
{
    ui->listEspera->clear();
    ui->listAtendidos->clear();

    for (int i = 0; i < colaEspera.size(); i++)
    {
        const Paciente &paciente = colaEspera.at(i);

        QString texto =
            QString::number(i + 1) + ". " +
            paciente.nombreApellido +
            " - Edad: " + QString::number(paciente.edad) +
            " - Género: " + QString(QChar(paciente.genero)) +
            " - DNI: " + paciente.dni;

        ui->listEspera->addItem(texto);
    }

    for (int i = 0; i < listaAtendidos.size(); i++)
    {
        const Paciente &paciente = listaAtendidos.at(i);

        QString texto =
            QString::number(i + 1) + ". " +
            paciente.nombreApellido +
            " - Edad: " + QString::number(paciente.edad) +
            " - Género: " + QString(QChar(paciente.genero)) +
            " - DNI: " + paciente.dni;

        ui->listAtendidos->addItem(texto);
    }

    if (colaEspera.isEmpty())
    {
        ui->lblProximo->setText("No hay pacientes en espera.");
    }
    else
    {
        const Paciente &paciente = colaEspera.head();

        ui->lblProximo->setText(
            "Próximo: " + paciente.nombreApellido +
            " - DNI: " + paciente.dni
        );
    }

    ui->lblCantidadEspera->setText(
        "En espera: " + QString::number(colaEspera.size())
    );

    ui->lblCantidadAtendidos->setText(
        "Atendidos: " + QString::number(listaAtendidos.size())
    );
}
