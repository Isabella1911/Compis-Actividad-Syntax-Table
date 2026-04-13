#include "follow.h"
 
ConjuntosSimbolos calcular_follow(
    const Gramatica& g,
    const ConjuntosSimbolos& first,
    const std::string& simbolo_inicial)
{
    ConjuntosSimbolos follow;
    for (const auto& [nt, _] : g)
        follow[nt] = {};
 
   
    follow[simbolo_inicial].insert(FIN);
 
    bool cambio = true;
    while (cambio) {
        cambio = false;
 
        for (const auto& [nt, producciones] : g) {
            for (const auto& prod : producciones) {
                for (size_t i = 0; i < prod.size(); ++i) {
                    const std::string& sym = prod[i];
                        //reglas follow
                    if (!es_no_terminal(sym, g)) continue;

                    Produccion beta(prod.begin() + i + 1, prod.end());
 
                    std::set<std::string> first_beta =
                        first_de_secuencia(beta, first, g);
 
                    for (const auto& f : first_beta) {
                        if (f != EPSILON && !follow[sym].count(f)) {
                            follow[sym].insert(f);
                            cambio = true;
                        }
                    }
 
                    if (first_beta.count(EPSILON)) {
                        for (const auto& f : follow[nt]) {
                            if (!follow[sym].count(f)) {
                                follow[sym].insert(f);
                                cambio = true;
                            }
                        }
                    }
                }
            }
        }
    }
 
    return follow;
}