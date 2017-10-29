#pragma once
#include <string>
#include <vector>
enum NodeType {
    ExpressionNode, FunctionNode, IdExprNode, IntExprNode
};
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
class AstNode {
public:
    NodeType nodeType;
    AstNode(NodeType nodeType) : nodeType(nodeType) {}
    virtual ~AstNode() {}
};
class Expression : public AstNode {
public:
    Expression(NodeType nodeType) : AstNode(nodeType) {}
};
class Function : public AstNode {
public:
    std::vector<Expression*>* argExprs;
    std::string identifier;
    Type type;
    Function(Type type, std::string identifier, std::vector<Expression*>* argExprs) : AstNode(FunctionNode), argExprs(argExprs), identifier(identifier), type(type) {}
};
class IdExpr : public Expression {
public:
    std::string identifier;
    IdExpr(std::string identifier) : Expression(IdExprNode), identifier(identifier) {}
};
class IntExpr : public Expression {
public:
    int intConst;
    IntExpr(int intConst) : Expression(IntExprNode), intConst(intConst) {}
};
extern FILE *yyin;
extern int yyparse();
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
