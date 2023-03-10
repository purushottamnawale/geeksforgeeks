//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	int a,b,c=INT_MIN;
    	for(int i=0;i<n;i++){
    	    if(c<arr[i]){
    	        c=arr[i];
    	    }
    	    if(b<arr[i]<c && i>0){
    	        b=arr[i];
    	    }
    	    if(a<arr[i]<b && i>1){
    	        a=arr[i];
    	    }
    	    
    	}
    	return a*b*c;

        
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends