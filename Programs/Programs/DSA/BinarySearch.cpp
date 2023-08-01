#include <bits/stdc++.h>
using namespace std;

int main()
{

    int size, target;
    cout << "Please Enter The Size of the Set : ";
    cin >> size;

    int set1[size];

    cout << "Please Enter Elements of the Set following by a space : ";
    for (int i = 0; i < size; i++)
    {

        cin >> set1[i];
    }

    cout << "Please Enter The Target Number you want to search: ";
    cin >> target;

    int left, right, middle;

    left = 0;
    right = size - 1;

    while (left <= right)
    {

        middle = (left + right) / 2;

        if (set1[middle] == target)
        {

            cout << " The Target " << set1[middle] << " is in positon " << middle +1 << endl;

            return 0;
        }

        else if (set1[middle] < target)
        {

            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
      
    }
      cout << "Target not found!" << endl;
}
