#ifndef INCIDENTE_HPP
#define INCIDENTE_HPP

#include <string>
#include <vector>

using namespace std;

// ── ESTRUCTURA INCIDENTE ─────────────────────────────
// Representa un incidente de seguridad con todos sus
// atributos: identificación, descripción, actor de amenaza,
// tipo (interna/externa), responsable, estado, fecha y prioridad.
struct Incidente {
  string id, descripcion, actorAmenaza;
  string tipoAmenaza;
  string responsable, estado, fecha;
  int prioridad;
};

// ── DECLARACIONES DE FUNCIONES ────────────────────────

// Genera un ID único con formato INC-P{prioridad}-{contador}.
string generarID(int prioridad, int contador);

// Asigna un responsable al incidente según su prioridad.
// Si 'personalizado' no está vacío, se usa ese valor.
string asignarResponsable(int prioridad, string personalizado);

// Determina el estado inicial del incidente basado en la prioridad.
string asignarEstado(int prioridad);

// Muestra por consola los detalles completos de un incidente.
void mostrarIncidente(const Incidente &incidente);

// Itera sobre el vector y muestra todos los incidentes registrados.
void mostrarTodos(const vector<Incidente> &lista);

// Calcula y muestra un resumen estadístico por prioridad.
void mostrarResumen(const vector<Incidente> &lista);

#endif
