//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Replace O's with X's


Example 1)
Input:
1
4 5
X X X X X
O X X X O
O X X O X
X X X O O

Output:
X X X X X
O X X X O
O X X O X
X X X O O

Example 2)
Input:
1
5 4
X X X X
X O X X
X O O X
X O X X
X X O O

Output:
X X X X 
X X X X 
X X X X 
X X X X 
X X O O


Explanation:
We will employ boundary DFS to address this problem.

Let's analyze when an 'O' cannot be flipped:
If it has at least one 'O' in its adjacent cells, AND ultimately this chain of adjacent 'O's is connected to an 'O' located on the boundary of the board.
Consider these two cases for clarity:

O's won't be flipped          O's will be flipped
[X O X X X]                   [X X X X X]
[X O O O X]                   [X O O O X]
[X O X X X]                   [X O X X X]
[X X X X X]                   [X X X X X]

So, we can conclude that if a chain of adjacent 'O's is connected to an 'O' on the boundary, then they cannot be flipped.

Steps to Solve:
1. Traverse the boundary of the board and locate 'O's.
2. Each time we encounter an 'O', initiate a Depth-First Search (DFS) from its position.
3. During the DFS, change all 'O's to '#' to differentiate between the 'O's that can be flipped and those that cannot.
4. After all DFSs have been executed, the board contains three elements: '#', 'O', and 'X'.
5. 'O's are the remaining elements that are not connected to any boundary 'O', so change them to 'X'.
6. '#' represents elements that cannot be flipped to 'X', so revert them back to 'O'.

*/

class Solution
{
public:
    void DFS(vector<vector<char>> &board, int i, int j, int n, int m)
    {
        if (i < 0 or j < 0 or i >= n or j >= m or board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = '#';
        DFS(board, i - 1, j, n, m);
        DFS(board, i + 1, j, n, m);
        DFS(board, i, j - 1, n, m);
        DFS(board, i, j + 1, n, m);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        if (n == 0)
        {
            return board;
        }

        // Moving over first and last column
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                DFS(board, i, 0, n, m);
            }
            if (board[i][m - 1] == 'O')
            {
                DFS(board, i, m - 1, n, m);
            }
        }

        // Moving over first and last row
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
            {
                DFS(board, 0, j, n, m);
            }
            if (board[n - 1][j] == 'O')
            {
                DFS(board, n - 1, j, n, m);
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }

        return board;
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
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends