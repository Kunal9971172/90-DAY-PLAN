
#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int n, int key) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n;
  cout << " Enter the number of array : ";
  cin >> n;
  int arr[n];
  cout << "Enter the numbers for array : ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int key;
  cout << "Enter the element to search ";
  cin >> key;
  bool found = LinearSearch(arr, n, key);
  if (found) {
    cout << "The element is Present" << endl;
  } else {
    cout << "The element is not Present" << endl;
  }
}
