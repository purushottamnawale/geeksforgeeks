//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int a, int b, int c)
    {
        int maxNum = max({a, b, c});
        if (maxNum <= (2 * (a + b + c - maxNum + 1)))
        {
            return a + b + c;
        }
        else
        {
            return -1;
        }
    }
};

"""
a=4 b=1 c=0
aabaa
4<=2*(4+1+0-4+1)
4<=2*(1+1)
4<=2*(2)


a=6 b=1 c=1
aabaacaa
6<=2*(6+1+1-6+1)
6<=2*(2+1)
6<=2*(3)


a=8 b=2 c=1
aabaabaacaa
8<=2*(8+2+1-8+1)
8<=2*(3+1)
8<=2*(4)


a=11 b=2 c=2
aabaacaabaacaaa
11<=2*(11+2+2-11+1)
11<=2*(4+1)
11<=2*(5) // returns -1

We can observe a pattern, for every max character to embedded (max two repetition), there is a smaller character
Additionally, two extra characters can be tolerated at the end of the string. 
The + 1 in the formula is for the extra last two characters.
"""

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends