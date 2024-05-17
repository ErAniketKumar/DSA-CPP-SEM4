#include <bits/stdc++.h>
using namespace std;
bool cycleDetection(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> graph(n + 1);
    // prepare Adjacency matrix
    for (auto edg : edges)
    {
        graph[edg[0]].push_back(edg[1]);
    }
    // indegree
    vector<int> indegree(n);
    for (auto adjlist : graph)
    {
        for (auto vec : adjlist)
        {
            indegree[vec]++;
        }
    }
    int count = 0;
    queue<int> qu;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            qu.push(i);
        }
    }

    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        count++;
        for (auto vec : graph[node])
        {
            indegree[vec]--;
            if (indegree[vec] == 0)
            {
                qu.push(vec);
            }
        }
    }
    return count != n;
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
    if (cycleDetection(edges, n))
    {
        cout << "Cycle Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}