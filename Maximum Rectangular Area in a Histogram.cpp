//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> st;
        long long int ans = 0, i = 0;

        while (i < n)
        {
            while (!st.empty() and arr[st.top()] > arr[i])
            {
                long long int h = arr[st.top()];
                st.pop();
                ans = max(ans, h * (st.empty() ? i : i - st.top() - 1));
            }
            st.push(i++);
        }

        while (!st.empty())
        {
            long long int h = arr[st.top()];
            st.pop();
            ans = max(ans, h * (st.empty() ? i : i - st.top() - 1));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends