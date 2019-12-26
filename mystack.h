#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

#include <iostream>


using namespace std;

#define MAX 1000
template <class T>
class Stack {

public:
    int top_pos;

    T a[MAX]; // Maximum size of Stack

    Stack<T>() { top_pos = -1; }
    bool push(T x);
    T pop();
    T top();
    bool isEmpty();
};

template <class T>
bool Stack<T>::push(T x)
{
    if (top_pos >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top_pos] = x;
        return true;
    }
}

template <class T>
T Stack<T>::pop()
{
    if (top_pos < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        // 이곳에 코드를 작성하시오. ////
		top_pos--;
		return 0;
        ///////////////////////
    }
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (top_pos < 0);
}

template <class T>
T Stack<T>::top()
{
    if (top_pos < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        T x = a[top_pos];
        return x;
    }
}

#endif // MYSTACK_H_INCLUDED
