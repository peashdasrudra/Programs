#include<bits/stdc++.h>
using namespace std ;

class student 
{
    private :
    string name;

    public :
    int id ;
    float gpa;
    string address;

    virtual void sendmessege() = 0 ;

    void setname(string name)
    {
        this -> name = name ;
    }
    string getname()
    {
        return name;
    }

    student (int id , float gpa , string address)
    {
        this -> id = id;
        this -> gpa = gpa;
        this -> address = address ;
    }
    void display ()
    {
        cout << "Id number =" << id << endl << "Result in gpa =" << gpa << endl << "Address =" << address << endl << endl  ;
    } 
}; 
class musfiq : public student 
{
    public :
    musfiq(int id , float gpa , string address)
    :student(id,gpa,address)
    {

    }
    void sendmessege()
    {
        cout  << endl << "Details of " ;
    }

};
class masud : public student
{
    public :
    masud(int id , float gpa , string address)
    :student(id,gpa,address)
    {

    }
    void sendmessege()
    {
        cout << endl << "Details of ";
    }
};

int main()
{
    string address,address2;
    
    student *prncple ;

    getline(cin , address);
    musfiq p1(220120794,3.083,address) ;
    prncple = &p1 ;
    prncple -> setname("Syed Musfiq Hossain");
    prncple -> sendmessege();
    cout << prncple -> getname() << endl ;
    prncple -> display();
    

    getline(cin , address2);
    masud p2(220120760,2.876,address2) ;
    prncple = &p2;
    prncple -> setname("Masudur Rahaman");
    prncple -> sendmessege();
    cout << prncple -> getname() << endl ;
    prncple -> display();
    

}