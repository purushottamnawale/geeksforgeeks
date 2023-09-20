//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

/*
Minimum Multiplications to reach End

Input:
1
3
2 5 7
3 30

Output:
2

*/

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // Array which stores the minimum steps to reach i from start
        int ans[100001];

        // -1 indicated the state has not been visited
        memset(ans, -1, sizeof(ans));
        const int mod = 100000;

        // Queue to store all possible states
        queue<int> q;

        // Initially push the start
        q.push(start % mod);

        // To reach start we require 0 steps
        ans[start] = 0;

        // Till all states are visited
        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            if (top == end)
            {
                return ans[end]; // Return the minimum steps to reach end
            }
            // Perform multiplication with all array elements
            for (int i = 0; i < arr.size(); i++)
            {
                int pushed = top * arr[i];
                pushed = pushed % mod;

                if (ans[pushed] == -1) // If not visited, then push it to queue
                {
                    ans[pushed] = ans[top] + 1;
                    q.push(pushed);
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends

/*
Explanation:
arr = {2 5 7}
start = 3
end = 30
q = {3}
ans = {3:0}

While Iteration 1
    top = 3
    q = {}
    For Iteration
        pushed = 3 * 2 = 6
        ans = {3:0, 6:1}
        q = {6}

        pushed = 3 * 5 = 15
        ans = {3:0, 6:1, 15:1}
        q = {6, 15}

        pushed = 3 * 7 = 21
        ans = {3:0, 6:1, 15:1, 21:1}
        q = {6, 15, 21}

While Iteration 2
    top = 6
    q = {15, 21}
    For Iteration
        pushed = 6 * 2 = 12
        ans = {3:0, 6:1, 12:2, 15:1, 21:1}
        q = {15, 21, 12}

        pushed = 6 * 5 = 30
        ans = {3:0, 6:1, 12:2, 15:1, 21:1, 30:2}
        q = {15, 21, 12, 30}

        pushed = 6 * 7 = 42
        ans = {3:0, 6:1, 12:2, 15:1, 21:1, 30:2, 42:2}
        q = {15, 21, 12, 30, 42}

While Iteration 3
    top = 15
    q = {21, 12, 30, 42}
    For Iteration
        pushed = 15 * 2 = 30

        pushed = 15 * 5 = 75
        ans = {3:0, 6:1, 12:2, 15:1, 21:1, 30:2, 42:2, 75:2}
        q = {21, 12, 30, 42, 75}

        pushed = 15 * 7 = 105
        ans = {3:0, 6:1, 12:2, 15:1, 21:1, 30:2, 42:2, 75:2, 105:2}
        q = {21, 12, 30, 42, 75, 105}


While Iteration 4
    top = 21
    q = {12 ,30, 42, 75, 105}
    For Iteration
        pushed = 21 * 2 = 42

        pushed = 21 * 3 = 105

        pushed = 21 * 7 = 147

While Iteration 5
    top = 12
    q = {30, 42, 75, 105}
    For Iteration
        pushed = 12 * 2 = 24
        ans = {3:0, 6:1, 12:2, 15:1, 21:1, 24:3, 30:2, 42:2, 75:2, 105:2}
        q = {30, 42, 75, 105, 147, 24}

        pushed = 12 * 5 = 60
        ans = {3:0, 6:1, 12:2, 15:1, 21:1, 24:3, 30:2, 42:2, 60:3, 75:2, 105:2}
        q = {30, 42, 75, 105, 147, 24, 60}

        pushed = 12 * 7 = 84
        ans = {3:0, 6:1, 12:2, 15:1, 21:1, 24:3, 30:2, 42:2, 60:3, 75:2, 84:3, 105:2}
        q = {30, 42, 75, 105, 147, 24, 60, 84}

While Iteration 6
    top = 30
    q = {42, 75, 105, 147, 24, 60, 84}
    return ans[30] = 2

*/