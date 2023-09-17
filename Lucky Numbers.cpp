//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdbool.h>

// } Driver Code Ends
// User function Template for C

// Complete the function
// n: Input n
// Return true if the given number is a lucky number else return False

/*
Lucky Numbers

Input:
1 19

Output:
1


TC : O(n)
Explanation:
n = 19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

First Iteration, i = 2
n = n - n/2
n = 19 - 19/2
n = 10
1 3 5 7 9 11 13 15 17 19

Second Iteration, i = 3
n = n - n/3
n = 10 - 10/3
n = 7
1 3 7 9 13 15 19

Third Iteration, i = 4
n = n - n/4
n = 7 - 7/4
n = 6
1 3 7 13 15 19

Fourth Iteration, i = 5
n = n - n/5
n = 6 - 6/5
n = 5
1 3 7 13 19

Since, i > n, i.e. 6 > 5
Loop breaks

So, 19 is a Lucky Number
*/

bool isLucky(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0) // if n is divisible by i, then it is not a lucky number
        {
            return false;
        }
        n -= n / i;
    }
    return true;
}

//{ Driver Code Starts.

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        // calling isLucky() function
        if (isLucky(n))
            printf("1\n"); // printing "1" if isLucky() returns true
        else
            printf("0\n"); // printing "0" if isLucky() returns false
    }
}
// } Driver Code Ends