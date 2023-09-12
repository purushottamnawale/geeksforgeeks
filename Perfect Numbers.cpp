//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Perfect Numbers

O(sqrt(N)) solution


Input:
1
6

Output:
1


Explanation:


*/
class Solution
{
public:
    int isPerfectNumber(long long N)
    {
        // To store sum of divisors
        long long sum = 0;
        for (long long i = 1; i <= sqrt(N); i++) // Find all divisors and add them
        {
            if (N % i == 0)
            {
                // If divisors are equal,only one factor
                if (N / i == i)
                    sum += i;

                else // Otherwise two factors
                {
                    sum += i;
                    sum += N / i;
                }
            }
        }
        sum -= N;
        if (sum == N)
            return 1;
        return 0;
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
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends