//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Nth Fibonacci Number:
Input:
1 2

Output:
1

Fibonacci Number:

*/
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        long long int nextTerm,t1=0,t2=1;
        if(n==0 || n==1){
            return n;
        }
        for(int i=1;i<n;i++){
            nextTerm=(t1+t2)%1000000007;
            t1=t2;
            t2=nextTerm;
        }
        return nextTerm;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends