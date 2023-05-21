//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
chairs     = [2,2,6,6] 
passengers = [1,3,2,6]

sort()
chairs     = [2 2 6 6]
passengers = [1 2 3 6]

chairs[i] - passengers[i]

ans = [1 0 3 0]
ans = 4
*/

class Solution
{
public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers)
    {
        int ans = 0;
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        for (int i = 0; i < n; i++)
        {
            ans += abs(chairs[i] - passengers[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> chairs(n), passengers(n);
        for (auto &val : chairs)
            cin >> val;
        for (auto &val : passengers)
            cin >> val;
        int ans = sol.findMoves(n, chairs, passengers);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends