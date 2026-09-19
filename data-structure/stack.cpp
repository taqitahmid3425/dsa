#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Popped value: " << top->data << endl;
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Top value: " << top->data << endl;
        }
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            Node *temp = top;
            cout << "Stack: ";
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
    Stack myStack;
    int choice, value;
    do
    {
        cout << endl;
        cout << "Operations available for stack" << endl;
        cout << "1. Push  2. Pop  3. Peek  4. Display  5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            myStack.push(value);
            break;

        case 2:
            myStack.pop();
            break;

        case 3:
            myStack.peek();
            break;

        case 4:
            myStack.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}