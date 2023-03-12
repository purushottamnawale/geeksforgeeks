//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N)
    {
        int i = 0, j = N - 1;
        int ones = 0, row = 0;
        while (i < N and j >= 0)
        {
            if (mat[i][j] == 1)
            {
                row = i;
                ones++;
                j--;
            }
            else
                i++;
        }
        return {row, ones};
    }
};

/*
vector<int> findMaxRow(vector<vector<int>> mat, int N)
    {
        int rowNumber = 0;
        int maxCount = 0;
        for (int i = 0; i < N; i++)
        {
            int count = 0;
            for (int j = 0; j < N; j++)
            {
                if (mat[i][j] == 1)
                {
                    count += 1;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
                rowNumber = i;
            }
        }
        vector<int> v;
        v.push_back(rowNumber);
        v.push_back(maxCount);
        return v;
    }
 */

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends