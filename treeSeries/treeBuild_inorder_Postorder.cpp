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
    return root;
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
void postorder(Node *root, vector<int> &post)
{
    if (root)
    {
        postorder(root->left, post);
        postorder(root->right, post);
        post.push_back(root->data);
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
// fins the position of element in in-order
int findPos(int ele, vector<int> in)
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == ele)
            return i;
    }
    return -1;
}
// conntruct tree from in-order array and post-order array;

Node *construct(vector<int> &in, vector<int> &post, int inSt, int inEd, int &index)
{
    if (inSt > inEd)
        return nullptr;
    int ele = post[index--];
    Node *root = new Node(ele);
    int pos = findPos(ele, in);
    root->right = construct(in, post, pos + 1, inEd, index);
    root->left = construct(in, post, inSt, pos - 1, index);
    return root;
}
void display(Node *root)
{
    vector<int> in;
    vector<int> post;
    inorder(root, in);
    postorder(root, post);
    int index = post.size() - 1;
    cout << "inorder: ";
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;
    cout << "postorder: ";
    for (int i = 0; i < post.size(); i++)
    {
        cout << post[i] << " ";
    }
    cout << endl;
    // construct tree from in-order and -post-order function all and root wil new tree after build
    Node *root2 = construct(in, post, 0, in.size() - 1, index);
    // print for confermation
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