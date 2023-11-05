//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.BigInteger;


// } Driver Code Ends
//User function Template for Java

/* Class MathematicalOperation with add fucntion
* x, y : Two parameters of BigIntegers to multiply
*/
class MathematicalOperation{
    
    static BigInteger mul(BigInteger x, BigInteger y){
        return x.multiply(y);
    }
    
}

//{ Driver Code Starts.

// Driver class with main function
class GFG {
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int testcase = sc.nextInt();
		
		while(testcase-- > 0){
		    // Taking first element 
		    // in BigInteger x
		    BigInteger x = sc.nextBigInteger();
		    
		    // Taking second element in
		    // BigInteger y
		    BigInteger y = sc.nextBigInteger();
		    
		    // Calling function add to add two BigIntegers
		    MathematicalOperation obj = new MathematicalOperation();
		    System.out.println(obj.mul(x, y));
		}
		
		
	}
}
// } Driver Code Ends