<div align="center">

# Sistema de Registro y Gestion de Incidentes de Seguridad

[![C++20](https://img.shields.io/badge/C++-20-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://en.cppreference.com/w/cpp/20)
[![CMake](https://img.shields.io/badge/CMake-3.10+-064F8C?style=flat-square&logo=cmake&logoColor=white)](https://cmake.org)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)](LICENSE)

Consola interactiva en C++ para el registro, consulta y analisis de incidentes de seguridad informatica.

Basado en el caso de estudio **Capital One (2019)** &mdash; Proyecto final del curso _Fundamentos de la Computacion_ &mdash; USIL 2026.

[Caracteristicas](#caracteristicas) • [Comenzando](#comenzando) • [Uso](#uso) • [Documentacion](#documentacion) • [Estructura](#estructura-del-proyecto)

</div>

---

## Caracteristicas

- **Registro de incidentes** con validacion de campos obligatorios y prioridad (1-3)
- **Asignacion automatica** de equipo SOC responsable segun la prioridad del incidente
- **Estados iniciales** diferenciados: prioridad critica inicia como "En Curso/Asignado", las demas como "Pendiente"
- **Identificacion unica** con formato `INC-P{prioridad}-{contador}` (ej. `INC-P1-001`)
- **Responsable personalizado** para incidentes de prioridad media (3)
- **Listado completo** de todos los incidentes registrados
- **Resumen estadistico** con conteo por nivel de prioridad
- **Validacion de entrada** en todos los campos obligatorios

## Comenzando

### Requisitos

- Compilador con soporte **C++20** (ej. GCC 15.2.0_1)
- **CMake** 3.10 o superior

### Compilacion y ejecucion

```bash
# Configurar el proyecto
cmake -S . -B build

# Compilar
cmake --build build

# Ejecutar
./build/my_app
```

## Uso

Al ejecutar el programa se muestra un menu con las siguientes opciones:

```
--- GESTION DE INCIDENTES ---
1. Registrar Incidente
2. Ver Todos
3. Ver Resumen
4. Salir
```

### Registrar un incidente

El programa solicita los datos del incidente: descripcion, actor de amenaza, tipo y prioridad. Si la prioridad es 3 (media), permite asignar un responsable personalizado.

> [!NOTE]
> Todos los campos de texto son obligatorios. La prioridad debe ser un valor entre 1 y 3.

### Visualizar resumen

Muestra el conteo de incidentes agrupados por prioridad y el total registrado:

```
--- RESUMEN ACTUAL ---
Prioridad 1 (Critico): 2
Prioridad 2 (Alto):    1
Prioridad 3 (Medio):   3
Total de incidentes:   6
```

## Funcionalidades

- **Registro de incidentes** con validación de campos obligatorios y prioridad (1-3)
- **Asignación automática** de equipo SOC responsable según la prioridad del incidente
- **Estados iniciales** diferenciados: prioridad crítica inicia como "En Curso/Asignado", las demás como "Pendiente"
- **Identificación única** con formato `INC-P{prioridad}-{contador}` (ej. `INC-P1-001`)
- **Listado completo** de todos los incidentes registrados
- **Resumen estadístico** con conteo por nivel de prioridad

## Estructura del proyecto

```
├── CMakeLists.txt               # Configuracion de build con CMake
├── CHANGELOG.md                 # Registro de cambios
├── assets/                      # Diagramas de flujo (.png)
├── docs/                        # Pseudocodigo y Documentacion de diagramas de flujo
├── include/
│   ├── Incidente.hpp            # Estructura de datos y declaraciones
│   └── Validacion.hpp           # Declaraciones de funciones de validacion
└── src/
    ├── main.cpp                 # Punto de entrada y menu interactivo
    ├── Incidente.cpp            # Implementacion de operaciones sobre incidentes
    └── Validacion.cpp           # Implementacion de validaciones
```

### Modulos

| Modulo         | Archivos                           | Responsabilidad                                                                           |
| -------------- | ---------------------------------- | ----------------------------------------------------------------------------------------- |
| **Incidente**  | `Incidente.hpp`, `Incidente.cpp`   | Estructura de datos, generacion de IDs, asignacion de responsable y estado, visualizacion |
| **Validacion** | `Validacion.hpp`, `Validacion.cpp` | Validacion de campos obligatorios y rango de prioridad                                    |
| **Principal**  | `main.cpp`                         | Bucle del menu interactivo y coordinacion de modulos                                      |

## Documentacion

Este proyecto incluye documentacion complementaria en el directorio `docs/`:

| Documento                                  | Descripcion                                                                 |
| ------------------------------------------ | --------------------------------------------------------------------------- |
| [Diagramas de flujo](docs/flow-diagram.md) | Diagramas visuales de la logica de cada funcion del programa                |
| [Pseudocodigo](docs/pseudocode.md)         | Pseudocodigo completo en sintaxis Dart de todas las funciones implementadas |

Los diagramas de flujo cubren: flujo principal, generacion de ID, validacion de entrada, validacion de prioridad, asignacion de responsable, asignacion de estado, visualizacion de incidentes, listado completo y resumen estadistico.

## Tecnologias

- **Lenguaje**: C++20
- **Herramienta de build**: CMake
