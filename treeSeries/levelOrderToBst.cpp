#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
Node *construct(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }
    if (root->data > data)
    {
        root->left = construct(root->left, data);
    }
    else
    {
        root->right = construct(root->right, data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void display(Node *root)
{
    inorder(root);
}
int main()
{
    int size;
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    Node *root = nullptr;
    for (int i = 0; i < size; i++)
    {
        root = construct(root, arr[i]);
    }
    display(root);
    return 0;
}