
#include "gramaticas.h"
#include "first.h"
#include "follow.h"
#include "tabla.h"
#include "impresion.h"
 
// Procesa una gramática 
void analizar(const GramaticaInfo& info) {
    imprimir_gramatica(info.g, info.nombre);
 
    ConjuntosSimbolos first  = calcular_first(info.g);
    ConjuntosSimbolos follow = calcular_follow(info.g, first, info.simbolo_inicial);
 
    imprimir_first_follow(info.g, first, follow);
 
    ResultadoTabla res = construir_tabla(info.g, first, follow);
    imprimir_tabla(res, info.g, info.terminales);
 
    std::cout << "\n";
}
 
int main() {

    std::cout << "// main de Firts, Follow y Tabla de analisis sintactico LL(1) //\n";
 
    analizar(gram_expresiones_aritmeticas());   // gramatica 1 — LL(1)
    analizar(gram_if_else());                   // gramatica 2 — NO LL(1)
    analizar(gram_listas());                    // gramatica 3 — LL(1)
 
    return 0;
}
