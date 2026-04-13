#pragma once
#include "tipos.h"
#include "first.h"
#include "follow.h"
 
struct ResultadoTabla {
    TablaSintactica tabla;
    bool es_ll1;
    std::vector<std::string> conflictos;
};
 
ResultadoTabla construir_tabla(
    const Gramatica& g,
    const ConjuntosSimbolos& first,
    const ConjuntosSimbolos& follow);