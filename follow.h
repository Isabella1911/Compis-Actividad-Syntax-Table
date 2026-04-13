#pragma once
#include "tipos.h"
#include "first.h"
 
// sigue las reglas de follow
ConjuntosSimbolos calcular_follow(
    const Gramatica& g,
    const ConjuntosSimbolos& first,
    const std::string& simbolo_inicial);
 