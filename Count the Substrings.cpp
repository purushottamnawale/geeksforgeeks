//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*
    For input 1 WomensDAY
    1. Replace each uppercase character with 1 and lower case character with -1.
    0  1 -1 -1 -1 -1 -1  1  1  1
    Any subarray having sum 0 will be having equal number of upper case and lower case characters.
    After the map declaration, we store zero with count 1;

    2. Use map and prefix sum to count the number of subarrays having zero sum.
    0  1  0 -1 -2 -3 -4 -3 -2 -1

    3. In above prefix sum, whenever a sum repeats itself, it means that there is a zero sum subarray.
*/

class Solution
{
    public:
    int countSubstring(string S)
    {
        unordered_map<int,int> map;
        map[0]=1;
        int ans=0;
        int sum=0;
        for(char ch:S){
            int val;
            if(isupper(ch)){
                val=1;
            }
            else{
                val=-1;
            }
            sum+=val;
            if(map.find(sum)!=map.end()){ // If map.find(sum) != map.end(), it means that the key sum is found in the map, and there is at least one element with that key. If map.find(sum) == map.end(), it means that the key sum is not found in the map, and there are no elements with that key.
                ans+=map[sum];
            }
            map[sum]++;
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends