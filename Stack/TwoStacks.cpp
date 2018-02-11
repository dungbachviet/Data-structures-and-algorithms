#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacks
{
	int *arr;
	int size;
	int top1, top2;

public :
	// Constructor 
	twoStacks(int size)
	{
		this->size = size;
		arr = new int[size];
		top1 = -1;
		top2 = size;
	}

	// Push x to stack 1
	void push1(int x)
	{
		if (top1 < top2 - 1)
		{
			cout << x << " is pushed to stack 1" << endl;
			arr[++top1] = x;
		}
		else
		{
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Push x to stack 2
	void push2(int x)
	{
		if (top1 < top2 - 1)
		{
			cout << x << " is pushed to stack 2" << endl;
			arr[--top2] = x;
		}
		else
		{
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Pop from stack 1
	int pop1()
	{
		if (top1 >= 0)
			return arr[top1--];
		else
		{
			cout << "Stack Underflow";
			exit(1);
		}
	}

	// Pop from stack 2
	int pop2()
	{
		if (top2 < size)
			return arr[top2++];
		else 
		{
			cout << "Stack Underflow";
			exit(1);
		}
	}
};


int main()
{

	twoStacks myTwoStacks(5);
	myTwoStacks.push1(1);
	myTwoStacks.push1(2);
	myTwoStacks.push2(3);
	myTwoStacks.push2(4);
	myTwoStacks.push2(5);

	printf("\n Pop %d out of stack 1", myTwoStacks.pop1());
	printf("\n Pop %d out of stack 2", myTwoStacks.pop2());
	printf("\n Pop %d out of stack 1", myTwoStacks.pop1());

	getchar();
	return 0;
}