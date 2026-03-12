#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

template <typename T>
void testRotate(ArrayStack<T>& s) {
    try {
        cout << "\nTesting rotate RIGHT..." << endl;
        s.rotate(Stack<T>::RIGHT);
        cout << "Stack after RIGHT rotate: " << s << endl;

        cout << "\nTesting rotate LEFT..." << endl;
        s.rotate(Stack<T>::LEFT);
        cout << "Stack after LEFT rotate: " << s << endl;
    }
    catch (string e) {
        cout << "Exception: " << e << endl;
    }

}

int main() {

    const int size = 5;

try {
        ArrayStack<int> stack1(size);

        cout << "add values to stack" << endl;
        for (int i = 1; i <= size; i++) {
            stack1.push(i);
            cout << "Stack: " << stack1 << endl;
        }

        cout << "Peek: " << stack1.peek() << endl;
        cout << "Length: " << stack1.getLength() << endl;

        testRotate(stack1);

        // TODO: recursive invert, for fun. just a few steps  after recursive print();
        // cout << "Testing invert..." << endl;
        // stack1.invert();
        // cout << "Stack after invert: " << stack1 << endl;

        cout << "pop: " << endl;
        stack1.pop();
        cout << "Stack after pop: " << stack1 << endl;

        cout << "Copy ctor: " << endl;
        ArrayStack<int> stack2(stack1);
        cout << "Copied stack: " << stack2 << endl;

        cout << "Testing operator=: " << endl;
        ArrayStack<int> stack3;
        stack3 = stack1;
        cout << "New stack 3: " << stack3 << endl;

        cout << "Testing clear function: " << endl;
        stack1.clear();
        cout << "Stack cleared. Is empty? " << boolalpha << stack1.isEmpty() << endl;
        cout << "Can print stack still?" << stack1 << endl;

        cout << "Negative tests: " << endl;

        try {
            cout << "Pop when empty: " << endl;
            stack1.pop();
        }
        catch (string e) {
            cout << "Caught exception: " << e << endl;
        }

        try {
            cout << "Peek when empty: " << endl;
            cout << stack1.peek() << endl;
        }
        catch (string e) {
            cout << "Caught exception: " << e << endl;
        }

        ArrayStack<string> strStack(4);

        strStack.push("Bulbasaur");
        strStack.push("Charmander");
        strStack.push("Squirtle");

        cout << "String stack: " << strStack << endl;

        testRotate(strStack);

        cout << "Rotrated string stack..." << strStack << endl;
        // strStack.invert();
        // cout << "After invert: " << strStack << endl;

    }
    catch (string e) {
        cout << "Unhandled exception: " << e << endl;
    }




    return 0;
}