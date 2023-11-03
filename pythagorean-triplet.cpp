//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	     unordered_set<int> s;
	    for(int i = 0;i<n;i++) s.insert(arr[i]);
	    for(int i = 1;i<=1000;i++) {
	        for(int j = i+1;j<=1000;j++) {
	            int k = i*i + j*j;
	            int p = sqrt(k);
	            if(p*p == k && p <= 1000) {
	                if(s.find(i) != s.end() && s.find(j) != s.end() && s.find(p) != s.end()) return true;
	            }
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends