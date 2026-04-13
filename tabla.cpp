#include "tabla.h"
 
ResultadoTabla construir_tabla(
    const Gramatica& g,
    const ConjuntosSimbolos& first,
    const ConjuntosSimbolos& follow)
{
    ResultadoTabla res;
    res.es_ll1 = true;
 
    
    std::map<std::string, std::map<std::string, std::vector<std::string>>> tabla_raw;
 
    for (const auto& [nt, producciones] : g) {
        for (const auto& prod : producciones) {
 
            std::string prod_str = produccion_a_str(nt, prod);
            std::set<std::string> first_alpha = first_de_secuencia(prod, first, g);
 
            for (const auto& a : first_alpha) {
                if (a != EPSILON)
                    tabla_raw[nt][a].push_back(prod_str);
            }
 
            if (first_alpha.count(EPSILON)) {
                auto it = follow.find(nt);
                if (it != follow.end()) {
                    for (const auto& b : it->second)
                        tabla_raw[nt][b].push_back(prod_str);
                }
            }
        }
    }
 
    //  armar tabla final
    for (const auto& [nt, cols] : tabla_raw) {
        for (const auto& [term, prods] : cols) {
            if (prods.size() > 1) {
                res.es_ll1 = false;
 
                std::string conflicto = "Conflicto en [" + nt + ", " + term + "]: ";
                for (size_t i = 0; i < prods.size(); ++i) {
                    if (i > 0) conflicto += "  |  ";
                    conflicto += prods[i];
                }
                res.conflictos.push_back(conflicto);

                res.tabla[nt][term] = prods[0] + " [CONFLICTO]";
            } else {
                res.tabla[nt][term] = prods[0];
            }
        }
    }
 
    return res;
}