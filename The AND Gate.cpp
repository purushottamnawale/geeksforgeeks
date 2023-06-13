//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int andGate(vector<int> arr, int N)
    {
        for (int i = 1; i < N; i++)
        {
            if (arr[i] == 0)
            {
                return 0;
            }
        }
        return 1;
    }
};

/*
Alternate Solution:
int andGate(vector<int> arr, int N)
{
    int ans = arr[0];
    for (int i = 1; i < N; i++)
    {
        ans &= arr[i];
    }
    return ans;
}
*/

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        Solution ob;
        cout << ob.andGate(v, N) << endl;
    }
    return 0;
}

// } Driver Code Ends