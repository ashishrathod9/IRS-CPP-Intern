#include <iostream>
using namespace std;

template<class T>
class Stack {
private:
    T* stk;
    int top;
    int size;

public:
    Stack(int sz) {
        size = sz;
        top = -1;
        stk = new T[size];
    }

    void push(T x);
    T pop();
};

// push()
template<class T>
void Stack<T>::push(T x) {
    if (top == size - 1)
        cout << "Stack is full" << endl;
    else {
        top++;
        stk[top] = x;
    }
}

// pop()
template<class T>
T Stack<T>::pop() {
    T x{};   // safe initialization
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        x = stk[top];
        top--;
    }
    return x;
}

int main() {
    Stack<float> s(10);
    s.push(10);
    s.push(130);
    s.push(130);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
}
