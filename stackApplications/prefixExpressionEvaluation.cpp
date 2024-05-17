#include <bits/stdc++.h>
using namespace std;
// prefixEvaluations
int doOperation(int op1, int op2, char ch)
{
    switch (ch)
    {
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '*':
        return op1 * op2;
        break;
    case '/':
        return op1 / op2;
        break;
    case '^':
        return pow(op1, op2);
        break;
    case '%':
        return op1 % op2;
        break;
    }
}
int evaluate(string exp)
{
    stack<int> st;
    for (int i = exp.size() - 1; i >= 0; i--)
    {
        if (isdigit(exp[i]))
        {
            st.push(exp[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res = doOperation(op1, op2, exp[i]);
            st.push(res);
        }
    }
    return st.top();
}
int main()
{
    string exp;
    cin >> exp;
    cout << evaluate(exp) << endl;
    return 0;
}