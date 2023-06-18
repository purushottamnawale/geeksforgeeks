//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
Let K=3 for below explaination
Given, N,K
m = N / K - No. of Groups of size K
r = N % K - Remaining people who doesn't belong to any group

We divide numbers from both sides as required

Case 1)                                 General form
m is even & r!=0
1 2 3 4 5 6 7 8 9 10 11 12 13 14        K *(m/2) + r
_____ _____ ___ _______ ________
Ans=8

Case 2)
m is even & r==0
1 2 3 4 5 6 7 8 9 10 11 12              K*(m/2) + 1
_____ _____ _____ ________
Ans=9

Case 3)
m is odd & r!=0
1 2 3 4 5 6 7 8 9 10                    K*(m/2 + 1) + 1
_____ _____ _ ______
Ans=7

Case 4)
m is odd & r==0
1 2 3 4 5 6 7 8 9                       K*(m/2 + 1)
_____ _____ _____
Ans=6
*/

class Solution
{
public:
    int distributeTicket(int N, int K)
    {
        int m = N / K;
        int r = N % K;
        if (m % 2 == 0 && r)
        {
            return K * (m / 2) + r;
        }
        if (m % 2 == 0 && !r)
        {
            return K * (m / 2) + 1;
        }
        if (m % 2 && r)
        {
            return K * (m / 2 + 1) + 1;
        }
        if (m % 2 && r == 0)
        {
            return K * (m / 2 + 1);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        Solution obj;
        int res = obj.distributeTicket(N, K);

        cout << res << endl;
    }
}

// } Driver Code Ends