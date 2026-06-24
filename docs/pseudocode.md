## FUNCION PRINCIPAL

```dart
VARIABLES

    TIPO Incidente

      string id, descripcion, actorAmenaza

      string tipoAmenaza

      string responsable, estado, fecha

      entero prioridad

    FIN_TIPO



    Incidente[] baseDatos

    entero opcion, contadorGlobal = 0

    booleano sistemaActivo = Verdadero

    registro Incidente nuevo



INICIO

    MIENTRAS sistemaActivo == Verdadero HACER

        ESCRIBIR "1. Registrar, 2. Ver Todos, 3. Ver Resumen, 4. Salir"

        LEER opcion

            SEGUN opcion HACER

                1:

                    LEER nuevo.descripcion, nuevo.actorAmenaza, nuevo.tipoAmenaza, nuevo.prioridad



                    SI validarEntrada(nuevo.descripcion) Y validarEntrada(nuevo.actorAmenaza) Y

                       validarEntrada(nuevo.tipoAmenaza) Y validarPrioridad(nuevo.prioridad) ENTONCES



                        contadorGlobal = contadorGlobal + 1

                        nuevo.id = generarID(nuevo.prioridad, contadorGlobal)

                        nuevo.responsable = asignarResponsable(nuevo.prioridad, "")

                        nuevo.estado = asignarEstado(nuevo.prioridad)

                        nuevo.fecha = "2026-05-15"



                        SI nuevo.prioridad == 3 ENTONCES

                            LEER nuevo.responsable

                        FIN_SI



                        agregarNuevoIncidenteABaseDatos()

                        mostrarIncidente(nuevo)

                    FIN_SI



                2:

                  mostrarTodos(baseDatos)



                3:

                  mostrarResumen(baseDatos)



                4:

                  sistemaActivo = Falso



                DE OTRO MODO:

                    ESCRIBIR "Opción no válida"

            FIN_SEGUN

    FIN_MIENTRAS

FIN
```

## DECLARACIONES DE FUNCIONES

```dart
FUNCION generarID(p: entero, c: entero) : string

    VARIABLES

        string relleno

    INICIO

        SI c < 10 ENTONCES

            relleno = "00"

        SI NO

            SI c < 100 ENTONCES

                relleno = "0"

            SI NO

                relleno = ""

            FIN_SI

        FIN_SI



        generarID = "INC-P" + p + "-" + relleno + c

    FIN

FIN_FUNCION
```

```dart

FUNCION asignarResponsable(p: entero, r: string) : string

    INICIO

        SI r != "" ENTONCES

            asignarResponsable = r

        SI_NO

            SI p == 1 ENTONCES

                asignarResponsable = "Equipo SOC N3"

            SI_NO

                SI p == 2 ENTONCES

                    asignarResponsable = "Equipo SOC N1"

                SI_NO

                    asignarResponsable = r

                FIN_SI

            FIN_SI

        FIN_SI

    FIN

FIN_FUNCION
```

```dart
FUNCION asignarEstado(p: entero) : string

    INICIO

        SEGUN p HACER

            1: asignarEstado = "En Curso/Asignado"

            DE OTRO MODO: asignarEstado = "Pendiente"

        FIN_SEGUN

    FIN

FIN_FUNCION
```

```dart

FUNCION validarEntrada(texto: string, campo: string) : booleano

    INICIO

        SI texto == "" ENTONCES

            ESCRIBIR "[!] El campo ", campo, " es obligatorio."

            validarEntrada = Falso

        SI NO

            validarEntrada = Verdadero

        FIN_SI

    FIN

FIN_FUNCION
```

```dart

FUNCION validarPrioridad(p: entero) : booleano

    INICIO

        SI p >= 1 Y p <= 3 ENTONCES

            validarPrioridad = Verdadero

        SI NO

            validarPrioridad = Falso

        FIN_SI

    FIN

FIN_FUNCION

```

```dart
PROCEDIMIENTO mostrarIncidente(i: Incidente)

    INICIO

        ESCRIBIR i.id, i.estado

        ESCRIBIR i.tipoAmenaza, i.prioridad

        ESCRIBIR i.descripcion

        ESCRIBIR i.actorAmenaza, i.responsable

    FIN

FIN_PROCEDIMIENTO

```

```dart

PROCEDIMIENTO mostrarTodos(lista: Incidente[])

    INICIO

        SI lista esta vacía ENTONCES

            ESCRIBIR "No hay incidentes registrados."

        SI NO

            PARA CADA incidente EN lista HACER

                mostrarIncidente(incidente)

            FIN_PARA

        FIN_SI

    FIN

FIN_PROCEDIMIENTO
```

```dart
PROCEDIMIENTO mostrarResumen(lista: Incidente[])

    VARIABLES

        entero p1, p2, p3

        Incidente i

    INICIO

        p1 = 0, p2 = 0, p3 = 0

        PARA CADA i EN lista HACER

            SI i.prioridad == 1 ENTONCES

                p1 = p1 + 1

            SI_NO

                SI i.prioridad == 2 ENTONCES

                    p2 = p2 + 1

                SI_NO

                    SI i.prioridad == 3 ENTONCES

                        p3 = p3 + 1

                    FIN_SI

                FIN_SI

            FIN_SI

        FIN_PARA

        ESCRIBIR "--- RESUMEN ACTUAL ---"

        ESCRIBIR "Prioridad 1 (Crítico): ", p1

        ESCRIBIR "Prioridad 2 (Alto): ", p2

        ESCRIBIR "Prioridad 3 (Medio): ", p3

        ESCRIBIR "Total de incidentes: ", LENGTH(lista)

    FIN

FIN_PROCEDIMIENTO
```
