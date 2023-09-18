//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Power of 2

Input:
1 32

Output:
1

Explaination:
2 10
&&
1 01
= 0

4 100
&&
3 011
= 0

8 1000
&& 
7 0111
= 0

16 10000
&&
15 01111
= 0

32 100000
&&
31 011111
= 0

return (n!=0 && (n&(n-1))==0);
*/

class Solution
{
public:
    // TC: O(1) and SC: O(1)
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        return (n && !(n & n - 1));
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++)
    {
        long long n; // input a number n
        cin >> n;

        Solution ob;
        if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

// } Driver Code Ends