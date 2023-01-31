//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    bool isPrime(int num){
            for(int i=2;i<=sqrt(num);i++){
                if(num%i==0){
                    return false;
                }
            }
            return true;
        }
	
	
		int NthTerm(int N){
            int diff1=INT_MAX;
            int diff2=INT_MAX;
        
            for(int i=N;i>=2;i--){
                if(isPrime(i)){
                    //cout<<n-i<<endl;
                    diff1=N-i;
                    break;
                }
            }
        
            for(int i=N+1;i>N;i++){
                if(isPrime(i)){
                    //cout<<i-n<<endl;
                    diff2=i-N;
                    break;
                }
            }
        
            if(diff1<=diff2){
                return diff1;
            }
            else{
                return diff2;
            }
        		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends