//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Example 1:
2A5=677

iteration 1
digit=2
decimal = 0*16 + 2 = 2

iteration 2
digit=10
decimal = 2*16 + 10 = 42

iteration 3
digit=5
decimal = 42*16 + 5 = 677

(2*16 + 10)*16 + 5 = 677
2*16*16 + 10*16 + 5 = 677



Example 2:
4D86B=317547

iteration 1
digit=4
decimal = 0*16+4 = 4

iteration 2
digit=13
decimal = 4*16 + 13 = 77

iteration 3
digit=8
decimal = 77*16 + 8 = 1240

iteration 4
digit=6
decimal = 1240*16 + 6 = 19846

iteration 5
digit=11
decimal = 19846*16 + 11 = 317547

(4*16 + 13)*16 + 8)*16 + 6)*16 + 11 = 317547
4*16*16*16*16 + 13*16*16*16 + 8*16*16 + 6*16 + 11 = 317547
4*65536 + 13*4096 + 8*256 + 6*16 + 11 = 317547



Example 3:
1111011=123

iteration 1
digit=1
decimal = 0*2+1 = 1

iteration 2
digit=1
decimal = 1*2 + 1 = 3

iteration 3
digit=1
decimal = 3*2 + 1 = 7

iteration 4
digit=1
decimal = 7*2 + 1 = 15

iteration 5
digit=0
decimal = 15*2 + 0 = 30

iteration 6
digit=1
decimal = 30*2 + 1 = 61

iteration 7
digit=1
decimal = 61*2 + 1 = 123

(1*2 + 1)*2 + 1)*2 + 1)*2 + 0)*2 + 1)*2 + 1 = 123
1*2^6 + 1*2^5 + 1*2^4 + 1*2^3 + 0*2^2 + 1*2^1 + 1*2^0 = 123
1*64 + 1*32 + 1*16 + 1*8 + 0*4 + 1*2 + 1*1 = 123
*/

class Solution
{
public:
    int decimalEquivalent(string N, int b)
    {
        int ans = 0;
        for (char c : N)
        {
            int digit = isdigit(c) ? c - '0' : c - 'A' + 10;
            if (digit >= b)
            {
                return -1;
            }
            ans = (ans * b) + digit;
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
        int b;
        cin >> b;
        string N;
        cin >> N;

        Solution ob;
        cout << ob.decimalEquivalent(N, b) << "\n";
    }
    return 0;
}
// } Driver Code Ends