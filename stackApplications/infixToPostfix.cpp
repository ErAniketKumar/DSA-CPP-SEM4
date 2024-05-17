#include <bits/stdc++.h>
using namespace std;

// infix to postfix expression conversion
int precedence(char ch)
{
    if (ch == '^')
    {
        return 4;
    }
    else if (ch == '/' || ch == '*' || ch == '%')
        return 3;
    else if (ch == '+')
        return 2;
    else if (ch == '-')
        return 1;
    else
        return -1;
}

string convertExpr(string exp)
{
    string ans = "";
    stack<char> st;
    for (int i = 0; i < exp.size(); i++)
    {
        if (('a' <= exp[i] && exp[i] <= 'z') || ('A' <= exp[i] && exp[i] <= 'Z'))
        {
            ans += exp[i];
        }
        else
        {
            if (exp[i] == '(')
            {
                st.push(exp[i]);
            }
            else if (exp[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); // pop opening bracket
            }
            // else if (st.empty() || precedence(st.top()) <= precedence(exp[i]))
            // {
            //     st.push(exp[i]);
            // }
            else
            {
                while (!st.empty() && precedence(st.top()) >= precedence(exp[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string exp;
    cin >> exp;
    string res = convertExpr(exp);
    cout << res << " ";
    return 0;
}