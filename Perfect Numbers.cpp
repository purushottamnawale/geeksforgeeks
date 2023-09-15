//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Perfect Numbers

Input:
1
6

Output:
1


Explanation:
In number theory, a perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself.
For instance, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6, so 6 is a perfect number.

1. Initialize a variable sum to 1 because 1 is the factor of every number.
2. Iterate from i = 2 to the square root of N.
    If N is divisible by i, which means i is a factor on N.
    If i is equal to (N/i), means both are same number, so we just add i to our sum.
    If i is not equal to (N / i), it means there is another divisor (N / i), so add i and (N / i) to the sum.

Another Approach:
TC : O(N)
int isPerfectNumber(long long N)
{
    long long sum = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        if (N % i == 0)
        {
            sum += i;
        }
    }
    return sum == N;
}


*/
class Solution
{
public:
    // TC : O(sqrt(N))
    int isPerfectNumber(long long N)
    {

        // To store sum of divisors
        long long sum = 1;

        // Find all divisors and add them
        for (int i = 2; i <= sqrt(N); i++)
        {
            if (N % i == 0)
            {
                if (i == N / i)
                    sum += i;
                else
                {
                    sum += i;
                    sum += N / i;
                }
            }
        }

        // If sum of divisors is equal to N, then N is a perfect number
        if (sum == N && N != 1)
        {
            return 1;
        }
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