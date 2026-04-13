#include "impresion.h"
 
void imprimir_gramatica(const Gramatica& g, const std::string& nombre) {
    std::cout << "// Gramatica: " << std::left << std::setw(25) << nombre << "//\n";
 
    for (const auto& [nt, prods] : g) {
        for (size_t i = 0; i < prods.size(); ++i) {
            if (i == 0)
                std::cout << "  " << nt << " -> ";
            else
                std::cout << "  " << std::string(nt.size(), ' ') << "  | ";
 
            if (prods[i].empty()) {
                std::cout << EPSILON;
            } else {
                for (size_t j = 0; j < prods[i].size(); ++j) {
                    if (j > 0) std::cout << " ";
                    std::cout << prods[i][j];
                }
            }
            std::cout << "\n";
        }
    }
}
 
void imprimir_first_follow(
    const Gramatica& g,
    const ConjuntosSimbolos& first,
    const ConjuntosSimbolos& follow)
{

    std::cout << "  FIRST y FOLLOW\n";
    std::cout << std::left
              << std::setw(8)  << "NT"
              << std::setw(32) << "FIRST"
              << "FOLLOW\n";
    std::cout << std::string(72, '-') << "\n";
 
    for (const auto& [nt, _] : g) {
        //first
        std::ostringstream f1;
        f1 << "{ ";
        bool fst = true;
        for (const auto& s : first.at(nt)) {
            if (!fst) f1 << ", ";
            f1 << s;
            fst = false;
        }
        f1 << " }";
 
        //follow
        std::ostringstream f2;
        f2 << "{ ";
        fst = true;
        for (const auto& s : follow.at(nt)) {
            if (!fst) f2 << ", ";
            f2 << s;
            fst = false;
        }
        f2 << " }";
 
        std::cout << std::left
                  << std::setw(8)  << nt
                  << std::setw(32) << f1.str()
                  << f2.str() << "\n";
    }
}
 
void imprimir_tabla(
    const ResultadoTabla& res,
    const Gramatica& g,
    const std::set<std::string>& terminales)
{
    std::cout << "  Tabla de Analisis sintactico LL(1)\n";
    std::set<std::string> cols = terminales;
    cols.insert(FIN);
 
    const int COL_NT   = 6;
    const int COL_TERM = 20;
 
    std::cout << std::left << std::setw(COL_NT) << "NT" << " | ";
    for (const auto& t : cols)
        std::cout << std::setw(COL_TERM) << t << " | ";
    std::cout << "\n";
    std::cout << std::string(COL_NT + (COL_TERM + 3) * (int)cols.size() - 4, '-') << "\n";
 
    // Filas
    for (const auto& [nt, _] : g) {
        std::cout << std::left << std::setw(COL_NT) << nt << " | ";
        for (const auto& t : cols) {
            auto it_nt = res.tabla.find(nt);
            if (it_nt != res.tabla.end()) {
                auto it_t = it_nt->second.find(t);
                if (it_t != it_nt->second.end()) {
                    std::cout << std::setw(COL_TERM) << it_t->second << " | ";
                    continue;
                }
            }
            std::cout << std::setw(COL_TERM) << "" << " | ";
        }
        std::cout << "\n";
    }
 
    
    std::cout << "\n";
    if (res.es_ll1) {
        std::cout << "  La gramatica si ES LL(1) (sin conflictos)\n";
    } else {
        std::cout << "  La gramatica NO es LL(1). Conflictos encontrados:\n";
        for (const auto& c : res.conflictos)
            std::cout << "    - " << c << "\n";
    }
}