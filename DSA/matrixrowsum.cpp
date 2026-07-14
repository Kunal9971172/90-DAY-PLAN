#include <iostream>
using namespace std;

void printRowSum(int arr[][4], int row, int col) {
  for (int i = 0; i < row; i++) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
      sum += arr[i][j];
    }
    cout << "Sum of rows is\n" << sum << endl;
  }
  cout << endl;
}
int main() {
  int arr[3][4];
  cout << "Enter the elements in the array";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
    }
  }
  printRowSum(arr, 3, 4);
}