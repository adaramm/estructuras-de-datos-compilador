#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <optional>

enum class BaseType {
    NONE,
    INT,
    FLOAT,
    CHAR,
    BOOL,
    STRUCT,
    ARRAY
};

struct TypeEntry {
    int id;                     // Id único
    std::string name;           // Ej: int, float, matriz, persona
    int size;                   // Tamaño total en bytes
    int items = 1;           // Para arrays
    int baseTypeId = -1;        // Tipo base si es array o struct 
    SymbolTable *structField = nullptr;
};

class TypeTable {
private:
    std::vector<TypeEntry> types; // Almacén de tipos
    int lastId = 0;

public:
    TypeTable();

    int addType(const std::string& name, int size, int elements = 1, int baseTypeId = -1);
    int addType(const std::string& name, int size, int elements = 1, int baseTypeId -1, SymbolTable *base );

    const TypeEntry& get(int id) const;
    string getName(int);
    int getTam(int);
    int getNumItems(int);
    int getBaseType(int);
    SymbolTable getBaseTypeST(int);
    void print() const;
};
