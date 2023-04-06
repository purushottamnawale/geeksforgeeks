//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        long long int ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and arr[st.top()] < arr[i])
            {
                int curr = st.top();
                st.pop();
                if (st.empty())
                {
                    break;
                }
                int diff = i - st.top() - 1;
                ans += (min(arr[st.top()], arr[i]) - arr[curr]) * diff;
            }
            st.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends