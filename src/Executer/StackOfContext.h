#ifndef STACKOFCONTEXT_H
#define STACKOFCONTEXT_H

#include <vector>

#include "Context.h"

class StackOfContext
{
public:
	StackOfContext();
	~StackOfContext();
	
	Context GetTopPosition();
	Context GetPosition(int index);
	
	void pop();
	void push(Context& context);

private:
	std::vector<Context> vectorOfContext;
	int topPosition;


};

#endif // STACKOFCONTEXT_H
