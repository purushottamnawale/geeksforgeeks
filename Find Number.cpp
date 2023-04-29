//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
 0  1  2  3  4
 9  1  3  5  7  

 1  3  5  7  9
11 13 15 17 19
31 33 35 37 39
51 53 55 57 59
71 73 75 77 79
91 93 95 97 99

Base is 5

13%5=3 ->5
13/5=2 ->3*10+5 ->35

20%5=0 ->9
20/5-1=3 ->5*10+9 ->59
*/

class Solution
{
public:
    long long findNumber(long long N)
    {
        long long curr = 1, ans = 0;
        int arr[] = {9, 1, 3, 5, 7};
        while (N)
        {
            ans = arr[N % 5] * curr + ans;
            if (N % 5 == 0)
            {
                N = N / 5 - 1;
            }
            else
            {
                N = N / 5;
            }
            curr = curr * 10;
        }
        return ans;
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
        cout << ob.findNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends