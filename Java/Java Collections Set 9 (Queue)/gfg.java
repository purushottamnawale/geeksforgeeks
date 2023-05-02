//{ Driver Code Starts
//Initial Template for Java

// Java orogram to demonstrate working of Queue
// interface in Java
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class gfg {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int flag = 0;
            QueueClass obj = new QueueClass();
            while (n-- > 0) {
                flag = 0;
                char p = sc.next().charAt(0);
                if (p == 'a') {
                    int k = sc.nextInt();
                    obj.addElement(k);
                } else if (p == 'r')
                    obj.RemoveElement();
                else if (p == 'p')
                    obj.peekElement();
                else
                    obj.Size();
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends
// User function Template for Java

class QueueClass {
    Queue<Integer> q;

    QueueClass() {
        q = new LinkedList<>();
    }

    public void addElement(int key) {
        q.add(key);
    }

    public void RemoveElement() {
        if (q.size() == 0) {
            System.out.print("-1" + " ");
        } else {
            System.out.print(q.remove() + " ");
        }
    }

    public void peekElement() {
        if (q.size() == 0) {
            System.out.print("-1" + " ");
        } else {
            System.out.print(q.peek() + " ");
        }
    }

    public void Size() {
        System.out.print(q.size() + " ");
    }
}

// { Driver Code Starts.

// } Driver Code Ends