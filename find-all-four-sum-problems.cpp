//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++


/*
Find All Four Sum Number

Input:
1
5 3
0 0 2 1 1

Output:
0 0 1 2 $


*/

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int start = j + 1;
                int end = n - 1;
                while (start < end)
                {
                    int sum = arr[i] + arr[j] + arr[start] + arr[end];
                    if (sum == k)
                    {
                        s.insert({arr[i], arr[j], arr[start], arr[end]});
                        start++;
                        end--;
                    }
                    else if (sum > k)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }
        for (auto i : s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends