//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*
Binary 2(0,1)
N=5 => 00,01,10,11,100,101,1000

2 | 5 | 1
  | 2 | 0 = 101
  | 1 |


3(0,1,2)
N=7 =>0,1,2,10,11,12,20,21,22

3 | 7 | 1 => 21
  | 2 |


9(0,1,2,3,4,5,6,7,8)
N=9 => 0,1,2,3,4,5,6,7,8,10

9 | 9 | 0 => 10
  | 1 | 1

9 | 21 | 3 => 23
  | 2  | 

*/


class Solution{
	public:
    long long findNth(long long N)
   {
       long long ans = 0 ,d = 0;
       while(N){
           long long x = N%9;
           ans =ans+ x*pow(10,d++);
           N/=9;
       }
       return ans;
   }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}


// } Driver Code Ends