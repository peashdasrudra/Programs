#include <bits/stdc++.h>
using namespace std;

int main()
{

    int size1, size2;
    int set1[20];
    int set2[20];

    cout << "                                       -----------  UNION CHECKER APP  ------------         " << endl;
    cout << "                                                Peash Das Rudra (CSE-719)          " << endl
         << endl
         << endl;
    cout << "Please Enter The Number of Elements of Set 1:" << endl;
    cin >> size1;

    cout << "Please Enter The Number of Elements of Set 2:" << endl;
    cin >> size2;

    cout << "Please Enter The Elements of Set 1:" << endl;
    for (int i = 0; i < size1; i++)
    {
        cin >> set1[i];
    }

    cout << "Please Enter The Elements of Set 2:" << endl;
    for (int j = 0; j < size2; j++)
    {
        cin >> set2[j];
    }

    int UnionSet[size1 + size2];
    int size = 0;

    for (int i = 0; i < size1; i++)
    {

        UnionSet[size++] = set1[i];
    }

    for (int i = 0; i < size2; i++)
    {

        bool exists = false;

        for (int j = 0; j < size1; j++)
        {

            if (set2[i] == set1[j])
            {

                exists = true;
                break;
            }
        }
        if (!exists)
        {

            UnionSet[size++] = set2[i];
        }
    }

    cout << "The Union of the Two Sets is: { ";

    for (int i = 0; i < size; i++)
    {

        cout << UnionSet[i] << " ";
    }
    cout << "}" << endl;
}
