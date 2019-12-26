#include <iostream>
using namespace std;

template <class T> class LinkedQue;

template <class T>
class Node    //자료형을 정의합니다.
{
friend class LinkedQue<T>;

private:
	T data;
	Node<T> *link;
public:
    Node(T e = 0, Node *link_ = NULL):data(e),link(link_){}
};

template <class T>
class LinkedQue
{
private:
    Node<T> *front;
    Node<T> *rear;

public:
    LinkedQue()
    {
        front = NULL;
        rear = NULL;
    }

    ~LinkedQue()
    {
        Node<T> *tmpPoint = front;
        while(tmpPoint->link != NULL)
        {
            delete(tmpPoint);
            tmpPoint = tmpPoint->next;
        }
        cout << "LinkedList is deleted" << endl;
    }

    bool IsEmpty() const
    {
        return( front == NULL && rear == NULL);
    }

    T& Front() const
    {
        return front->data;
    }

    T& Rear()
    {
        return rear->data;
    }

    void Push (const T& e)
    {
        if(IsEmpty())
        {
            front = rear = new Node<T> (e,0);
        }
        else
        {
            rear = rear->link = new Node<T> (e,0);
        }
    }

    void Pop()
    {
        if(IsEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node<T> *tempPoint = front;
            front = front->link;
            delete tempPoint;
        }
    }
};
