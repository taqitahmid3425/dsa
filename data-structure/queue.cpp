#include <iostream>
#include <list>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (front == rear && rear == NULL)
        {
            cout << "Queue is empty." << endl;
        }
        else if (front == rear && rear != NULL)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete rear;
            rear = temp;
        }
    }

    void frontValue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Value at Front: " << front->data << endl;
        }
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            Node *temp = front;
            cout << "Queue: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue myQueue;
    int choice, value;
    do
    {
        cout << endl;
        cout << "Operations available for queue" << endl;
        cout << "1. Enqueue  2. Dequeue  3. Display  4. Front  5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            myQueue.enqueue(value);
            break;

        case 2:
            myQueue.dequeue();
            break;

        case 3:
            myQueue.display();
            break;

        case 4:
            myQueue.frontValue();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}