#include <iostream>
using namespace std;

class Student
{
public:
    int x;
    Student()
    { // Default Constructor
       // x = 99;
    }
    Student(int a)
    { // Parameterized Constructor
        x = a;
    }
};

int main()
{
    Student s1(0);           // Implicit call on Parameterized Constructor.
    Student s2 = Student(22); // Explicit call on Parameterized Constructor.

    cout << "From Implicit : " << s1.x << endl
         << "From Explicit : " << s2.x;
    return 0;
}