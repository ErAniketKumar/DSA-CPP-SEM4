#include <bits/stdc++.h>
using namespace std;
bool isLoopDfs(int src, vector<vector<int>> &graph, vector<int> &visited, vector<int> &dfsvisited)
{
    visited[src] = true;
    dfsvisited[src] = true;
    for (auto vec : graph[src])
    {
        if (!visited[vec])
        {
            if (isLoopDfs(vec, graph, visited, dfsvisited))
            {
                return true;
            }
        }
        else if (dfsvisited[vec])
        {
            return true;
        }
    }
    dfsvisited[src] = false;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        int x, y;
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        edges.push_back(temp);
    }
    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1);    // n+1 for 1 base indexing or if source node is 1 // n if source node is 0
    vector<int> dfsvisited(n + 1); // n+1 for 1 base indexing or if source node is 1 // n if source node is 0
    for (auto edg : edges)
    {
        graph[edg[0]].push_back(edg[1]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (isLoopDfs(i, graph, visited, dfsvisited))
            {
                cout << "Yes present" << endl;
                return 0;
            }
        }
    }
    cout << "not present" << endl;

    return 0;
}