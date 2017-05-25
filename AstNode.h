#ifndef ASTNODE_H
#define ASTNODE_H
#include <vector>

//todo: derivation of this class to more specific classes for ex: with a table of symbols
class AstNode
{
public:
	AstNode(AstNode* parent);
	virtual ~AstNode();
	
	void AddChild(AstNode* astNode);
	//tu bedzie execute gdzies
	
	//ForDebug only:
	AstNode* getParent();
	std::vector<AstNode*> GetChildren();
	
	virtual float calculate() = 0;
	virtual void execute() = 0;
	virtual void check() = 0;
	
	AstNode* FindStart(AstNode* startNode);
	AstNode* FindStartForCall(AstNode* sourceNode);
	
protected:
	AstNode* parent;
	std::vector<AstNode*> children;
	
};

#endif // ASTNODE_H
