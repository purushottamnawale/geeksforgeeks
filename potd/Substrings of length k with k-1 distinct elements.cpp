//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        int ans=0;
        int j=0;
        unordered_map<char,int> map;
        
        for(int i=0;i<S.size();i++){
            map[S[i]]++;
            if(i+1>=K){
                if(map.size()==K-1){
                    ans++;
                }
                map[S[j]]--;
                if(map[S[j]]==0){
                    map.erase(S[j]);
                }
                j++;
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
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends