#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// recursive function to build BST
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;

    for (int value : arr)
    {
        root = insert(root, value);
    }

    return root;
}

void preOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void inOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraverse(root->left);
    cout << root->data << " ";
    inOrderTraverse(root->right);
}

void postOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    Node *root = buildBST(arr);

    cout << "Pre-Order Traverse: ";
    preOrderTraverse(root);
    cout << endl;

    cout << "In-Order Traverse: ";
    inOrderTraverse(root);
    cout << endl;

    cout << "Post-Order Traverse: ";
    postOrderTraverse(root);
    cout << endl;

    return 0;
}