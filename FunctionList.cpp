#include "FunctionList.h"
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

vector<ClassInstance> classInstances;

FunctionInfo* FunctionList::getFunction(const char *name)
{
    string funcName = string(name);
    for (auto &func : functions)
    {
        if (func.name == funcName)
        {
            return &func;  // Returnează un pointer către funcția găsită
        }
    }
    return nullptr;  // Returnează nullptr dacă funcția nu este găsită
}


void FunctionList::addFunction(FunctionInfo funcInfo)
{
    if (funcInfo.isMethod) {
        funcInfo.scope = funcInfo.className; // Setează domeniul de aplicare la numele clasei pentru metode
         
    } else {
        funcInfo.scope = "GLOBAL"; // Funcțiile globale au domeniul de aplicare GLOBAL
    }
    functions.push_back(funcInfo);
}
bool FunctionList::existsFunction(const char *name)
{
    string funcName = string(name);
    for (const auto &func : functions)
    {
        if (func.name == funcName)
        {
            return true;
        }
    }
    return false;
}

void FunctionList::printFunctions()
{
    ofstream file("function_symbol_table.txt");

    if (file.is_open())
    {
        for (auto &func : functions)
        {
            file << "Function name: " << func.name << " , Return type: " << func.returnType << " "
                 << ", Scope: " << func.scope<<endl;
                 file<<"Parameters:"<<endl;
            for (auto &param : func.parameters)
            {
                file << "type: " << param.type << ", name: " << param.name<<endl;
            }
            file << endl;
        }

        file.close();
    }
    else
    {
        cerr << "Error: Unable to open function_symbol_table.txt for writing." << endl;
    }
}

FunctionList::~FunctionList()
{
    functions.clear();
}
