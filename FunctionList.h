#include <iostream>
#include <vector>
#include <string>

using namespace std;
 struct ParamInfo
{
    string type;
    string name;
};
 
struct FunctionInfo
{
    string name;
    string returnType;
    string scope;
    bool isMethod;
    string className;
    vector<ParamInfo> parameters;
};

class FunctionList
{
    vector<FunctionInfo> functions;

public:
    FunctionInfo* getFunction(const char *name);
    void addFunction(FunctionInfo funcInfo);
    bool existsFunction(const char *name);
    void printFunctions();
   
    ~FunctionList();
};
