#include <bits/stdc++.h>
using namespace std;

void dfssolve(int src, vector<int> &visited, vector<vector<int>> &graph)
{
    visited[src] = true;
    cout << src << " ";
    for (auto node : graph[src])
    {
        if (!visited[node])
        {
            dfssolve(node, visited, graph);
        }
    }
}
void dfsTraversal(vector<vector<int>> graph, int n)
{
    vector<int> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfssolve(i, visited, graph);
        }
    }
}
void adjacencyList(vector<vector<int>> edges, int n)
{
    vector<vector<int>> graph(n + 1);
    for (auto edg : edges)
    {
        graph[edg[0]].push_back(edg[1]);
        graph[edg[1]].push_back(edg[0]);
    }
    dfsTraversal(graph, n);
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