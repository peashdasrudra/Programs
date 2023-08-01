#include <bits/stdc++.h>
using namespace std;

void fun(int);
void fun(double);
void fun(int i)
{
std::cout << "Value of i is : " <<i<< std::endl;
}
void fun(double j)
{
std::cout << "Value of j is : " <<j<< std::endl;
}
int main()
{
fun(12);
fun(1.2);
return 0;
}