#include "first.h"
 
ConjuntosSimbolos calcular_first(const Gramatica& g) {
    ConjuntosSimbolos first;
 
    
    for (const auto& [nt, _] : g)
        first[nt] = {};
 
    bool cambio = true;
    while (cambio) {
        cambio = false;
 
        for (const auto& [nt, producciones] : g) {
            for (const auto& prod : producciones) {
 
                
                if (prod.empty()) {
                    if (!first[nt].count(EPSILON)) {
                        first[nt].insert(EPSILON);
                        cambio = true;
                    }
                    continue;
                }
 
                bool todos_derivan_epsilon = true;
 
                for (const auto& sym : prod) {
                    if (!es_no_terminal(sym, g)) {
                        
                        if (!first[nt].count(sym)) {
                            first[nt].insert(sym);
                            cambio = true;
                        }
                        todos_derivan_epsilon = false;
                        break;
                    }
 
                    
                    for (const auto& f : first[sym]) {
                        if (f != EPSILON && !first[nt].count(f)) {
                            first[nt].insert(f);
                            cambio = true;
                        }
                    }
 
                    
                    if (!first[sym].count(EPSILON)) {
                        todos_derivan_epsilon = false;
                        break;
                    }
                }
 
                
                if (todos_derivan_epsilon && !first[nt].count(EPSILON)) {
                    first[nt].insert(EPSILON);
                    cambio = true;
                }
            }
        }
    }
 
    return first;
}
 

std::set<std::string> first_de_secuencia(
    const Produccion& seq,
    const ConjuntosSimbolos& first,
    const Gramatica& g)
{
    std::set<std::string> resultado;
 
    if (seq.empty()) {
        resultado.insert(EPSILON);
        return resultado;
    }
 
    bool todos_epsilon = true;
 
    for (const auto& sym : seq) {
        if (!es_no_terminal(sym, g)) {
            resultado.insert(sym);
            todos_epsilon = false;
            break;
        }
 
        auto it = first.find(sym);
        if (it != first.end()) {
            for (const auto& f : it->second)
                if (f != EPSILON) resultado.insert(f);
 
            if (!it->second.count(EPSILON)) {
                todos_epsilon = false;
                break;
            }
        } else {
            todos_epsilon = false;
            break;
        }
    }
 
    if (todos_epsilon) resultado.insert(EPSILON);
    return resultado;
}