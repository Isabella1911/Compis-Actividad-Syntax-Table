#pragma once
#include "tipos.h"
#include "tabla.h"
 

void imprimir_gramatica(const Gramatica& g, const std::string& nombre);
 

void imprimir_first_follow(
    const Gramatica& g,
    const ConjuntosSimbolos& first,
    const ConjuntosSimbolos& follow);
 

void imprimir_tabla(
    const ResultadoTabla& res,
    const Gramatica& g,
    const std::set<std::string>& terminales);