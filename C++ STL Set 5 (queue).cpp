//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void push(queue<int> &q, int x);

int pop(queue<int> &q);
int getSize(queue<int> &q);

int getBack(queue<int> &q);

int getFront(queue<int> &q);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        queue<int> s;
        int q;
        cin >> q;
        while (q--)
        {
            char c;
            cin >> c;
            if (c == 'a')
            {
                int x;
                cin >> x;
                push(s, x);
            }
            if (c == 'b')
            {
                cout << pop(s) << " ";
            }
            if (c == 'c')
            {
                cout << getSize(s) << " ";
            }
            if (c == 'd')
            {
                cout << getFront(s) << " ";
            }
            if (c == 'e')
            {
                cout << getBack(s) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/*You are required to complete below methods*/

/*inserts an element x at
the back of the queue q */
void push(queue<int> &q, int x)
{
    q.push(x);
}

/*pop out the front element
from the queue q and returns it */
int pop(queue<int> &q)
{
    if (!q.empty())
    {
        int x = q.front();
        q.pop();
        return x;
    }
    return -1;
}

/*returns the size of the queue q */
int getSize(queue<int> &q)
{
    return q.size();
}

/*returns the last element of the queue */
int getBack(queue<int> &q)
{
    if (!q.empty())
    {
        return q.back();
    }
    return -1;
}

/*returns the first element of the queue */
int getFront(queue<int> &q)
{
    if (!q.empty())
    {
        return q.front();
    }
    return -1;
}
