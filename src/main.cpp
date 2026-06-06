// ─────────────────────────────────────────────────────
// Sistema de Registro y Gestión de Incidentes de Seguridad
// Caso de estudio: Capital One
// Curso: Fundamentos de la Computación — USIL 2026
// ─────────────────────────────────────────────────────
// Punto de entrada del programa. Implementa un menú
// interactivo en consola para gestionar incidentes.
// Usa un vector<Incidente> como base de datos en memoria
// y un bucle while para mantener el menú activo.
// ─────────────────────────────────────────────────────

#include "Incidente.hpp"
#include "Validacion.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // ── BASE DE DATOS EN MEMORIA ──────────────────────
  // Vector dinámico que almacena todos los incidentes registrados
  // durante la sesión. Se pierde al cerrar el programa.
  vector<Incidente> baseDatos;

  int opcion = 0;            // Opción seleccionada por el usuario en el menú.
  int contadorGlobal = 0;    // Contador incremental para generar IDs únicos.
  bool sistemaActivo = true; // Controla la ejecución del bucle principal.

  // ── BUCLE PRINCIPAL ────────────────────────────────
  // Se ejecuta hasta que el usuario elija la opción "Salir" (4).
  while (sistemaActivo) {
    // Menú principal: se muestra en cada iteración.
    cout << "\n--- GESTIÓN DE INCIDENTES ---\n";
    cout << "1. Registrar Incidente\n2. Ver Todos\n3. Ver Resumen\n4. "
            "Salir\n>> ";
    cin >> opcion;
    cin.ignore(); // Limpia el buffer para evitar interferencias con getline().

    switch (opcion) {
    case 1: {
      // ── REGISTRO DE NUEVO INCIDENTE ────────────────
      // Captura los datos del incidente desde la entrada estándar.
      Incidente nuevo;

      cout << "Descripción de Vulnerabilidad: ";
      getline(cin,
              nuevo.descripcion); // getline permite leer textos con espacios.

      cout << "Actor de Amenaza: ";
      getline(cin, nuevo.actorAmenaza);

      cout << "Tipo (INTERNA/EXTERNA): ";
      getline(cin, nuevo.tipoAmenaza);

      cout << "Prioridad (1-3): ";
      cin >> nuevo.prioridad;
      cin.ignore();

      // Validación: si algún campo obligatorio está vacío o la prioridad
      // es inválida, el incidente no se registra.
      if (validarEntrada(nuevo.descripcion, "Descripción") &&
          validarEntrada(nuevo.actorAmenaza, "Actor") &&
          validarEntrada(nuevo.tipoAmenaza, "Tipo") &&
          validarPrioridad(nuevo.prioridad)) {

        contadorGlobal++;
        nuevo.id = generarID(nuevo.prioridad, contadorGlobal);
        nuevo.responsable = asignarResponsable(nuevo.prioridad, "");
        nuevo.estado = asignarEstado(nuevo.prioridad);
        nuevo.fecha =
            "2026-05-15"; // TODO: Reemplazar con fecha actual del sistema.

        // Para prioridad 3 (medio), se permite asignar un responsable
        // personalizado.
        if (nuevo.prioridad == 3) {
          cout << "Asignar Responsable específico: ";
          getline(cin, nuevo.responsable);
        }

        baseDatos.push_back(nuevo);
        cout << "[OK] Incidente registrado correctamente.\n";
        mostrarIncidente(nuevo);
      }
      break;
    }

    case 2:
      // ── LISTAR TODOS ───────────────────────────────
      mostrarTodos(baseDatos);
      break;

    case 3:
      // ── RESUMEN ESTADÍSTICO ─────────────────────────
      mostrarResumen(baseDatos);
      break;

    case 4:
      // ── SALIR ───────────────────────────────────────
      sistemaActivo = false;
      break;

    default:
      cout << "[!] Opción no válida.\n";
    }
  }

  return 0;
}
