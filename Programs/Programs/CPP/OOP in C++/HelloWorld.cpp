#include<bits/stdc++.h>
using namespace std;

class Student
{

public:
 string name;
int id;
float cgpa;

};

Student (string name),int id,float cgpa)

{

this -> name = name;
this -> id = id;
this -> cgpa = cgpa;

}

void display()

{

cout<<"The Details of"<<name<<"is"<<endl<<"ID :"<<id<<endl<<"CGPA :"<<cgpa<<endl;

}

int main ()
{

Student.student1 ("Raddiya Sultana,749,3.80");
Student.student2 ("Peash Das Rudra,719,3.70");
student1.display()
student2.display()

}