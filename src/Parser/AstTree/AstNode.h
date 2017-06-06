#ifndef ASTNODE_H
#define ASTNODE_H
#include <vector>
#include "src/Executer/Executer.h"
#include "src/Window/Window.h"

class AstNode
{
public:
	AstNode(AstNode* parent, Window* window);
	virtual ~AstNode();
	
	void AddChild(AstNode* astNode);
	
	AstNode* getParent();
	std::vector<AstNode*> GetChildren();
	
	virtual float calculate() = 0;
	virtual void execute(Executer* executer) = 0;
	virtual void check() = 0;
	virtual float calc(Executer* executer) = 0;
	
	AstNode* FindStart(AstNode* startNode);
	AstNode* FindStartForCall(AstNode* sourceNode);
	
protected:
	AstNode* parent;
	std::vector<AstNode*> children;
	
	Window* window;
	
};

#endif // ASTNODE_H
