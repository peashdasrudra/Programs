#include <iostream>
using namespace std;

int main() {
  int n1, n2;
  cout << "Enter the size of set 1: ";
  cin >> n1;
  int set1[n1];
  cout << "Enter the elements of set 1: ";
  for (int i = 0; i < n1; i++) {
    cin >> set1[i];
  }

  cout << "Enter the size of set 2: ";
  cin >> n2;
  int set2[n2];
  cout << "Enter the elements of set 2: ";
  for (int i = 0; i < n2; i++) {
    cin >> set2[i];
  }

  // Intersection
  int intersection[n1];
  int k = 0;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      if (set1[i] == set2[j]) {
        intersection[k] = set1[i];
        k++;
      }
    }
  }
  cout << "Intersection: { ";
  for (int i = 0; i < k; i++) {
    cout << intersection[i] << " ";
  }
  cout << "}" << endl;

  // Union
  int unionSet[n1 + n2];
  k = 0;
  for (int i = 0; i < n1; i++) {
    unionSet[k] = set1[i];
    k++;
  }
  for (int i = 0; i < n2; i++) {
    bool duplicate = false;
    for (int j = 0; j < n1; j++) {
      if (set2[i] == set1[j]) {
        duplicate = true;
        break;
      }
    }
    if (!duplicate) {
      unionSet[k] = set2[i];
      k++;
    }
  }
  cout << "Union: { ";
  for (int i = 0; i < k; i++) {
    cout << unionSet[i] << " ";
  }
  cout << "}" << endl;

  return 0;
}

Enter the size of set 1: 3
Enter the elements of set 1: 1 2 3
Enter the size of set 2: 2
Enter the elements of set 2: 3 4
Intersection: { 3 }
Union: { 1 2 3 4 }
