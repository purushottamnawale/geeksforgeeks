//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// function Template for C++

// Function to reverse the queue.

/*
Queue Reversal using Recursion:
helper(4 3 1 10 2 6)
    helper(3 1 10 2 6)
        helper(1 10 2 6)
            helper(10 2 6)
                helper(2 6)
                    helper(6)
                        helper()
                        return
                    q.push(6) => (6)
                q.push(2) => (6 2)
            q.push(10) => (6 2 10)
        q.push(1) => (6 2 10 1)
    q.push(3) => (6 2 10 1 3)
q.push(4) => (6 2 10 1 3 4)


Another approach using stack:
queue<int> rev(queue<int> q)
{
    stack<int> s; // Using a stack to reverse the queue.
    while(!q.empty())
    {

        s.push(q.front()); // Pushing elements from queue into stack and removing them from queue.
        q.pop();
    }
    queue<int> a; //creating new queue.
    while(!s.empty())
    {
        a.push(s.top()); // Now pushing elements back into the queue from stack and removing them from stack. Queue gets reversed as stack follows last in first out.
        s.pop();
    }
    return a; // Returning reversed queue.
}
*/

class Solution
{
public:
    void helper(queue<int> &q)
    {
        if (q.empty())
        {
            return;
        }
        int x = q.front();
        q.pop();
        helper(q);
        q.push(x);
    }

    queue<int> rev(queue<int> q)
    {
        helper(q);
        return q;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        Solution ob;
        queue<int> a = ob.rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
}
// } Driver Code Ends