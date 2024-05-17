#include <bits/stdc++.h>
using namespace std;
class CQueue
{
public:
    int front;
    int rear;
    int size;
    int capacity;
    int *arr;
    CQueue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        if (front == -1)
        {
            front = rear;
        }
        size++;
        return;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "underflow" << endl;
            return INT_MIN;
        }
        int poppedVal = arr[front];
        front = (front + 1) % capacity;
        size--;
        if (size == 0)
        {
            rear = front = -1;
        }
        return poppedVal;
    }
    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % capacity == front);
    }
};
int main()
{
    int size;
    cin >> size;

    CQueue qu(size);
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    cout << qu.pop() << endl;
    cout << qu.pop() << endl;
    qu.push(6);
    qu.push(7);
    qu.push(8);
    qu.push(9);
    qu.push(10);
    cout << qu.pop() << endl;
    cout << qu.pop() << endl;
    cout << qu.pop() << endl;
    cout << qu.pop() << endl;

    return 0;
}