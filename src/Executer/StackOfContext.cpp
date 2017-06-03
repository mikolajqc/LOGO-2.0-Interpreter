#include "StackOfContext.h"

StackOfContext::StackOfContext()
{
}

StackOfContext::~StackOfContext()
{
}

Context* StackOfContext::GetTopPosition()
{
	return vectorOfContext[vectorOfContext.size() - 1];
}

Context* StackOfContext::GetPosition(int index)
{
	return vectorOfContext[index];
}

void StackOfContext::pop()
{
	delete vectorOfContext[vectorOfContext.size() - 1];
	vectorOfContext.pop_back();
}

void StackOfContext::push(Context* context)
{
	vectorOfContext.push_back(context);
}

size_t StackOfContext::size()
{
	return vectorOfContext.size();
}
