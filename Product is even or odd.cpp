//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int EvenOdd(string n1, string n2);

// driver code
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string n1;
        cin >> n1;
        string n2;
        cin >> n2;
        cout << EvenOdd(n1, n2) << endl;
    }
    return 0;
}

// } Driver Code Ends

int EvenOdd(string n1, string n2)
{
    
    return !(n1.back() * n2.back() & 1);
}