//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

void inputData();

// } Driver Code Ends
// User function Template for C++

void inputData()
{
    int a;
    string b;
    // Use cin to take input and cout a and b with a space between them.
    // You don't have to print any new lines after cout
    cin >> a >> b;
    cout << a << " " << b;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // function call
        inputData();
        cout << endl;
    }
}

// } Driver Code Ends