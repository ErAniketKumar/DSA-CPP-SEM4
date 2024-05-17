#include <bits/stdc++.h>
using namespace std;
// sorted array to balance binary tree or in-order to balance binary tree

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

Node *arrayToBalanceBst(vector<int> arr, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = arrayToBalanceBst(arr, start, mid - 1);
    root->right = arrayToBalanceBst(arr, mid + 1, end);
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

    Node *root = arrayToBalanceBst(arr, 0, arr.size() - 1);
    display(root);

    return 0;
}