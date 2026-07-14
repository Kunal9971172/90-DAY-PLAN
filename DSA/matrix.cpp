#include <iostream>
using namespace std;

bool isFound(int arr[][4], int target, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] == target) {
        return true;
      }
    }
  }
  return false;
}
int main() {
  int arr[3][4];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
    }
  }
  cout << "Enter the element to search:  ";
  int target;
  cin >> target;

  if (isFound(arr, target, 3, 4)) {
    cout << "Element is Present: ";
  } else {
    cout << "Element is not present";
  }
}
