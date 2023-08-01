#include <bits/stdc++.h>
using namespace std;

int main()
{

    int size1, size2;

    cout << "Please enter the number of elements in Set 1: " << endl;
    cin >> size1;

    cout << "Please enter the number of elements in Set 2: " << endl;
    cin >> size2;

    int Set1[size1];
    int Set2[size2];

    cout << "Please enter the elements of Set 1: " << endl;
    int i, j;
    for (i = 0; i < size1; i++)
    {
        cin >> Set1[i];
    }

    cout << "Please enter the elements of Set 2: " << endl;

    for (j = 0; j < size2; j++)
    {
        cin >> Set2[j];
    }

    int SubtSet[size1 + size2];
    int size = 0;

    for (j = 0; j < size2; j++)
    {
        bool exists = false;
        for (int i = 0; i < size1; i++)
        {
            if (Set2[j] == Set1[i])
            {
                exists = true;
                SubtSet[size++] = Set2[j];
            }

            if (!exists)
            {
                break;
            }
        }

       cout << "The Union of the Two Sets is: { ";

    for (int i = 0; i < size; i++)
    {

        cout << SubtSet[i] << " ";
    }
    cout << "}" << endl;
}

}

