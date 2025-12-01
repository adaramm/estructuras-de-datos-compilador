#pragma once
#include "TypeTable.hpp"
#include <algorithm>

class TypeManager {
public:
    // Prioridad para determinar tipo mayor
    static int priority(const TypeTable &TT, int typeId) {
        const auto &t = TT.get(typeId);
        if (t.name == "char") return 1;
        if (t.name == "int")  return 2;
        if (t.name == "float")return 3;
        return 0;
    }

  // Las funciones estáticas se implementan en el .hpp
    // Devuelve el tipo mayor
    static int maxType(const TypeTable &TT, int t1, int t2) ;

    // Devuelve el tipo menor
    static int minType(const TypeTable &TT, int t1, int t2);

    // Ampliar: convertir tipo pequeño → mayor
    static int ampliar(int dir, int tipo1, int tipo2);

    // Reducir: convertir tipo grande → menor (requiere cuidado)
    static int reducir(int dir, int tipo1, int tipo2);
};
