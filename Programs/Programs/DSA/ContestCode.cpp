#include <bits/stdc++.h>
using namespace std;
int main()
{

    int s1, s2;
    cin >> s1 >> s2;
    int M[s1], N[s2];
    for (int i = 0; i < s1; i++)
    {
        cin >> M[i];
    }
    for (int j = 0; j < s2; j++)
    {
        cin >> N[j];
    }

    int UnionSet[s1 + s2];
    int size = 0;

    for (int i = 0; i < s1; i++)
    {

        UnionSet[size++] = M[i];
    }

    for (int i = 0; i < s2; i++)
    {

        bool exists = false;

        for (int j = 0; j < s1; j++)
        {

            if (N[i] == M[j])
            {

                exists = true;
                break;
            }
        }
        if (!exists)
        {

            UnionSet[size++] = s2[i];
        }
    }

    for (int i = 0; i < s1; i++)

    {

        {

            cout << UnionSet[i] << " ";
        }
        cout << "}" << endl;
    }
}
