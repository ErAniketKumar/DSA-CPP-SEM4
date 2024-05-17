#include <bits/stdc++.h>
using namespace std;
void prepareAdjListOfString(vector<vector<string>> edges)
{
    map<string, vector<string>> m;
    for (auto edg : edges)
    {
        m[edg[0]].push_back(edg[1]);
        m[edg[1]].push_back(edg[0]);
    }
    for (auto x : m)
    {
        cout << x.first << "->";
        for (auto y : x.second)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<string>> edges;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        vector<string> temp;
        string x, y;
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        edges.push_back(temp);
    }
    
    prepareAdjListOfString(edges);

    return 0;
}