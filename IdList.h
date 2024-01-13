#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct IdInfo {
    string type;
    string name;
    string value;
    string func_name;
    string class_name;
    bool constant;
};
class IdList {
    vector<IdInfo> vars;
   
    public:
    bool existsVar(const char* s);
    void addVar(const char* type, const char* name,const char *   value, const char* func_name, const char* class_name,bool constant );
    void addArray(const char *name, vector<int> &values);
    void addVal(const char* name,const char*value);
    string TypeOf(const char* arg);
    string get_val(const char*name);
    void printVars();
    ~IdList();
};
