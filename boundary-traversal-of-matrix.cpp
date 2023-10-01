//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Boundary traversal of matrix


Input:
1
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

Output:
1 2 3 4 8 12 16 15 14 13 9 5


 1   2   3   4
 5   6   7   8
 9  10  11  12
13  14  15  16


TC: O(n + m) and SC: O(n + m)
*/

class Solution
{
public:
    // Function to return list of integers that form the boundary traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> matrix, int n, int m)
    {
        vector<int> ans;
        for (int j = 0; j < m; j++) // first column to last column
        {
            ans.push_back(matrix[0][j]); // [first row] [j]
        }
        for (int i = 1; i < n - 1; i++) // second row to second last row
        {
            ans.push_back(matrix[i][m - 1]); // [i] [last column]
        }
        if (n == 1)
        {
            return ans;
        }
        for (int j = m - 1; j >= 0; j--) // last column to first column
        {
            ans.push_back(matrix[n - 1][j]); // [last row] [j]
        }
        if (m == 1)
        {
            return ans;
        }
        for (int i = n - 2; i >= 1; i--) // second last row to second row
        {
            ans.push_back(matrix[i][0]); // [i] [first column]
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends