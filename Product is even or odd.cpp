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

/*
Odd*Odd=Odd
Odd*Even=Even
Even*Even=Even
Even number's binary representation ends with 0

Example No.1:
n1="455"
n2="322"

n1.back()='5' => 53 in ASCII
n2.back()='2' => 50 in ASCII

n1.back() * n2.back() = '5' * '2' =  53 * 50 = 2650
2650 & 1 = 0
101001011010 & 000000000001 = 0
!0 = 1

Example No.2:
n1="455"
n2="321"

n1.back()='5' => 53 in ASCII
n2.back()='1' => 49 in ASCII
n1.back() * n2.back() = '5' * '1' =  53 * 49 = 2597
2597 & 1 = 1
101000100101 & 000000000001 = 1
!1 = 0




*/

int EvenOdd(string n1, string n2)
{
    
    return !(n1.back() * n2.back() & 1);
}