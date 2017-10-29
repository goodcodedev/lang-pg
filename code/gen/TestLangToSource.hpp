#include "TestLangVisitor.hpp"
#include <string>
class TestLangToSource : public TestLangVisitor {
public:
std::string str;
void visitAssign(Assign* node) {
str += node->identifier;
str += "=";
visitExpression(node->expr);
}
void visitFunction(Function* node) {
str += enumTypeToString(node->type);
str += " ";
str += node->identifier;
str += "(";
for (Expression* child : *node->argExprs) {
if (child != node->argExprs->front()) {
str += ",";
}
visitExpression(child);
}
str += ")";
str += "{";
for (Statement* child : *node->statements) {
visitStatement(child);
str += ";";
}
str += "}";
}
void visitIdExpr(IdExpr* node) {
str += node->identifier;
}
void visitIntExpr(IntExpr* node) {
str += std::to_string(node->intConst);
}
};
