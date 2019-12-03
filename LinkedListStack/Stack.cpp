#include "Stack.h"

Stack::Stack(const Stack &source)
{
	*this = source;
}

Stack::~Stack()
{
	delete pTop;
	pTop = nullptr;
}

Stack& Stack::operator =(const Stack &source)
{
	if (!Empty())
	{
		delete pTop;
		pTop = nullptr;
	}

	if (!source.Empty())
	{
		pTop = new Element(*source.pTop);
	}

	return *this;
}

void Stack::Push(int val)
{
	pTop = new Element(val, pTop);
	size++;
}

int Stack::Pop()
{
	if (Empty())
	{
		return -1;
	}

	const int popped = pTop->GetVal();
	Element* pOldTop = pTop;
	pTop = pTop->Disconnect();
	delete pOldTop;

	return popped;
}

int Stack::Size() const
{
	if (!Empty())
	{
		return pTop->CountElements();
	}
	else
	{
		return 0;
	}
}

bool Stack::Empty() const
{
	return pTop == nullptr;
}

Stack::Element::Element(const Element &source)
	:
	val(source.val)
{
	if (source.pNext != nullptr)
	{
		pNext = new Element(*source.pNext);
	}
}

Stack::Element::~Element()
{
	delete pNext;
	pNext = nullptr;
}

Stack::Element::Element(int val, Element *pNext)
	:
	val(val),
	pNext(pNext)
{
}

Stack::Element& Stack::Element::operator =(const Element &source)
{
	if (this != &source)
	{
		delete pNext;
		pNext = nullptr;

		pNext = new Element(source.val, source.pNext);
	}
	return *this;
}

Stack::Element* Stack::Element::Disconnect()
{
	Element* pTemp = pNext;
	pNext = nullptr;

	return pTemp;
}

int Stack::Element::GetVal() const
{
	return val;
}

int Stack::Element::CountElements()
{
	if (pNext == nullptr)
	{
		return 1;
	}
	else
	{
		return pNext->CountElements() + 1;
	}
}