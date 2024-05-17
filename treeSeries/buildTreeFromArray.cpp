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

Node *costructTree(vector<int> arr, int &idx)
{
    if (idx >= arr.size())
        return nullptr; // Check if idx is within array size

    queue<Node *> qu;
    Node *root = new Node(arr[idx++]);
    qu.push(root);
    while (!qu.empty() && idx < arr.size()) // Check if idx is within array size
    {
        Node *temp = qu.front();
        qu.pop();
        if (!temp->left)
        {
            temp->left = new Node(arr[idx++]);
            qu.push(temp->left);
        }
        if (idx < arr.size() && !temp->right) // Check if idx is within array size
        {
            temp->right = new Node(arr[idx++]);
            qu.push(temp->right);
        }
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
    int idx = 0;
    Node *root = costructTree(arr, idx);
    display(root);

    return 0;
}