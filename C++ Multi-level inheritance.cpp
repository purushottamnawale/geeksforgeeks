//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

class student
{
    protected :
        int roll_number;
        
    public:
        void set_number(int a)
        {
            roll_number = a;
        }
        
        void display_number()
        {
            cout<<roll_number<<endl;
        }
};


// } Driver Code Ends
//User function Template for C++
class test: public student 
{
    public:
    float s1,s2,s3,s4,s5;
    void set_marks(float *temp){
        s1=temp[0];
        s2=temp[1];
        s3=temp[2];
        s4=temp[3];
        s5=temp[4];
    }
};

class result: public test
{
    public:
    int hero=s1;
    void display(){
        float total=s1+s2+s3+s4+s5;
        float average=total/5;
        cout<<roll_number<<" "<<total<<" "<<average<<" "<<hero<<endl;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
    	result student1;
	    int n;
	    cin>>n;
	    student1.set_number(n);
	    float temp[5];
	    int i;
	
	    for(i = 0; i < 5; i++)
	        cin>>temp[i];
	
	    student1.set_marks(temp);
	    student1.display();
	}

	return 0;    
}

// } Driver Code Ends