#include "TestLang.hpp"
class TestLangVisitor {
public:
   virtual void visitAssign(Assign *node);
   virtual void visitExpression(Expression *node);
   virtual void visitFunction(Function *node);
   virtual void visitIdExpr(IdExpr *node);
   virtual void visitIntExpr(IntExpr *node);
   virtual void visitStatement(Statement *node);
};
void TestLangVisitor::visitAssign(Assign *node) {
    visitExpression(node->expr);
}
void TestLangVisitor::visitExpression(Expression *node) {
    switch(node->nodeType) {
        case IdExprNode: visitIdExpr(static_cast<IdExpr*>(node));break;
        case IntExprNode: visitIntExpr(static_cast<IntExpr*>(node));break;
        default:break;
    }
}
void TestLangVisitor::visitFunction(Function *node) {
    for (Expression* elem : *node->argExprs) {
        visitExpression(elem);
    }
    for (Statement* elem : *node->statements) {
        visitStatement(elem);
    }
}
void TestLangVisitor::visitIdExpr(IdExpr *node) {
}
void TestLangVisitor::visitIntExpr(IntExpr *node) {
}
void TestLangVisitor::visitStatement(Statement *node) {
    switch(node->nodeType) {
        case AssignNode: visitAssign(static_cast<Assign*>(node));break;
        default:break;
    }
}
