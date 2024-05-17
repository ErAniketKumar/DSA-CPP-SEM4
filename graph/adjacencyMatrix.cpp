#include <bits/stdc++.h>
using namespace std;
void printGraphByAdjMatrix(vector<vector<int>> grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}
void adjacencyMatrix()
{
    int n;
    cin >> n;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    printGraphByAdjMatrix(grid, n);
}
int main()
{
    adjacencyMatrix();
    return 0;
}