#include <iostream>

using namespace std;

int main()
{
    int i, j, s1, s2;
    // Declare the fist array size
    cout << "Input the size of set A:";
    cin >> s1;
    int A[s1];
    // input the data in array
    cout << "Input the elements of set A:";
    for (i = 0; i < s1; i++)
    {
        cin >> A[i];
    }
    // Declear the second array size
    cout << "Input the size of set B:";
    cin >> s2;
    int B[s2];
    // input the data in second array
    cout << "Input the elements of set B:";
    for (i = 0; i < s2; i++)
    {
        cin >> B[i];
    }
    // input the data of array1 to union array
    int U[s1 + s2];
    for (i = 0; i < s1; i++)
    {
        U[i] = A[i];
    }
    // input the data of array2 to union aarray
    int k = s1;
    for (i = 0; i < s2; i++)
    {
        int c = 1;
        for (j = 0; j < s1; j++)
        {
            if (B[i] == A[j])
            {
                c = 0;
                break;
            }
        }
        if (c == 1)
        {
            U[k] = B[i];
            k++;
        }
    }
    // print the union array
    int p = k;
    cout << "A U B :";
    for (i = 0; i < p; i++)
    {
        cout << U[i] << " ";
    }
}