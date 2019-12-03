#pragma once

class Stack
{
public:
	Stack() = default;
	Stack(const Stack& source);
	~Stack();
	Stack& operator=(const Stack& source);
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	class Element
	{
	public:
		Element(int val, Element* pNext);
		~Element();
		Element(const Element& source);
		Element& operator = (const Element& source);
		Element* Disconnect();
		int GetVal() const;
	private:
		int val = 0;
		Element* pNext = nullptr;
	public:
		int CountElements();
	};
	Element* pTop = nullptr;
	int size = 0;
private:
};