//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
struct Module
{
    int x;
    int y;
    int dist;
    Module(int x, int y, int dist)
    {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

bool isSafe(vector<vector<int>> &grid, int x, int y)
{
    return x >= 0 && y >= 0 && x <= grid.size() - 1 && y <= grid[0].size() - 1 && grid[x][y] != 0;
} // IS SAFE FUNCTION CHECKER

class Solution
{
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (A[0][0] == 0)
        {
            return -1;
        }
        int dirX[4] = {1, -1, 0, 0};
        int dirY[4] = {0, 0, 1, -1};

        queue<Module> q;
        q.push(Module(0, 0, 0)); // X=0 , Y=0, DIST=0

        A[0][0] = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Module curr = q.front();
                q.pop();
                int CX = curr.x;
                int CY = curr.y;
                int dist = curr.dist;
                if (CX == X && CY == Y)
                {
                    return dist;
                }
                for (int i = 0; i < 4; i++)
                {
                    int newX = CX + dirX[i];
                    int newY = CY + dirY[i];
                    if (isSafe(A, newX, newY) == false)
                    {
                        continue;
                    }
                    A[newX][newY] = 0;
                    q.push(Module(newX, newY, dist + 1));
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends