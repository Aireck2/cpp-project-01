#ifndef VALIDACION_HPP
#define VALIDACION_HPP

#include <string>

using namespace std;

// ── VALIDACIONES ──────────────────────────────────────

// Verifica que un campo de texto no esté vacío.
// Muestra un mensaje de error con el nombre del campo si falla.
bool validarEntrada(const string &texto, const string &nombreCampo);

// Verifica que la prioridad esté en el rango válido (1 a 3).
bool validarPrioridad(int prioridad);

#endif
