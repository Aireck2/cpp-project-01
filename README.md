# Sistema de Registro y Gestión de Incidentes de Seguridad

Consola interactiva en C++ para el registro, consulta y análisis de incidentes de seguridad informática, basada en el caso de estudio **Capital One** (2019). Proyecto final del curso _Fundamentos de la Computación_ — USIL 2026.

## Requisitos

- Compilador con soporte **C++20** (ej. GCC 15.2.0_1)
- **CMake** 3.10 o superior

## Compilación y ejecución

```bash
# Configurar el proyecto
cmake -S . -B build

# Compilar
cmake --build build

# Ejecutar
./build/my_app
```

## Uso

Al ejecutar el programa se muestra un menú con las siguientes opciones:

```
--- GESTIÓN DE INCIDENTES ---
1. Registrar Incidente
2. Ver Todos
3. Ver Resumen
4. Salir
```

### Registrar un incidente

El programa solicita los datos del incidente: descripción, actor de amenaza, tipo y prioridad. Si la prioridad es 3 (media), permite asignar un responsable personalizado.

> [!NOTE]
> Todos los campos de texto son obligatorios. La prioridad debe ser un valor entre 1 y 3.

### Visualizar resumen

Muestra el conteo de incidentes agrupados por prioridad y el total registrado:

```
--- RESUMEN ACTUAL ---
Prioridad 1 (Crítico): 2
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
├── CMakeLists.txt
├── include/
│   ├── Incidente.hpp        # Estructura de datos y declaraciones
│   └── Validacion.hpp       # Declaraciones de funciones de validación
└── src/
    ├── main.cpp             # Punto de entrada y menú interactivo
    ├── Incidente.cpp        # Implementación de operaciones sobre incidentes
    └── Validacion.cpp       # Implementación de validaciones
```

## Módulos

| Módulo         | Archivos                           | Responsabilidad                                                                           |
| -------------- | ---------------------------------- | ----------------------------------------------------------------------------------------- |
| **Incidente**  | `Incidente.hpp`, `Incidente.cpp`   | Estructura de datos, generación de IDs, asignación de responsable y estado, visualización |
| **Validación** | `Validacion.hpp`, `Validacion.cpp` | Validación de campos obligatorios y rango de prioridad                                    |
| **Principal**  | `main.cpp`                         | Bucle del menú interactivo y coordinación de módulos                                      |

## Tecnologías

- **Lenguaje**: C++20
- **Herramienta de build**: CMake
