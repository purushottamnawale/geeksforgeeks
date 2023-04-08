//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

class Person
{
    string name;
    int number;
    int height;

public:
    Person() {}
    Person(string iname, int inumber, int iheight)
    {
        name = iname;
        number = inumber;
        height = iheight;
    }

    void display()
    {
        cout << name << " " << number << " " << height << endl;
    }

    void friend swapper(Person **obj1, Person **obj2);
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string name1;
        int number1, height1;
        cin >> name1;
        cin >> number1;
        cin >> height1;

        string name2;
        int number2, height2;
        cin >> name2;
        cin >> number2;
        cin >> height2;

        Person *p1 = new Person(name1, number1, height1);
        Person *p2 = new Person(name2, number2, height2);
        p1->display();
        p2->display();
        swapper(&p1, &p2);
        p1->display();
        p2->display();
    }
    return 0;
}

// } Driver Code Ends
// User function Template for C++

// Function to swap two objects **obj1 and **obj2
void swapper(Person **obj1, Person **obj2)
{
    Person *temp = *obj1;
    *obj1 = *obj2;
    *obj2 = temp;
}

//{ Driver Code Starts.

// } Driver Code Ends