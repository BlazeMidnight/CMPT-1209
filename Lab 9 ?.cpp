#include <iostream>
#include <string>
using namespace std;

class IntStack {
private:
    int* stackArray;
    int stackSize;
    int numElements;

public:
    IntStack(int);
    ~IntStack();

    IntStack(const IntStack& obj);
    IntStack& operator=(const IntStack& right);
    
    void push(int);
    int pop();
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
};

IntStack::IntStack(int Size) {
    stackArray = new int[Size];
    stackSize = Size;
    numElements = 0;
}

IntStack::~IntStack() {
    delete[] stackArray;
}

// Overloaded assignment operator
IntStack& IntStack::operator=(const IntStack& right) {
    delete[] this->stackArray;
    this->stackSize = right.stackSize;
    this->numElements = right.numElements;
    this->stackArray = new int[this->stackSize];

    for (int i = 0; i < this->numElements; i++) {
        this->stackArray[i] = right.stackArray[i];
    }

    return *this;
}

// Copy constructor overloader
IntStack::IntStack(const IntStack& obj) {
    this->stackSize = obj.stackSize;
    this->numElements = obj.numElements;
    this->stackArray = new int[this->stackSize];
    for (int i = 0; i < this->numElements; i++) {
        this->stackArray[i] = obj.stackArray[i];
    }
}

void IntStack::push(int num) {
    if (isFull()) {
        cout << "The stack is full.\n";
    } else {
        stackArray[numElements] = num;
        numElements++;
    }
}

int IntStack::pop() {
    if (isEmpty()) {
        cout << "The stack is empty. Cannot pop.\n";
        return -1;
    }
    numElements--;
    return stackArray[numElements];
}

bool IntStack::isFull() const {
    return numElements == stackSize;
}

bool IntStack::isEmpty() const {
    return numElements == 0;
}

void IntStack::display() const {
    if (isEmpty())
        cout << "The stack is empty.\n";
    else
        for (int i = 0; i < numElements; i++)
            cout << stackArray[i] << "\t";
    cout << endl;
}

int main() {
    IntStack stack1(6);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    
    IntStack stack2(6);
    stack2 = stack1; // Overloaded assignment operator
    
    IntStack stack3 = stack1; // Copy constructor
    
    stack1.push(10);
    stack2.push(20);
    stack3.push(30);
    
    stack1.display();
    stack2.display();
    stack3.display();
    
    return 0;
}
