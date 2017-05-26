#ifndef STACKOFCONTEXT_H
#define STACKOFCONTEXT_H

#include <vector>

#include "Context.h"

class StackOfContext
{
public:
	StackOfContext();
	~StackOfContext();
	
	Context* GetTopPosition();
	Context* GetPosition(int index);
	
	void pop();
	void push(Context* context);
	size_t size();
	

private:
	std::vector<Context*> vectorOfContext;
};

#endif // STACKOFCONTEXT_H
