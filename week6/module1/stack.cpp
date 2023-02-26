#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int max_size = 500;
class Stack
{
public:
    int a[max_size];
    int stack_size;
    Stack()
    {
        stack_size = 0;
    }
    // add an element in the stack. o(1)..
    void push(int value)
    {
        if (stack_size + 1 > max_size)
        {
            cout << "stack is full";
            return;
        }
        stack_size = stack_size + 1;
        a[stack_size - 1] = value;
    };
    // delete the topmost element from the stack 0(i)
    void pop()
    {
        if (stack_size == 0)
        {
            cout << "stack is empty!\n";
            return;
        }
        a[stack_size - 1] = 0;
        stack_size = stack_size - 1;
    };
    // return the top element from the stack
    int top()
    {
        if (stack_size == 0)
        {
            cout << "stack is empty";
        }
        return a[stack_size - 1];
    };
};

int main()
{
    Stack st;
    st.push(3);
    cout << st.top() << "\n";
    st.push(4);
    cout << st.top() << "\n";
    st.push(5);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    return 0;
}