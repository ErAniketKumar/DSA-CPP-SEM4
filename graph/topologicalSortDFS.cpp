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
    vector<bool> visited(n + 1, false);
    stack<int> st;
    vector<int> ans;
    for (auto edg : edges)
    {
        graph[edg[0]].push_back(edg[1]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfsSolve(i, visited, graph, st);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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