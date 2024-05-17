#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<vector<int>> graph, int n)
{
    vector<int> visited(n, false);
    queue<int> qu;
    qu.push(0);
    visited[0] = true;
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        cout << node << " ";
        for (auto ver : graph[node])
        {
            if (!visited[ver])
            {
                visited[ver] = true;
                qu.push(ver);
            }
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
    bfsTraversal(graph, n);
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