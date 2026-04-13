#pragma once
#include "tipos.h"

struct GramaticaInfo {
    std::string nombre;
    Gramatica g;
    std::string simbolo_inicial;
    std::set<std::string> terminales;
};

// gramatica 1 
GramaticaInfo gram_expresiones_aritmeticas();

// gramatica 2
GramaticaInfo gram_if_else();

// gramatica 3
GramaticaInfo gram_listas();