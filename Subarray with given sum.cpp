//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
Subarray with given sum

Input:
1 5 12
1 2 3 7 5

Output:
2 4

*/


class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        int start = 0, last = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i]; // storing the sum till sum greater than or equal to s
            if (sum >= s)
            {
                last = i;
                while (s < sum && start < last)
                {
                    sum -= arr[start]; // removing the starting element from sum, if sum is greater than s
                    start++;
                }
                if (sum == s) // if sum is equal to s, then return the starting and ending index
                {
                    return {start + 1, last + 1};
                }
            }
        }
        return {-1};
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
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends