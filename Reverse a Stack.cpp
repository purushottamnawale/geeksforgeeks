//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Reverse a Stack:

Input:
1 3
4 5 7

Output:
7 5 4

Explanation:

Reverse(4 5 7)
    Reverse(5 7)
        Reverse(7)
            Reverse()
                Return
            InsertAtBottom(,7)
                Return 7
        InsertAtBottom(7,5)
            return 7 5
    InsertAtBottom(7 5,4)
        return 7 5 4


Another Approach:

void Reverse(stack<int> &St)
{

    stack<int> temp = St;
    while (!St.empty())
    {
        St.pop();
    }
    // St = stack<int>();
    while (!temp.empty())
    {
        St.push(temp.top());
        temp.pop();
    }
}

*/

class Solution
{
public:
    void insertAtBottom(stack<int> &St, int ele)
    {
        if (St.empty())
        {
            St.push(ele);
            return;
        }
        int topele = St.top();
        St.pop();
        insertAtBottom(St, ele);
        St.push(topele);
    }

    void Reverse(stack<int> &St)
    {
        if (St.empty())
        {
            return;
        }
        int ele = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, ele);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int> res;
        while (St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }
}
// } Driver Code Ends