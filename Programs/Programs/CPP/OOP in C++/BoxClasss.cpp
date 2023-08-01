#include<iostream>
using namespace std;

class Box {
    private:
double length;
double breadth;
double height;

public:
Box (double l = 2.0, double b = 2.0, double h = 2.0)
{ cout << "Constructor called."<< endl;
length = l;
breadth = b;
height = h;
}

double volume ()
{
    return length * breadth * height;
}
int compare (Box box)
{
    return this -> volume () > box.volume ();
}
};

int main () {
Box box1 (1.1,5.3,2.4);
Box box2 (2.1, 2.2, 2.3);

if (box2.compare(box1))

{

cout << " BOX 1 is Smaller Than BOX 2"<< endl;
}


else {

cout << " BOX 2 is Similar or Bigger Than BOX 1"<< endl;

}
}
