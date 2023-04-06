//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> lexicographicallyLargest(vector<int> &a, int n)
    {
        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && (a[j] + a[j - 1]) % 2 == 0)
            {
                j++;
            }
            sort(a.begin() + i, a.begin() + j, greater<int>()); // Sorts in Descending order

            i = j;
        }

        return a;
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
        vector<int> a(n);
        for (auto &j : a)
            cin >> j;
        Solution s;
        vector<int> b = s.lexicographicallyLargest(a, n);
        for (auto i : b)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends