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
Node *build()
{
    int x;
    cin >> x;
    if (x == -1)
        return nullptr;
    Node *root = new Node(x);
    root->left = build();
    root->right = build();
}

void preorder(Node *root, vector<int> &pre)
{
    if (root)
    {
        pre.push_back(root->data);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
}

void inorder(Node *root, vector<int> &in)
{
    if (root)
    {
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
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
// construct tree by pre-order and in-order

int findPos(int target, vector<int> in)
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == target)
            return i;
    }
    return -1;
}

int index = 0;
Node *construct(vector<int> pre, vector<int> in, int inSt, int inEd)
{
    if (inSt > inEd)
        return nullptr;
    int ele = pre[index++];
    Node *root = new Node(ele);
    int pos = findPos(ele, in);
    root->left = construct(pre, in, inSt, pos - 1);
    root->right = construct(pre, in, pos + 1, inEd);
    return root;
}
void display(Node *root)
{
    vector<int> in;
    vector<int> pre;
    preorder(root, pre);
    // cout << endl;
    inorder(root, in);
    // treeconstruction
    cout << "inorder: ";
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;
    cout << "preorder: ";
    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl;
    Node *root2 = construct(pre, in, 0, in.size() - 1);
    cout << "levelorder: ";
    levelorder(root2);
    cout << endl;
}
int main()
{
    Node *root = build();
    display(root);
    return 0;
}