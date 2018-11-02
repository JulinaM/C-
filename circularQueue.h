//
// Created by Julina Maharjan on 11/1/18.
//

#ifndef BST_CIRCULARQUEUE_H
#define BST_CIRCULARQUEUE_H

#endif //BST_CIRCULARQUEUE_H

#include <iostream>

template <typename T>
class circularQueue{
private:
    int *front, *rear;
    const int size = 5;
    T data[];

public:
    circularQueue();
    ~circularQueue();
    void push(const T t);
    T pop();

    bool isEmpty();
    bool isFull();
};

template<typename T>
circularQueue<T>::circularQueue() {
    front= 0;
    rear= 0;
    data = new T[size];
}

template<typename T>
circularQueue<T>::~circularQueue() {
    delete []data;
    front = 0;
    rear = 0;
}

template<typename T>
void circularQueue<T>::push(const T t) {
    assert(!isFull());
    data[rear] = t;
    rear = rear++%size;
}

template<typename T>
T circularQueue<T>::pop() {
    assert(!isEmpty());
    T data = data[front];
    front = front++%size;
    return data;

}

template<typename T>
bool circularQueue<T>::isEmpty() {
    return rear== front;
}

template<typename T>
bool circularQueue<T>::isFull() {
    return rear == front -1 &&  (front == 0 && rear = size-1);
}
