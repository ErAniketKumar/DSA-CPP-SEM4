#include <bits/stdc++.h>
using namespace std;
void adjacencyList(vector<vector<int>> edges, int n)
{
    vector<vector<int>> graph(n + 1);
    // prepare graph
    for (auto edg : edges)
    {
        graph[edg[0]].push_back(edg[1]);
        graph[edg[1]].push_back(edg[0]);
    }

    // print graph/adjacency list
    // int k=0;
    for (auto i : graph)
    {
        // cout << k++ << "->";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        edges.push_back(temp);
    }
    adjacencyList(edges, n);

    return 0;
}