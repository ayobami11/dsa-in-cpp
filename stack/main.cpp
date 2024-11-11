#include <iostream>
#include "MyStack.h"

// #include <stack> (there is also a built stack data structure; I don't think that is the focus of the course though.)

using namespace std;

int main () {

	MyStack stack = MyStack(10);

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.push(10);

	// stack.push(11);

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	cout << "\nElement at the top of the stack: " << stack.peek() << endl;
	cout << "\nSize of the stack: " << stack.peek() << endl;

	stack.print();

	system("pause");

	cout << endl;

	return 0;
}