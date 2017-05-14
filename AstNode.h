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
	
	virtual float calculate() = 0;
	virtual void execute() = 0;
	
protected:
	AstNode* parent;
	std::vector<AstNode*> children;
};

#endif // ASTNODE_H
