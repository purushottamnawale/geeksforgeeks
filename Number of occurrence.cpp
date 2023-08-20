//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int target)
    {
        int left, right, mid, first, last;
        left = 0, right = n - 1, first = last = -1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                first = mid;
                right = mid - 1;
            }
            else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (first == -1)
            return 0;
        left = 0, right = n - 1; // re-assigning left and right values
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                last = mid;
                left = mid + 1;
            }
            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return last - first + 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends