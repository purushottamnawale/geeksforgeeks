//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
First and last occurrences of x

Input:
1
9 5
1 3 5 5 5 5 67 123 125

Output:
2 5

TC: O(logn) and SC: O(1)
Code uses Binary Search to find the first and last occurrence of a number in a sorted array.


Another Approach:
vector<int> find(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        if (arr[low] != x)
        {
            low++;
        }
        if (arr[high] != x)
        {
            high--;
        }
        if (arr[low] == x && arr[high] == x)
        {
            return {low, high};
        }
    }
    if (low > high)
    {
        return {-1, -1};
    }
}

*/

class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        vector<int> ans(2, -1);

        // Find the first occurrence of x
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                ans[0] = mid;
                right = mid - 1;
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // Find the last occurrence of x
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                ans[1] = mid;
                left = mid + 1;
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
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
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends