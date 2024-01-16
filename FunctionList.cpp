#include "FunctionList.h"
#include <fstream>
#include <iostream>

using namespace std;

void FunctionList::addFunction(FunctionInfo funcInfo)
{  funcInfo.scope = "GLOBAL";
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
            file << "Function name: " << func.name << " , Return type: " << func.returnType<<" " << ", Scope: " << func.scope<<endl;
            file << "Parameters: " << endl;
            for (auto &param : func.parameters)
            {
                file << "Type: " << param.type << ", Name: " << param.name << endl;
            }
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

