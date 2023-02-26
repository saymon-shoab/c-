#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

template <class T>
class Stack
{
public:
    T *a;
    int stack_size;
    int array_cap;
    Stack()
    {
        a = new T[1];
        array_cap = 1;
        stack_size = 0;
    }
    // makes the array array_capacity multiply by 2
    void increase_size()
    {
        T *tmp;
        tmp = new T[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
        {
            tmp[i] = a[i];
        }
        swap(a, tmp);
        delete[] tmp;
        array_cap = array_cap * 2;
    }
    // add an element in the stack. o(1)..
    void push(T value)
    {
        if (stack_size + 1 > array_cap)
        {
            // cout << "stack is full";
            increase_size();
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
        // a[stack_size - 1] = 0;
        stack_size = stack_size - 1;
    };
    // return the top element from the stack
    T top()
    {
        if (stack_size == 0)
        {
            cout << "stack is empty";
            T a;
            return a;
        }
        return a[stack_size - 1];
    };
};

int main()
{
    Stack<double> st;
    st.push(3.5);
    st.push(1.6);
    st.push(7.8);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    return 0;
}