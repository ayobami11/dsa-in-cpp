#include <iostream>

#include "MyStack.h"

using namespace std;

int main() {

	MyStack *stack = new MyStack(10);

	stack->push(10);
	stack->push(20);
	stack->push(30);

	for (int i = 0; i < 3; i++) {
		cout << stack->pop() << endl;
	}

	stack->push(70);

	cout << stack->peek() << endl;

	cout << endl;
	
	system("pause");

	return 0;
}