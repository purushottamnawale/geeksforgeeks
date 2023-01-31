//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// CollegeCourse Class
class CollegeCourse
{
public:
    string courseId;
    char grade;
    int credits;

    void set_CourseId(string CID)
    {
        courseId = CID;
    }

    void set_Grade(char g)
    {
        grade = g;
    }
    void set_Credit(int cr)
    {
        credits = cr;
    }

    int calculateGradePoints(char g)
    {
        if (g == 'A' || g == 'a')
        {
            grade = 10;
        }
        else if (g == 'B' || g == 'b')
        {
            grade = 9;
        }
        else if (g == 'C' || g == 'c')
        {
            grade = 8;
        }
        else if (g == 'D' || g == 'd')
        {
            grade = 7;
        }
        else if (g == 'E' || g == 'e')
        {
            grade = 6;
        }
        else
        {
            grade = 5;
        }
        return grade;
    }

    float calculateHonorPoints(int gp, int cr)
    {
        return grade * credits;
    }

    void display()
    {
        cout << int(grade)<<" ";
        cout << grade * credits << endl;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        CollegeCourse cc;
        string courseId;
        int gp;
        char grade;
        int credits;
        cin >> courseId >> grade >> credits;
        cc.set_CourseId(courseId);
        cc.set_Grade(grade);
        cc.set_Credit(credits);
        gp = cc.calculateGradePoints(grade);
        cc.calculateHonorPoints(gp, credits);
        cc.display();
    }
    return 0;
}

// } Driver Code Ends