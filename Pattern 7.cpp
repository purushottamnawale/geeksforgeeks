//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

/*
  N = 5
  0 1 2 3 4 5 6 7 8

0         *
1       * * *
2     * * * * *
3   * * * * * * *
4 * * * * * * * * *

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (n + i); j++)
            {
                if (j < (n - 1 - i))
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
            }
            cout << endl;
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
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends