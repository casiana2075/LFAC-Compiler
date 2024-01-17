#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* struct ParamInfo
{
    string type;
    string name;
};
 */
struct FunctionInfo
{
    string param_type;
    string param_name;
    string name;
    string returnType;
    string scope;
    vector<pair<string, string>> parameters;
};
class FunctionList
{
    vector<FunctionInfo> functions;

public:
    void addFunction(FunctionInfo funcInfo);
    void getParam(const char *type, const char *name);
    bool existsFunction(const char *name);
    void printFunctions();
   
    ~FunctionList();
};
