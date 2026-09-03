# SISTEMA DE GUARDIA HOSPITALARIA - González Fátima, González Guillermina, Gasparetto Gerónimo

Sistema de gestión de turnos para una guardia hospitalaria desarrollado en C++ y Qt Creator.

## Descripción

El proyecto consistió en el desarrollo de un **Sistema de Gestión de Turnos para una Guardia Hospitalaria**, realizado en lenguaje **C++** utilizando **Qt Creator** para el desarrollo de la interfaz gráfica de usuario.

El objetivo principal del programa es gestionar el ingreso, espera y atención de pacientes en una guardia hospitalaria, respetando el **orden de llegada** de cada paciente.

El proyecto fue desarrollado como trabajo práctico dentro de la materia Programación II en la carrera Bioingeniería de la UTN FRH. Se aplicaron conceptos de programación en C++ y diseño de interfaces gráficas vistos en las respectivas unidades de la materia.

---

## Objetivos del proyecto

El sistema permite:

* Ingresar al sistema mediante usuario y contraseña.
* Registrar nuevos pacientes.
* Guardar los datos personales de cada paciente.
* Mostrar los pacientes que se encuentran esperando.
* Mostrar quién es el próximo paciente a ser atendido.
* Atender al paciente que se encuentra primero en la cola.
* Mantener un historial de los pacientes atendidos.
* Salir del sistema.

---

## Tecnologías utilizadas

* **Lenguaje:** C++
* **Entorno de desarrollo:** Qt Creator
* **Sistema de construcción:** qmake
* **Interfaz gráfica:** Qt Designer

---

## Inicio de sesión

Antes de acceder al sistema, se solicita un usuario y una contraseña.
### Datos de acceso:

```text
Usuario: grupo3
Contraseña: utnfrh
```

Si los datos ingresados son correctos, se abre la ventana principal de la aplicación.

En caso contrario, se muestra un mensaje indicando que el acceso fue denegado.

---

# Registro y admisión de pacientes

Desde la sección **"Admisión de nuevo paciente"** se pueden ingresar los datos del paciente:

* Nombre y apellido
* Edad
* Género
* DNI

Una vez completados los datos, se presiona el botón **"Admitir paciente"**.

El paciente es incorporado automáticamente al final de la lista de espera.

---

# Sistema de cola

Para administrar los pacientes que todavía no fueron atendidos se utiliza:

```cpp
QQueue<Paciente> colaEspera;
```
`QQueue` nos permitió implementar una estructura de datos tipo **FIFO**:

> **First In, First Out**
> Primero en entrar, primero en salir.

Esto representa el funcionamiento de una cola de espera.

---

# Ver próximo paciente

El botón **"Ver próximo"** permite conocer qué paciente será atendido a continuación.

Para esto se utilizó:

```cpp
colaEspera.head();
```
`head()` permitió consultar el primer paciente de la cola **sin eliminarlo**.

Por lo tanto, utilizar esta opción no modifica la lista de espera.

---

# Atención del paciente

Cuando se presiona **"Atender paciente"**, se toma al primer paciente de la cola.

Para esto se utiliza:

```cpp
Paciente atendido = colaEspera.dequeue();
```

`dequeue()` obtiene el primer elemento y lo elimina de la cola.

Después de atenderlo, el paciente se agrega a la lista de pacientes atendidos:

```cpp
listaAtendidos.append(atendido);
```

La lista se declara como:

```cpp
QList<Paciente> listaAtendidos;
```

De esta manera se conserva el orden en el que fueron atendidos los pacientes.

---

# Listas del sistema

La interfaz cuenta con dos listas principales:

### 1) Pacientes en espera

Muestra todos los pacientes que todavía no fueron atendidos, respetando el orden de llegada.

```text
1. Fatima Gonzalez | Edad: 1 | Género: F | DNI: 12345678
2. Guillermina Gonzalez Edad:2 | Género: F| DNI: 23456789
3. Geronimo Gasparetto| Edad: 3 | Género: M | DNI: 34567890
```

