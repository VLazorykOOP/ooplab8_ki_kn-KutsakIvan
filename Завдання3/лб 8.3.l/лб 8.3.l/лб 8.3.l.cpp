#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
class CircularQueue
{
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    CircularQueue(int size = 10)
    {
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    void enqueue(T item)
    {
        if (isFull())
        {
            cout << "Черга повна" << std::endl;
        }
        else
        {
            rear = (rear + 1) % capacity;
            arr[rear] = item;
            count++;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Черга порожня" << std::endl;
        }
        else
        {
            front = (front + 1) % capacity;
            count--;
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Черга порожня" << std::endl;
            return T();
        }
        else
        {
            return arr[front];
        }
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return (size() == 0);
    }

    bool isFull()
    {
        return (size() == capacity);
    }
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // створення циклічної черги з розміром 5 і типом int
    CircularQueue<int> queue(5);

    // перевірка чи черга порожня
    cout << "Черга порожня? " << boolalpha << queue.isEmpty() << endl;

    // додавання елементів в чергу
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    // спроба додати елемент до повної черги
    queue.enqueue(60);

    // виведення розміру черги
    cout << "Розмір черги: " << queue.size() << endl;

    // виведення першого елементу черги
    cout << "Передня частина черги: " << queue.peek() << endl;

    // вилучення елементів з черги
    queue.dequeue();
    queue.dequeue();

    // виведення розміру черги після вилучення елементів
    cout << "Розмір черги після вилучення з черги: " << queue.size() << endl;

    // додавання нового елементу
    queue.enqueue(60);

    // виведення всіх елементів черги
    while (!queue.isEmpty())
    {
        cout << queue.peek() << " ";
        queue.dequeue();
    }
    cout << endl;
}





