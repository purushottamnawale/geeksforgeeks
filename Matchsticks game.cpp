//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
There is a pattern: 

N    Number of Matchstics 

1          1

2          2

3          3 

4          4

5         -1

6          1 

7          2

8          3

9          4

10        -1

11         1 

12         2 , so on...

Answer is N % 5
if Answer is 0 then return -1
*/

class Solution
{
public:
    int matchGame(long long N)
    {
        int res = N % 5;
        return res == 0 ? -1 : res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;

        cin >> N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends