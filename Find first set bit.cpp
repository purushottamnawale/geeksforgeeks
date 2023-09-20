//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Find first set bit

Input:
1 18

Output:
2

Explanation:
TC: O(1) and SC: O(1)
log2(n & -n) + 1 and log2(n & ~(n - 1)) + 1 both works same.

log2(n & -n):
Here, n & -n will give the rightmost set bit of n.
-n is the 2’s complement of n. It is obtained by changing all the 0’s to 1 and 1’s to 0 and adding 1 to it.
18 = 10010
-18 = 01101 + 1 = 01110
10010 && 01110 = 00010
Answer = log2(00010) + 1 = log2(2) + 1 = 1 + 1 = 2



log2(n & ~(n - 1)):
Here, n & ~(n - 1) will give the rightmost set bit of n.
n - 1 will have all the bits same as n, except for the rightmost set bit of n and all the bits to the right of it.
18 = 10010
17 = 10001
~17 = 01110
10010 && 01110 = 00010

Answer = log2(00010) + 1 = log2(2) + 1 = 1 + 1 = 2


Note:
While there are specific cases where ~(n-1) and -n may produce the same result,
such as when n is a power of 2 or when n is a negative integer with all bits set to 1,
they are not generally equivalent. In most cases, these expressions will yield different values.




Alternative Approach 1:
TC: O(Log(N)) and SC: O(1)

Note: Right Shift Operator >>
    a = 5; which is 101 in Binary Form.
    Now, if “a is right-shifted by 2” i.e a >> 2 then a will become a = 1
    0101 -> 01

unsigned int getFirstSetBit(int n)
{
    int pos = 1;
    while (n > 0)
    {
        // Checking if last bit is set
        if (n & 1)
        {
            return pos;
        }

        // Increment position and right shift number by 1
        n = n >> 1;
        pos++;
    }
    return 0;
}


Alternative Approach 2:
TC: O(Log(N)) and SC: O(1)

unsigned int getFirstSetBit(int n)
{
    int pos = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            return pos + 1;
        }
        n = n / 2;
        pos++;
    }

    return 0;
}

Above Code Explanation:
18 = 10010
n = 18
n = 9 after n/2
9 = 1001

*/

class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        return log2(n & -n) + 1;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; // input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
    return 0;
}

// } Driver Code Ends