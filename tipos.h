#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using Produccion = std::vector<std::string>;

using Gramatica = std::map<std::string, std::vector<Produccion>>;

using ConjuntosSimbolos = std::map<std::string, std::set<std::string>>;

using TablaSintactica = std::map<std::string, std::map<std::string, std::string>>;
 
inline const std::string EPSILON = "ε";
inline const std::string FIN     = "$";
 
inline bool es_no_terminal(const std::string& sym, const Gramatica& g) {
    return g.count(sym) > 0;
}
 
inline std::string produccion_a_str(const std::string& nt, const Produccion& prod) {
    std::string res = nt + " -> ";
    if (prod.empty()) return res + EPSILON;
    for (size_t i = 0; i < prod.size(); ++i) {
        if (i > 0) res += " ";
        res += prod[i];
    }
    return res;
}