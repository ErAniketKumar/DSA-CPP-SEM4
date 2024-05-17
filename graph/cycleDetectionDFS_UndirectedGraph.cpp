#include <bits/stdc++.h>
using namespace std;
bool dfsSolve(int src, int parent, vector<vector<int>> &graph, vector<int> &visited)
{
    visited[src] = true;
    for (auto ver : graph[src])
    {
        if (!visited[ver])
        {
            if (dfsSolve(ver, src, graph, visited))
            {
                return true;
            }
        }
        else if (parent != ver)
        {
            return true;
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
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfsSolve(i, -1, graph, visited))
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