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

Node *buildTree()
{
    int x;
    cin >> x;
    if (x == -1)
    {
        return nullptr;
    }
    Node *root = new Node(x);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
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

void levelorder(Node *root)
{
    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        int size = qu.size();
        while (size--)
        {
            Node *temp = qu.front();
            qu.pop();
            cout << temp->data << " ";
            if (temp->left)
                qu.push(temp->left);
            if (temp->right)
                qu.push(temp->right);
        }
        cout << endl;
    }
}
void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void pathPrint(Node *root, vector<vector<int>> &res, vector<int> temp)
{
    if (!root)
        return;
    temp.push_back(root->data);
    if (!root->left && !root->right)
    {
        res.push_back(temp);
    }
    pathPrint(root->left, res, temp);
    pathPrint(root->right, res, temp);
}

int height(Node *root)
{
    if (!root)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return 1 + max(lheight, rheight);
}
void display(Node *root)
{

    // preorder traversal
    cout << "preorder: ";
    preorder(root);
    cout << endl;
    // in-order traversal
    cout << "inorder: " << endl;
    inorder(root);
    cout << endl;
    // post order
    cout << "postorder: " << endl;
    postorder(root);
    cout << endl;

    // levelorder-traversal
    cout << "level oder: " << endl;
    levelorder(root);
    cout << endl;

    // printall path
    vector<vector<int>> res;
    vector<int> v;
    pathPrint(root, res, v);
    cout << "all tree's path: " << endl;
    for (auto path : res)
    {
        for (auto x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;

    // height of binary tree
    cout << "height of tree: ";
    cout << height(root) << endl;
}

int main()
{
    Node *root = buildTree();
    display(root);
    return 0;
}