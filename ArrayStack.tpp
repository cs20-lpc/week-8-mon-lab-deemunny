#include "ArrayStack.hpp"  // comment out before compiling

template <typename T>
ArrayStack<T>::ArrayStack(int i) : maxSize(i), buffer(new T[i]{}) {}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    delete[] buffer;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    buffer = new T[copyObj.getMaxSize()];

    for (int i = 0; i < copyObj.getLength(); ++i) {
        buffer[i] = copyObj.buffer[i];
    }

    this->length = copyObj.getLength();
    maxSize = copyObj.getMaxSize();
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
const T& ArrayStack<T>::peek() const {
    if isEmpty() throw string("Cannot peek. Stack is empty");
    return buffer[this->length-1];
}

// peek that allows changing content
template <typename T>
T& ArrayStack<T>::peek() {
    if isEmpty() throw string("Cannot peek. Stack is empty");
    return buffer[this->length-1];
}

template <typename T>
void ArrayStack<T>::pop() {
    if isEmpty() throw string("Cannot pop. Stack is empty");
    cout << "Removing item " << peek() << endl;
    --this->length;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // copy and increase buffer if too large first
    if (this->length == maxSize) {
        int newSize = maxSize * 2 + 1; // + 1 for if maxSize is 0 for some reason
        T* newBuffer = new T[newSize]
        for (int i = 0; i < this->length; ++i) {
            newBuffer[i] = buffer[i];
        }
        // move pointers
        clear();
        buffer = newBuffer;
        maxSize = newSize;
    }
    buffer[this->length++] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (this->length <= 1) throw string("Nothing to rotate. Stack too small.");
    if (dir == this->RIGHT) {  // moves top to bottom
        T topVal = buffer[this->length - 1];
        for (int i = length - 1; i > 0; --i) {
            buffer[i] = buffer[i-1];
        }
        buffer[0] = topVal;
    }

    if (dir == this->LEFT) {  // moves bottom to top
        T botVal = buffer[0];
        for (int i = 0; i < this->length; ++i) {
            buffer[i] = buffer[i+1];
        }
        buffer[this->length-1] = botVal;
    }
}

template <typename T>
void ArrayStack<T>::invert() {
    if isEmpty() return;
    T temp = peek();
    pop();
    invert();
    if isEmpty() push(temp);
    else {
        T newTop = peek();
        pop();
        invert();
        push(top);
        push(temp);
    }
}


template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}
