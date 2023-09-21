//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

/*
Stickler Thief

Input:
1
6
5 20 10 100 10 5

Output:
125


Explanation:
1
6
5 20 10 100  10   5

DP Table:
5 20 20 120 120 125

val1 = 5
val2 = 20

for i = 2
    sum = 20
    val1 = 20
    val2 = 20

    i = 3
    sum = 120
    val1 = 20
    val2 = 120

    i = 4
    sum = 120
    val1 = 120
    val2 = 120

    i = 5
    sum = 125
    val1 = 120
    val2 = 125

*/

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int val1 = arr[0];
        if (n == 1)
        {
            return val1;
        }
        int val2 = max(arr[0], arr[1]);
        if (n == 2)
        {
            return val2;
        }
        int sum;
        for (int i = 2; i < n; i++)
        {
            sum = max(arr[i] + val1, val2);
            val1 = val2;
            val2 = sum;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends