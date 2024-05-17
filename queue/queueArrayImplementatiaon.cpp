#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int capacity;
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        front = rear = -1;
        size = 0;
        arr = new int[capacity];
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "overflow" << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        size++;
        arr[++rear] = data;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "underflow" << endl;
            return INT_MIN;
        }
        int poppedVal = arr[front++];
        if (size == 0)
        {
            front = -1;
        }
        size--;
        return poppedVal;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return rear == capacity - 1;
    }
};
int main()
{
    int size;
    cin >> size;
    Queue qu(size);
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    cout << qu.pop() << endl;
    cout << qu.pop() << endl;
    return 0;
}