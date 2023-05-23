//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;

// } Driver Code Ends

/*
1abc23

sum=0
ans=0


i=0
sum=sum*10+1=0*10+1=1

i=1
ans=ans+sum=0+1=1
sum=0

i=2
ans=ans+sum=0+1=1
sum=0

i=3
ans=ans+sum=0+1=1
sum=0

i=4
sum=sum*10+2=0*10+2=2

i=5
sum=sum*10+3=2*10+3=23

return ans+sum=1+23=24
*/

class Solution
{
public:
    // Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
        int sum = 0, ans = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if ('0' <= str[i] && str[i] <= '9')
            {
                sum = sum * 10 + str[i] - '0';
            }
            else
            {
                ans += sum;
                sum = 0;
            }
        }
        return ans + sum;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    // input alphanumeric string
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.findSum(str);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends