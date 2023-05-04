//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Time Complexity: O(n*r)
Space Complexity: O(r)

nCr = n! / (r! * (n-r)!)

4C0 4C1 4C2 4C3 4C4
 1   4   6   4   1

3C0 3C1 3C2 3C3
 1   3   3   1


Pascal Triangle
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

Current Row Element = Previous Row Element + (Previous Row-1) Element
nCr = nCn-r

Find 4C2
We are going to create a new array using previous array

  r   0 1 2
i
0     1 0 0
1     1 1 0
2     1 2 1
3     1 3 3 | 1
4     1 4 6 | 4 1

We starting the loop from top to bottom (1 to n) and right to left (r to 0)
*/


class Solution{
public:
    int nCr(int n, int r){
        if(n<r){
            return 0;
        }
        if((n-r)<r){ // nCr = nCn-r
            r=n-r; 
        }
        int mod=1e9+7;

        int dp[r+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1; // 0C0 = 1
        for(int i=1;i<=n;i++){
            for(int j=min(i,r);j>0;j--){  
                dp[j]=(dp[j]+dp[j-1])%mod; 
            }
        }
        return dp[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends