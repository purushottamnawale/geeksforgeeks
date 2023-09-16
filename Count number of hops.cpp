//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Count number of hops

Input:
1 4

Output:
7

TC = O(N) and SC = O(1)

Explanation:

We can observe that at any given moment, we only need the results for the previous three steps to calculate 
the number of ways to reach the current step. This is because the frog can take either 1, 2, or 3 steps to reach 
the current step, and the number of ways to reach the current step only depends on the number of ways to reach 
the previous three steps. So we can optimize the space used by using only a constant number of variables to store 
the intermediate results, rather than using an array of size n.

Implementation
    * First of all we will check the base cases:
        If n = 1, return 1 since there is only one way to reach 1.
        If n = 2, return 2 since there are 2 ways to reach at 2: {2} and {1->1}.
        If n = 3, return 4 since there are 4 ways to reach at 3: {3}, {1->1->1}, {1->2} and {2->1}.
    * We initialize a, b, and c as 1, 2, and 4 respectively and a variable temp. These variables represent the number of ways 
      to reach the steps i = 1, i = 2, and i = 3.
    * We then iterate from 4 to n and update the current variable, which represents the number of ways to reach the current step (i).
      make temp = (a+b+c)%mod.
      and update a = b , b = c and c = temp.
    * Once the loop finishes, c will contain the number of ways to reach step n, which is the answer we need to return.

Example: n = 5

    Initialize the variables:

    a = 1 (Number of ways to reach step 1)
    b = 2 (Number of ways to reach step 2)
    c = 4 (Number of ways to reach step 3)


    Loop Iteration 1 (i = 4):
    Calculate temp = (a + b + c) % MOD = (1 + 2 + 4) % 1000000007 = 7
    Update a = 2, b = 4, and c = 7


    Loop Iteration 2 (i = 5):
    Calculate temp = (a + b + c) % MOD = (2 + 4 + 7) % 1000000007 = 13
    Update a = 4, b = 7, and c = 13
    Loop ends, return c = 13.

*/

class Solution
{
public:
    // Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // We use similar algorithm as Fibonacci series to find the number of ways in which frog can reach the top.
        long long mod = 1e9 + 7;

        // Base cases
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        if (n == 3)
        {
            return 4;
        }

        // Initializng base values.
        long long int a = 1, b = 2, c = 4, temp;

        for (int i = 4; i <= n; i++)
        {
            temp = (a + b + c) % mod;

            // Updating a as b and b as c and c as temp (sum of a, b and c).
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking testcases
    int t;
    cin >> t;

    while (t--)
    {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;
}

// } Driver Code Ends