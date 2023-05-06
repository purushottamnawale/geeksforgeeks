//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

const int N = 1e6;
class Solution
{
public:
    int isPrime[N];
    void sieve()
    {
        isPrime[0] = isPrime[1] = 1;
        for (int i = 2; i * i <= N; i++)
        {
            if (isPrime[i] == 0)
            {
                for (int j = i * i; j <= N; j += i)
                {
                    isPrime[j] = 1;
                }
            }
        }
    }

    long long int prime_Sum(int n)
    {
        static int run = 0;
        if (run == 0)
        {
            sieve(); // sieve() function will run only once because of static variable
            run++;
        }
        long long int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isPrime[i] == 0)
                ans += i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        long long int ans = ob.prime_Sum(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends