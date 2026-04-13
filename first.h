#pragma once
#include "tipos.h"
 
// Calcula first para todos los no terminales 

ConjuntosSimbolos calcular_first(const Gramatica& g);
 
// FIRST de una secuencia 

std::set<std::string> first_de_secuencia(
    const Produccion& seq,
    const ConjuntosSimbolos& first,
    const Gramatica& g);