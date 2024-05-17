#include <bits/stdc++.h>
using namespace std;
void nextgreaterEle(vector<int> &arr)
{
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (!st.empty() && st.top() > arr[i])
        {
            int ele = arr[i];
            arr[i] = st.top();
            st.push(ele);
        }
        else
        {
            while (!st.empty())
            {
                if (st.top() > arr[i])
                {
                    int ele = arr[i];
                    arr[i] = st.top();
                    st.push(ele);
                    break;
                }
                st.pop();
            }
            if (st.empty())
            {
                st.push(arr[i]);
                arr[i] = -1;
            }
        }
    }
}
int main()
{
    int size;
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    nextgreaterEle(arr);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}