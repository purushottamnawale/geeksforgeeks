//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
Rotate Bits


Input:
1 28 2

Output:
112 7

Explanation:
N = 28, D = 2

Rotating left by 2 positions
28 = 0000000000011100
28 << 2 = 0000000001110000
28 >> 14 = 0000000000000000
0000000001110000 | 0000000000000000 = 0000000001110000
0000000001110000 & 1111111111111111 = 0000000001110000 = 112

Rotating right by 2 positions
28 = 0000000000011100
28 >> 2 = 0000000000000111
28 << 14 = 111_0000000000000000 Beyond 16 bits
0000000000000111 | 111_0000000000000000 = 111_0000000000000111
111_0000000000000111 & 1111111111111111 = 0000000000000111 = 7 Discard the extra bits


(0xFFFF) in Hexadecimal = (1111111111111111) in binary
0xFFFF is a 16-bit number where all the bits are set to 1.
Performing a bitwise AND with 0xFFFF effectively retains only the least significant 16 bits of the result,
while all bits beyond the 16th position are set to 0.

d = d % 16 is to ensure that we perform only the necessary rotations. 
As we know integer n is stored using 16 bits, so rotation of 16 is same as rotation of 0, 
rotation of 17 is same as rotation of 1 and so on.



*/
class Solution
{
public:
    vector<int> rotate(int n, int d)
    {
        int a, b;
        d = d % 16; // 
        a = (n << d | (n >> (16 - d))) & 0xFFFF;
        b = (n >> d | (n << (16 - d))) & 0xFFFF;
        return {a, b};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, d;
        cin >> n >> d;
        Solution ob;
        vector<int> res = ob.rotate(n, d);
        cout << res[0] << endl
             << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends