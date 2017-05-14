#ifndef ASTNODE_H
#define ASTNODE_H
#include <vector>

//todo: derivation of this class to more specific classes for ex: with a table of symbols
class AstNode
{
public:
	AstNode(AstNode* parent);
	~AstNode();
	
	void AddChild(AstNode* astNode);
	//tu bedzie execute gdzies
	
	//ForDebug only:
	AstNode* getParent();
	
	float calculate();
	
protected:
	AstNode* parent;
	std::vector<AstNode*> children;

};

#endif // ASTNODE_H
