#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Stack.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayStack : public Stack<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the stack
        int maxSize;

        // copy the state of the argument stack to `this`
        void copy(const ArrayStack<T>&);

    public:
        // constructor with the maximum size as the argument
        ArrayStack(int = 100);

        // copy constructor
        ArrayStack(const ArrayStack<T>&);

        // overloaded assignment operator
        ArrayStack<T>& operator=(const ArrayStack<T>&);

        // destructor
        virtual ~ArrayStack();

        // remove all elements in the stack, resetting to the initial state
        virtual void clear() override;

        // return the current length of the stack
        virtual int getLength() const override;

        // return the maximum size of the stack
        int getMaxSize() const;

        // determine if the stack currently empty
        virtual bool isEmpty() const override;

        // determine if the stack is currently full
        bool isFull() const;

        // return the element at the top of the stack
        virtual const T& peek() const override;
        virtual T& peek() override; // peek that allows changing content

        // remove the top element from the stack
        virtual void pop() override;

        // add the argument to the top of the stack
        virtual void push(const T&) override;

        // rearranges the elements in the stack according to the argument
        virtual void rotate(typename Stack<T>::Direction) override;

        virtual void invert() override;

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const ArrayStack<U>&);
};

#include "ArrayStack.tpp"
#endif
