#include <iostream>
using namespace std;

//priority queue class implementation using array
class PQueue
{
private:
    struct node
    {
        string name;
        int priority;
    };

    int front, rear;
    int size;
    node *arr;

public:
    //constructor for initialising size , front and rear
    PQueue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = (node *)malloc(size * sizeof(node));
    }

    //function to insert elements in priority queue
    void enqueue(node element)
    {
        //Element always entered in queue acc to priorities

        if (rear < size - 1)
        {
            if (front == -1)
            {
                front = rear = 0;
                arr[front] = element;
            }
            else if (element.priority < arr[0].priority)
            {
                rear++;
                arr[rear] = arr[0];
                arr[0] = element;
            }
            else
            {
                int index = 0;

                while (index <= rear && element.priority >= arr[index].priority)
                    index++;

                rear++;
                for (int i = rear; i > index; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[index] = element;
            }
        }
        else
            cout << "Queue Overflow!!!" << endl;
    }

    //function to remove elements from priority queue
    node dequeue()
    {
        //assuming higher number is higher priority
        node element;
        if (rear >= 0)
        {
            element = arr[0];
            for (int i = 0; i < rear; i++)
                arr[i] = arr[i + 1];

            if (rear == 0)
                front = rear = -1;
            else
                rear--;
        }
        else
            cout << "Queue Underflow" << endl;
        return element;
    }

    //method for getting front element from the queue
    string Front()
    {
        if (front == -1)
            return "";
        else
            return arr[front].name;
    }

    //method for getting rear element from the queue
    string Rear()
    {
        if (rear == -1)
            return "";
        else
            return arr[rear].name;
    }

    //method for checking if queue is empty or not
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    //method fot checking if queue is full or not
    bool isFull()
    {
        if (rear == size - 1)
            return true;
        else
            return false;
    }

    //method to display whole queue
    void display()
    {
        cout << endl
             << "PQ: ";
        for (int i = 0; i <= rear; i++)
            cout << "[" << arr[i].name << "|" << arr[i].priority << "] ";
    }

    //method for getting size of queue
    int Size()
    {
        if (rear == -1 && front == -1)
            return 0;
        return rear - front + 1;
    }
};

int main()
{
    system("cls");

    //double ended queue class object declaration
    PQueue pq(5);
    pq.enqueue({"p1", 5});
    pq.enqueue({"p2", 1});
    pq.enqueue({"p3", 2});
    pq.enqueue({"p4", 2});
    pq.enqueue({"p6", 3});

    cout << pq.dequeue().name << endl;
    cout << pq.dequeue().name << endl;
    cout << pq.dequeue().name << endl;

    cout << pq.Front() << " " << pq.Rear() << endl;
    cout << pq.Size();
    pq.display();
}