### 2) Pacientes atendidos

Muestra los pacientes que ya fueron atendidos, respetando el orden de atención.

```text
1. María González | Edad: 25 | Género: F | DNI: 12345678
2. Juan Pérez     | Edad: 42 | Género: M | DNI: 23456789
```

---

# Actualización de la interfaz

Cada vez que se agrega o atiende un paciente, se actualiza la información mostrada en pantalla mediante:

```cpp
actualizarListasUI();
```
Esta función:
- Recorre la cola de espera.
- Muestra los pacientes que todavía esperan.
- Recorre la lista de atendidos.
- Muestra el historial de atención.
- Actualiza el proximo paciente.
- Actualiza los contadores de pacientes.

---

# Estructura de datos del paciente

Tal como se pidió en los requerimientos del Trabajo Práctico de la cátedra, cada paciente se representa mediante la estructura:

```cpp
struct Paciente
{
    QString nombre_apellido;
    int edad;
    char genero;
    QString dni;
};
```

# Interfaz gráfica

La interfaz fue diseñada utilizando **Qt Designer**.

La ventana principal está organizada en diferentes secciones:

### Encabezado:

Contiene el nombre del sistema y el estado de la guardia.

### Admisión:

Permite ingresar los datos de un nuevo paciente.

### Próximo paciente:

Muestra quién será atendido a continuación y permite realizar la atención

### Lista de espera:

Muestra todos los pacientes pendientes de atención.

### Pacientes atendidos:

Muestra el historial de atencion

### Salir:

Permite cerrar el sistema.

---

# Organizacion del proyecto

El proyecto está compuesto por los siguientes archivos:

```text
QT-GuardiaHosp/
│
├── main.cpp
├── mainwindow.h
├── mainwindow.cpp
├── mainwindow.ui
├── QT-GuardiaHosp.pro
└── README.md
```

### `main.cpp`

Contiene la función principal del programa y el sistema de inicio de sesión.

### `mainwindow.h`

Contiene las declaraciones de la ventana principal, la estructura `Paciente`, la cola de espera y la lista de atendidos.

### `mainwindow.cpp`

Contiene la implementación de las funciones y la lógica del sistema

### `mainwindow.ui`

Contiene el diseño de la interfaz gráfica realizado con Qt designer.

### `QT-GuardiaHosp.pro`

Archivo de configuracipn del proyecto para utilizarlo con qmake.

### `README.md`

Documentación del proyecto y explicación del funcionamiento.

---

# Funcionamiento general

El funcionamiento del sistema puede resumirse de la siguiente manera:

###AÑADIR DIAGRAMA DE FLUJOI
---

# Conceptos utilizados

Durante el desarrollo se aplicaron diferentes conceptos de programación:

* Estructuras (`struct`)
* Variables y tipos de datos
* Funciones
* Condicionales `if / else`
* Ciclos `for`
* Colas (`QQueue`)
* Listas (`QList`)
* Interfaz gráfica
* Señales y slots de Qt
* Manejo de eventos mediante botones
* Mensajes mediante `QMessageBox`
* Entrada de datos mediante `QInputDialog`
* Organización de una interfaz mediante layouts

---

# Diseño de la interfaz

La interfaz utiliza una estética relacionada con el ámbito hospitalario, utilizando:

* Colores claros.
* Tonos celestes/turquesas.
* Botones diferenciados según su función.
* Bordes redondeados.
* Espaciado entre componentes
* Secciones diferenciadas.
* Diseño adaptable mediante layouts.

El objetivo es que el usuario pueda identificar rápidamente las diferentes funciones del sistema

---

# Autores: González Guillermina, González Fátima, Gasparetto Gerónimo. Especialidad: Bioingeniería

Proyecto realizado como trabajo práctico 
