#include <iostream>
#include <exception>
using namespace std;

class StackOverFlow : public exception
{
public:
  const char *what() const noexcept override
  {
    return "Stack Overflow: Cannot push, stack is full!";
  }
};

class StackUnderFlow : public exception
{
public:
  const char *what() const noexcept override
  {
    return "Stack Underflow: Cannot pop, stack is empty!";
  }
};

class Stack
{
private:
  int *stk;
  int top;
  int size;

public:
  Stack(int sz)
  {
    size = sz;
    stk = new int[size];
    top = -1;
  }

  void push(int x)
  {
    if (top == size - 1)
    {
      throw StackOverFlow();
    }
    stk[++top] = x;
  }

  int pop()
  {
    if (top == -1)
    {
      throw StackUnderFlow();
    }
    return stk[top--];
  }

  ~Stack()
  {
    delete[] stk;
  }
};

int main()
{
  Stack s(3);

  try
  {
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
  }
  catch (const exception &e)
  {
    cout << "Exception caught: " << e.what() << endl;
  }

  return 0;
}
