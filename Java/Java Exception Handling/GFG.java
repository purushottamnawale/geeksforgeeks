//{ Driver Code Starts
//Initial Template for Java
/*package whatever //do not write package name here */

import java.io.*;
import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            TestClass obj1 = new TestClass(a, b);
            obj1.findMin();
        }
    }
}

// } Driver Code Ends
// User function Template for Java

class TestClass {
    // Add your code here. Define private variables, Constructors to initialize
    // variables with the given values and a method findMin() which prints the
    // Minimum value of a$b.
    private int m, n;

    public TestClass(int m, int n) {
        this.m = m;
        this.n = n;
    }

    public void findMin() {
        int sum = m + n;
        int diff = m - n;
        int mul = m * n;
        int min1 = Math.min(mul, Math.min(sum, diff));
        try {
            int div = m / n; // Floating point exception
            int min2 = Math.min(div, min1);
            System.out.println(min2);
        } catch (Exception e) {
            System.out.println(min1);
        }
    }
}

// { Driver Code Starts.

// } Driver Code Ends