#pragma once
#include <string>
#include <vector>
extern FILE *yyin;
extern int yyparse();
enum Type {
    INT, VOID
};
static std::string enumTypeToString(Type item) {
    switch (item) {
    case INT:return "int";
    case VOID:return "void";
    default: return "";
    }
}
class Expression {
public:
};
class Function {
public:
    std::vector<Expression*>* argExprs;
    std::string identifier;
    Type lc_Type;
    Function(Type lc_Type, std::string identifier, std::vector<Expression*>* argExprs) : argExprs(argExprs), identifier(identifier), lc_Type(lc_Type) {}
};
class IdExpr : public Expression {
public:
    std::string identifier;
    IdExpr(std::string identifier) : identifier(identifier) {}
};
class IntExpr : public Expression {
public:
    int intConst;
    IntExpr(int intConst) : intConst(intConst) {}
};
extern Function* result;
class Loader {
public:
static Function* parseFile(std::string fileName) {
   FILE *sourceFile;
   #ifdef _WIN32
   fopen_s(&sourceFile, fileName.c_str(), "r");
   #else
   sourceFile = fopen(fileName.c_str(), "r");
   #endif
   if (!sourceFile) {
       printf("Can't open file %s", fileName.c_str());
       exit(1);
   }
   yyin = sourceFile;
   do {
       yyparse();
   } while (!feof(yyin));
   return result;
}
};
