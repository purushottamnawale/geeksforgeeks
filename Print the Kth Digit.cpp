//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int kthDigit(int A,int B,int K){
        long long int d=pow(A,B)/pow(10,K-1);
        return d%10;
    }
};

// int kthDigit(int A,int B,int K){
//     long long int a=pow(A,B);
//     long long int b=pow(10,K-1);
//     long long int d=a/b;
//     return d%10;
// }

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int A,B,K;
        cin>>A>>B>>K;
        Solution ob;
        cout << ob.kthDigit(A,B,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends