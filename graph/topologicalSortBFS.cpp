#include <bits/stdc++.h>
using namespace std;
void dfsSolve(int src, vector<bool> &visited, vector<vector<int>> &graph, stack<int> &st)
{
    visited[src] = true;
    for (auto ver : graph[src])
    {
        if (!visited[ver])
        {
            dfsSolve(ver, visited, graph, st);
        }
    }
    st.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1);
    vector<int> ans;
    queue<int> qu;
    for (auto edg : edges)
    {
        graph[edg[0]].push_back(edg[1]);
    }

    for (auto listedg : graph)
    {
        for (auto ver : listedg)
        {
            indegree[ver]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            qu.push(i);
        }
    }
    // do bfs
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        ans.push_back(node);
        for (auto ver : graph[node])
        {
            indegree[ver]--;
            if (indegree[ver] == 0)
            {
                qu.push(ver);
            }
        }
    }
    return ans;
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
    vector<int> ans = topologicalSort(edges, n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}