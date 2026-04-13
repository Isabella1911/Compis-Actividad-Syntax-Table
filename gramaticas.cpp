#include "gramaticas.h"

// gramática 1 (dada en el lab)
GramaticaInfo gram_expresiones_aritmeticas() {
    GramaticaInfo info;
    info.nombre           = "Expresiones Aritmeticas";
    info.simbolo_inicial  = "E";
    info.terminales       = {"+", "*", "(", ")", "id"};

    info.g["E"]  = { {"T", "E'"} };
    info.g["E'"] = { {"+", "T", "E'"}, {} };   
    info.g["T"]  = { {"F", "T'"} };
    info.g["T'"] = { {"*", "F", "T'"}, {} };
    info.g["F"]  = { {"(", "E", ")"}, {"id"} };

    return info;
}

// gramática 2
GramaticaInfo gram_if_else() {
    GramaticaInfo info;
    info.nombre          = "if-else (dangling-else)";
    info.simbolo_inicial = "S";
    info.terminales      = {"if", "else", "then", "other", "b"};

    info.g["S"]  = { {"if", "E", "then", "S", "S'"}, {"other"} };
    info.g["S'"] = { {"else", "S"}, {} };
    info.g["E"]  = { {"b"} };

    return info;
}

// gramatica 3

GramaticaInfo gram_listas() {
    GramaticaInfo info;
    info.nombre          = "Listas de identificadores";
    info.simbolo_inicial = "P";
    info.terminales      = {"id", ","};

    info.g["P"] = { {"L"} };
    info.g["L"] = { {"id", "R"} };
    info.g["R"] = { {",", "id", "R"}, {} };

    return info;
}