# SISTEMA DE GUARDIA HOSPITALARIA

Trabajo realizado por Gasparetto Gerónimo, González Fátima y González Guillermina

Este proyecto es un sistema para organizar los turnos de una guardia hospitalaria, la idea del programa es cargar pacientes y atenderlos según el orden en el que llegaron. 

Fue hecho en C++ usando Qt Creator y Qt Designer para armar la interfaz.

## Se puede hacer:

- Ingresar al sistema con usuario y contraseña.
- Cargar un paciente con sus datos.
- Ver los pacientes que todavía no fueron atendidos.
- Consultar quién es el próximo paciente.
- Atender al primero de la cola.
- Ver la lista de pacientes que ya fueron atendidos.
- Salir del programa.

## Inicio de sesión

Cuando se abre el programa se pide un usuario y una contraseña.

```text
Usuario: grupo2
Contraseña: utnfrh
```

El usuario se tiene que escribir en minúsculas y sin espacios. Si alguno de los dos datos es incorrecto aparece un mensaje de acceso denegado y el programa se cierra.

## Ingreso de pacientes

En la parte **Ingreso de paciente** se completan estos datos:

- Nombre y apellido.
- Edad.
- Género.
- DNI.

La edad tiene que ser mayor que cero y el DNI acepta solamente números, con un máximo de 8 dígitos, después se presiona el botón **Admitir paciente**. Si falta algún dato aparece una advertencia sino el paciente se agrega al final de la cola y los campos quedan vacíos para poder cargar otro.

## Funcionamiento general

El programa primero pide el usuario y la contraseña. Si los datos son correctos, se abre la ventana principal.

Desde esa ventana se puede cargar un paciente. El programa controla que estén completos el nombre, la edad, el género y el DNI. Después lo agrega al final de la cola y actualiza las listas de la pantalla.

El botón **Ver próximo** muestra al primer paciente sin sacarlo de la cola. El botón **Atender** sí lo saca y lo guarda en la lista de pacientes atendidos. Si la cola está vacía, se muestra un mensaje avisando que no hay pacientes.

El proceso se puede repetir todas las veces que sea necesario hasta que se presione el botón **Salir**.

## Interfaz

La ventana fue armada con Qt Designer y está separada en partes simples:

- Ingreso de paciente.
- Próximo paciente.
- Pacientes sin atender.
- Pacientes atendidos.
- Botón para salir.

Para la interfaz usamos colores claros, como turquesa y verde, porque nos parecieron acordes al ambiente de un hospital. Los textos lo colocamos en negro para que se pudieran leer bien. 

## Archivos del proyecto

- `main.cpp`: inicia el programa, pide el usuario y la contraseña y abre la ventana principal.
- `mainwindow.h`: declara la ventana, la estructura `Paciente`, la cola y la lista de atendidos.
- `mainwindow.cpp`: contiene las funciones de los botones y la lógica del programa.
- `mainwindow.ui`: guarda el diseño de la interfaz hecho con Qt Designer.
- `QT-GuardiaHosp.pro`: configura el proyecto para compilarlo con qmake.
- `README.md`: explica de manera general cómo funciona el trabajo.

## Conceptos usados

- Estructuras (`struct`).
- Variables y tipos de datos.
- Funciones.
- Condicionales `if`.
- Ciclos `for`.
- Cola `QQueue`.
- Lista `QList`.
- Señales y slots de Qt.
- Mensajes con `QMessageBox`.
- Entrada de datos con `QInputDialog`.
- Organización de la interfaz con layouts.
