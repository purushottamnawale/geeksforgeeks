//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// The Time Complexity is below program O(nLog(leaves)) and is based on Sieve.

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[])
    {
        bool visited[leaves+1]={0};
        for (int i = 0; i < N; i++)
        {
            int num = frogs[i];
            if (num <= leaves && !visited[num])
            {
                for (int j = num; j <= leaves; j += num)
                {
                    visited[j]=true;
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<=leaves;i++){
            if(!visited[i]){
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends