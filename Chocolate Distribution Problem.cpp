//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
Chocolate Distribution Problem:

Input:
1
8
3 4 1 9 56 7 9 12
5

Output:
6

*/


class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long mini = INT_MAX;
        long long l = 0, r = m - 1;
        while (r < n)
        {
            long long diff = a[r] - a[l];
            mini = min(mini, diff);
            l++;
            r++;
        }
        return mini;
    }
};

//{ Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends