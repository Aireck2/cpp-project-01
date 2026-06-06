#include "Incidente.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ── GENERACIÓN DE ID ─────────────────────────────────
// Construye un identificador único con formato "INC-P{prioridad}-{contador}".
// El contador se rellena con ceros a la izquierda para mantener
// un ancho de 3 dígitos (001, 042, 999).
string generarID(int p, int c) {
  string relleno = (c < 10) ? "00" : (c < 100 ? "0" : "");
  return "INC-P" + to_string(p) + "-" + relleno + to_string(c);
}

// ── ASIGNACIÓN DE RESPONSABLE ────────────────────────
// Define el equipo SOC encargado según la prioridad:
//   Prioridad 1 (Crítico) → Equipo SOC N3
//   Prioridad 2 (Alto)    → Equipo SOC N1
//   Prioridad 3 (Medio)   → Responsable personalizado (se pasa por parámetro).
// Si recibe un nombre personalizado (r), lo usa antes de aplicar la regla de prioridad.
string asignarResponsable(int p, string r) {
  string responsable;
  if (!r.empty())
    responsable = r;
  if (p == 1)
    responsable = "Equipo SOC N3";
  if (p == 2)
    responsable = "Equipo SOC N1";
  return responsable;
}

// ── ASIGNACIÓN DE ESTADO ──────────────────────────────
// Determina el estado inicial del incidente:
//   Prioridad 1 → "En Curso/Asignado" (se atiende de inmediato).
//   Prioridad 2 o 3 → "Pendiente" (entra en cola de espera).
string asignarEstado(int p) {
  switch (p) {
  case 1:
    return "En Curso/Asignado";
  default:
    return "Pendiente";
  }
}

// ── VISUALIZACIÓN DE INCIDENTE ────────────────────────
// Imprime en consola todos los campos de un incidente
// con un formato delimitado por guiones para facilitar la lectura.
void mostrarIncidente(const Incidente &i) {
  cout << "------------------------------------------\n";
  cout << "ID: " << i.id << " | Estado: " << i.estado << "\n";
  cout << "Tipo: " << i.tipoAmenaza << " | Prioridad: " << i.prioridad << "\n";
  cout << "Vulnerabilidad: " << i.descripcion << "\n";
  cout << "Actor: " << i.actorAmenaza << " | Responsable: " << i.responsable
       << "\n";
  cout << "------------------------------------------\n";
}

// ── LISTADO COMPLETO ──────────────────────────────────
// Recorre todo el vector de incidentes y muestra cada uno.
// Si el vector está vacío, lo indica con un mensaje.
void mostrarTodos(const vector<Incidente> &lista) {
  if (lista.empty())
    cout << "No hay incidentes registrados.\n";
  for (const auto &incidente : lista)
    mostrarIncidente(incidente);
}

// ── RESUMEN ESTADÍSTICO ───────────────────────────────
// Cuenta los incidentes agrupados por prioridad (1, 2, 3)
// y muestra el total registrado. No modifica los datos.
void mostrarResumen(const vector<Incidente> &lista) {
  int p1 = 0, p2 = 0, p3 = 0;
  for (const auto &i : lista) {
    if (i.prioridad == 1)
      p1++;
    else if (i.prioridad == 2)
      p2++;
    else if (i.prioridad == 3)
      p3++;
  }
  cout << "\n--- RESUMEN ACTUAL ---\n";
  cout << "Prioridad 1 (Crítico): " << p1 << "\n";
  cout << "Prioridad 2 (Alto):    " << p2 << "\n";
  cout << "Prioridad 3 (Medio):   " << p3 << "\n";
  cout << "Total de incidentes:   " << lista.size() << "\n";
}
