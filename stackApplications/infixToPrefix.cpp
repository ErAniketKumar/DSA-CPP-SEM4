#include <bits/stdc++.h>
using namespace std;
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
string evaluateInfixToPostfix(string exp)
{
    // reverse
    reverse(exp.begin(), exp.end());
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == ')')
        {
            exp[i] = '(';
        }
        else if (exp[i] == '(')
        {
            exp[i] = ')';
        }
    }
    // apply postfix logic

    stack<char> st;
    string ans = "";
    for (int i = 0; i < exp.size(); i++)
    {
        if (('a' <= exp[i] && exp[i] <= 'z') || ('A' <= exp[i] && exp[i] <= 'Z'))
        {
            ans += exp[i];
        }
        else if (exp[i] == '(')
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
                st.pop(); // remove opening bracket
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(exp[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string exp;
    cin >> exp;
    string res = evaluateInfixToPostfix(exp);
    cout << res << " ";
    return 0;
}