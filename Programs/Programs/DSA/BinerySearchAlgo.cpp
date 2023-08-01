#include <iostream>
using namespace std;

int main()
{

    int a[] = {1, 2, 3, 4, 5, 88, 99, 100};
    int item = 99;

    int left, right, middle;

    left = 0;
    right = 7;

    while (left <= right)
    {

        middle = (left + right) / 2;

        if (a[middle] == item)
        {
            cout << "The " << a[middle] << " is in position " << middle << endl;

            return 0;
        }
        else if (a[middle] < item)
        {
            left = middle + 1;
        }

        else
        {
            right = middle - 1;
        }
    }

    cout << "Item Not Found" << endl;

    return 0;
}