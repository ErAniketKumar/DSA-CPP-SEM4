#include <bits/stdc++.h>
using namespace std;
// bfs
bool bfsSolve(int src, vector<vector<int>> &graph, vector<int> &visited, vector<int> &parent)
{
    parent[src] = -1;
    visited[src] = true;
    queue<int> qu;
    qu.push(src);
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        for (auto vec : graph[node])
        {
            if (visited[vec] && vec != parent[node])
            {
                return true;
            }
            else if (!visited[vec])
            {
                visited[vec] = true;
                parent[vec] = node;
                qu.push(vec);
            }
        }
    }
    return false;
}
bool checkCycle(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> graph(n + 1);
    for (auto edg : edges)
    {
        graph[edg[0]].push_back(edg[1]);
        graph[edg[1]].push_back(edg[0]);
    }
    vector<int> visited(n + 1);
    vector<int> parent(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (bfsSolve(i, graph, visited, parent))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
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

    if (checkCycle(edges, n))
    {
        cout << "paresent" << endl;
    }
    else
    {
        cout << "Not paresent" << endl;
    }

    return 0;
}