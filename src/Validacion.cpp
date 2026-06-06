#include "Validacion.hpp"
#include <iostream>
#include <string>

using namespace std;

// ── VALIDACIÓN DE CAMPO DE TEXTO ──────────────────────
// Retorna true si el texto no está vacío.
// En caso contrario, muestra un mensaje de error indicando
// el nombre del campo que falló la validación.
bool validarEntrada(const string &texto, const string &campo) {
  if (texto.empty()) {
    cout << "[!] El campo " << campo << " es obligatorio.\n";
    return false;
  }
  return true;
}

// ── VALIDACIÓN DE PRIORIDAD ───────────────────────────
// La prioridad debe ser un entero entre 1 y 3 (inclusive).
bool validarPrioridad(int p) { return (p >= 1 && p <= 3); }
