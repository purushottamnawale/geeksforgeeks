//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
void print(deque<int> &A);
void add_in_back(deque<int> &A, int x);
void remove_from_back(deque<int> &A);
void remove_from_front(deque<int> &A);
void sort(deque<int> &A);
void reverse(deque<int> &A);
int size(deque<int> &A);
void add_in_front(deque<int> &A, int x);
int element_at_front(deque<int> &A);
int element_at_back(deque<int> &A);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        deque<int> A;
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
                add_in_front(A, x);
                print(A);
                break;
            }
            case 2:
            {
                int x;
                cin >> x;
                add_in_back(A, x);
                print(A);
                break;
            }
            case 3:
            {
                if (A.empty())
                    cout << "-1" << endl;
                else
                {
                    remove_from_front(A);
                    print(A);
                }
                break;
            }
            case 4:
            {
                if (A.empty())
                    cout << "-1" << endl;
                else
                {
                    remove_from_back(A);
                    print(A);
                }
                break;
            }
            case 5:
            {
                if (A.empty())
                    cout << "-1" << endl;
                else
                {
                    sort(A);
                    print(A);
                }
                break;
            }
            case 6:
            {
                if (A.empty())
                    cout << "-1" << endl;
                else
                {
                    reverse(A);
                    print(A);
                }
                break;
            }
            case 7:
            {
                if (A.empty())
                    cout << "-1" << endl;
                else
                    print(A);
                break;
            }
            case 8:
            {
                cout << size(A) << endl;
                break;
            }
            case 9:
            {
                if (A.empty())
                    cout << "-1" << endl;
                else
                    cout << element_at_front(A) << endl;
                break;
            }
            case 10:
            {
                if (A.empty())
                    cout << "-1" << endl;
                else
                    cout << element_at_back(A) << endl;
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

void print(deque<int> &A)
{
    if (A.empty())
    {
        cout << -1;
    }
    else
    {
        for (auto i = A.begin(); i != A.end(); i++)
        {
            cout << *i << " ";
        }
    }
    cout << endl;
}

void add_in_front(deque<int> &A, int x)
{
    A.push_front(x);
}

void add_in_back(deque<int> &A, int x)
{
    A.push_back(x);
}

void remove_from_back(deque<int> &A)
{
    if (A.empty())
    {
        cout << -1;
    }
    else
    {
        A.pop_back();
    }
}

void remove_from_front(deque<int> &A)
{
    if (A.empty())
    {
        cout << -1;
    }
    else
    {
        A.pop_front();
    }
}

void sort(deque<int> &A)
{
    sort(A.begin(), A.end());
}

void reverse(deque<int> &A)
{
    reverse(A.begin(), A.end());
}

int size(deque<int> &A)
{
    return A.size();
}

int element_at_front(deque<int> &A)
{
    return A.front();
}

int element_at_back(deque<int> &A)
{
    return A.back();
}
