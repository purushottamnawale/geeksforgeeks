//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
void addElement(priority_queue<int> &A, int x);
void remove_Element(priority_queue<int> &A);
int getSize(priority_queue<int> &A);
int getElement_at_top(priority_queue<int> &A);
void print(priority_queue<int> &A);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        priority_queue<int> A;
        while (q--)
        {
            int c;
            cin >> c;
            switch (c)
            {
            case 1:
            {
                int x;
                cin >> x;
                addElement(A, x);
                print(A);
                break;
            }
            case 2:
            {
                remove_Element(A);
                break;
            }
            case 3:
            {
                cout << getElement_at_top(A) << endl;
                break;
            }
            case 4:
            {
                cout << getSize(A) << endl;
                break;
            }
            case 5:
            {
                print(A);
                break;
            }
            default:
                return 0;
            }
        }
    }
    return 0;
}

// } Driver Code Ends

// User function Template for C++
//   Function to add an element to a priority queue
void addElement(priority_queue<int> &A, int x)
{
    A.push(x);
}

// Function to remove the top element from a priority queue and print it
void remove_Element(priority_queue<int> &A)
{
    // If the priority queue is not empty
    if (!A.empty())
    {
        cout << A.top() << "\n";
        A.pop();
    }
    else
    {
        cout << -1 << "\n";
    }
}

// Function to return the top element of a priority queue
int getElement_at_top(priority_queue<int> &A)
{
    // Return -1 if the queue is empty, otherwise return the top element
    return A.empty() ? -1 : A.top();
}

// Function to return the size of a priority queue
int getSize(priority_queue<int> &A)
{
    return A.empty() ? -1 : A.size();
}

// Function to print the elements in a priority queue without emptying the queue
void print(priority_queue<int> &A)
{
    if (A.empty())
    {
        cout << -1 << endl;
        return;
    }
    priority_queue<int> temp = A;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}