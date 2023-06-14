//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
{2,1,7,4,2}
In priority Queue:
{7,4,2,2,1}

K=3, ans=7, push 7/2=3, delete 7
{4,3,2,2,1}

K=2, ans=7+4=11, push 4/2=2, delete 4
{3,2,2,2,1}

K=1, ans=7+4+3=14, push 3/2=1, delete 3
{2,2,2,1,1}

*/

class Solution
{
public:
    long long maxDiamonds(int A[], int N, int K)
    {
        priority_queue<int> pq(A, A + N);
        long long int ans = 0;
        while (K--)
        {
            ans += pq.top();
            pq.push(pq.top() / 2);
            pq.pop();
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
        int N, K;

        cin >> N >> K;
        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxDiamonds(A, N, K) << endl;
    }
    return 0;
}
// } Driver Code Ends