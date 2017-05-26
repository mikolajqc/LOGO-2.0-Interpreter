#include "StackOfContext.h"

StackOfContext::StackOfContext()
{
	topPosition = 0;
}

StackOfContext::~StackOfContext()
{
}

Context StackOfContext::GetTopPosition()
{
	return vectorOfContext[vectorOfContext.size() - 1];
}

Context StackOfContext::GetPosition(int index)
{
	return vectorOfContext[index];
}

void StackOfContext::pop()
{
	vectorOfContext.pop_back();
}

void StackOfContext::push(Context& context)
{
	vectorOfContext.push_back(context);
}
