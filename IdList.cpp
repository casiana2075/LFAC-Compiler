#include "IdList.h"
#include <string.h>
#include <fstream>

using namespace std;

void IdList::addVar(const char *type, const char *name, const char *value, const char *func, const char *class_name, bool constant)
{
    if (value != NULL && func == NULL && class_name == NULL)
    {
        IdInfo var = {string(type), string(name), string(value), "NULL", "NULL", constant};
        vars.push_back(var);
    }
    else if (value == NULL && func == NULL && class_name == NULL)
    {
        IdInfo var = {string(type), string(name), "NULL", "NULL", "NULL", constant};
        vars.push_back(var);
    }
}


void IdList::addVal(const char* name,const char*value){
    string strvar = string(name);
    for ( IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            v.value=string(value);
            break;
        }
    }
}

void IdList::addArray(const char *name, vector<int> &values) {
    vector<IdInfo> arrayVars;
    for (int i = 0; i < values.size(); ++i) {
        string varName = string(name) + "[" + to_string(i) + "]";
        arrayVars.push_back({ "int", varName, to_string(values[i]), "", "", false });
    }
    vars.insert(vars.end(), arrayVars.begin(), arrayVars.end());
}

string IdList::get_val(const char*name){
    string strvar = string(name);
    for ( IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return v.value;
        }
    }
    return "not found";
}


bool IdList::existsVar(const char *var)
{
    string strvar = string(var);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return true;
        }
    }
    return false;
}

string IdList::TypeOf(const char*arg){
    
    string strvar = string(arg);
    for (const IdInfo &v : vars)
    {
        if (strvar == v.name)
        {
            return v.type;
        }
    }
    return "not declared";
}

void IdList::printVars()
{
    std::ofstream outputFile("symbol_table.txt");

    if (outputFile.is_open())
    {
        for (const IdInfo &v : vars)
        {
            outputFile << "name: " << v.name << " type: " << v.type << " value: " << v.value
                        << " funct: " << v.func_name << " class: " << v.class_name << " constant: " << v.constant << std::endl;
        }

        outputFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to open symbol_table.txt for writing." << std::endl;
    }
}


IdList::~IdList()
{
    vars.clear();
}

