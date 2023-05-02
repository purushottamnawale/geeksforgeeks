
//{ Driver Code Starts
import java.util.Scanner;
import java.util.*;

class Collections_Set_1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            Set<Integer> s = new HashSet<Integer>();
            int q = sc.nextInt();

            while (q > 0) {
                GfG g = new GfG();
                char c = sc.next().charAt(0);
                if (c == 'a') {
                    int x = sc.nextInt();
                    g.insert(s, x);
                }
                if (c == 'b') {
                    g.print_contents(s);
                }
                if (c == 'c') {
                    int x = sc.nextInt();
                    g.erase(s, x);
                }
                if (c == 'd') {
                    int x = sc.nextInt();
                    System.out.print(g.find(s, x) + " ");
                }
                if (c == 'e')
                    System.out.print(g.size(s) + " ");
                q--;
                // System.out.println();
            }
            t--;
            System.out.println();
        }
    }
}
// } Driver Code Ends

/* You are required to complete below methods */
class GfG {
    /* inserts an element x to the set s */
    void insert(Set<Integer> s, int x) {
        s.add(x);
    }

    /* prints the contents of the set s in ascending order */
    void print_contents(Set<Integer> s) {
        Set<Integer> set = new TreeSet<>(s);
        Iterator it = set.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
    }

    /* erases an element x from the set s */
    void erase(Set<Integer> s, int x) {
        s.remove(x);
    }

    /* returns the size of the set s */
    int size(Set<Integer> s) {
        return s.size();
    }

    /*
     * returns 1 if the element x is
     * present in set s else returns -1
     */
    int find(Set<Integer> s, int x) {
        if (s.contains(x)) {
            return 1;
        }
        return -1;
    }
}