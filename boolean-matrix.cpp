//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Boolean Matrix

Input:
1
4 3
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1 1
1 1 1
1 1 1
1 0 0

*/

class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.

    // TC: O(n*m) and SC: O(n+m)
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // Using two list to keep track of the rows and columns that needs to be updated with 1.
        int row[n] = {0};
        int col[m] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If we get 1 in matrix, we mark ith row and jth column as 1.
                if (matrix[i][j] == 1)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If ith row or jth column is marked as 1, then all elements of matrix in that row and column will be 1.
                if (row[i] || col[j])
                {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row);
        for (int i = 0; i < row; i++)
        {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.booleanMatrix(matrix);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends