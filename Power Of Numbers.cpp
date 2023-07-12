//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Using Recursion:

12 ^ 21 = 12 * (12 ^ 20)

21 ^ 12 = 21 ^ 6 * 21 ^ 6


Time Complexity: O(logR)
Space Complexity: O(logR)
*/
class Solution
{
public:
    long long power(int N, int R)
    {
        int mod = 1e9 + 7;
        if (N == 0)
        {
            return 0;
        }
        if (R == 0)
        {
            return 1;
        }
        long long int ans = power(N, R / 2);
        if (R % 2 == 0) // If R is even
        {
            return (ans % mod * ans % mod) % mod;
        }
        else // If R is odd
        {
            return (N % mod * ans % mod * ans % mod) % mod;
        }
    }
};

//{ Driver Code Starts.

// compute reverse of a number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    int T;
    cin >> T; // testcases

    while (T--)
    {
        long long N;
        cin >> N; // input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        // power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
}
// } Driver Code Ends