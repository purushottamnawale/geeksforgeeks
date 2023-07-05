//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    stack<int> insertAtBottom(stack<int> St, int X)
    {
        stack<int> s;
        while (!St.empty())
        {
            s.push(St.top());
            St.pop();
        }
        St.push(X);
        while (!s.empty())
        {
            St.push(s.top());
            s.pop();
        }
        return St;
    }
};

/*
Another approach using recursion:
stack<int> recur(stack<int> &St, int X)
{
    if (St.size() == 0)
    {
        St.push(X);
    }
    else
    {
        int y = St.top();
        St.pop();
        St = recur(St, X);
        St.push(y);
    }
    return St;
}
stack<int> insertAtBottom(stack<int> St, int X)
{
    St = recur(St, X);
    return St;
}
*/


//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        cin >> x;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp = ob.insertAtBottom(st, x);
        vector<int> v;
        while (tmp.size())
        {
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends