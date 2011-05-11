//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Count Subarrays of Non-Zero Elements
No need to Non-Zero Elements with Zeros
*/

class Solution
{
public:
    int arrayOperations(int n, vector<int> &arr)
    {
        int counter = 0;
        bool flag = false, allNonZero = true;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                if (flag == false) // If the element is the first non-zero element
                {
                    counter++;
                }
                flag = true;
            }
            else
            {
                allNonZero = false;
                flag = false;
            }
        }
        if (allNonZero)
        {
            return -1;
        }
        return counter;
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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution obj;
        int res = obj.arrayOperations(n, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends