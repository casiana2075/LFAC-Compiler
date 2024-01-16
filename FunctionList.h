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
    vector<ParamInfo> parameters;
     // Name of the class if it's a member function
};
class FunctionList
{
    vector<FunctionInfo> functions;

public:
    void addFunction(FunctionInfo funcInfo);
    bool existsFunction(const char *name);
    void printFunctions();
   
    ~FunctionList();
};
