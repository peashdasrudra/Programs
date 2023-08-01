#include<bits/stdc++.h>

using namespace std;

class Box { 

public: 

float len, bre, hie;

Box (float l, float b, float h) {

len = l;
bre = b;
hie = h;
}

float area() {

float a;

a = l . b; 

}

float volume() {

float v;

v = l . b . h;

}

void display() {

cout << " The Area of The Box is :" << a << endl << " The Volume of the box is : " << v << endl;

}

int main ()

Box box1(1.2,2.1,3.2)
box1.display;



Create a class box and Box3d. box3d is an extended class of boxes. The above two classes are going to fulfill following requirments:
1. Include constructor
2. Set value of length, breadth, and height using the method 
3. Find The area and volume in another method

where base classes and sub classes have respective methods and instance variables. 


2. Invoke a method named Cool () of the class AC without creating the object of the class.