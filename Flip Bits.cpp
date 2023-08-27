//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Flip Bits

Example 1)
Input:
1
5
1 0 0 1 0

Output:
4

Example 2)
Input:
1
7
1 0 0 1 0 0 1

Output:
6
*/

class Solution
{
public:
    // Solution is based on Kadane's Algorithm
    int maxOnes(int a[], int n)
    {
        int maxSum, currSum, oneCnt;
        maxSum = currSum = oneCnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                oneCnt++;
                currSum--;
            }
            else
            {
                currSum++;
            }
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxSum + oneCnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxOnes(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends