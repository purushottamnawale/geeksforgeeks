
//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

// } Driver Code Ends
//User function Template for Java

/* Class MathematicalOperation with add fucntion
* x, y : Two parameters of BigIntegers to add
*/
class MathematicalOperation {

    static BigInteger add(BigInteger x, BigInteger y) {
        return x.add(y);
    }

}

// { Driver Code Starts.

// Driver class with main function
class GFG {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int testcase = sc.nextInt();

        while (testcase-- > 0) {
            // Taking first element
            // in BigInteger x
            BigInteger x = sc.nextBigInteger();

            // Taking second element in
            // BigInteger y
            BigInteger y = sc.nextBigInteger();

            // Calling function add to add two BigIntegers
            MathematicalOperation obj = new MathematicalOperation();
            System.out.println(obj.add(x, y));
        }

    }
}
// } Driver Code Ends