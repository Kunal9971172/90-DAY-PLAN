#include <iostream>
using namespace std;

void reverse(int arr[], int n) {
  int start = 0;
  int end = n - 1;
  while (start <= end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}
void printArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  int n;
  cout << "Enter the size: ";
  cin >> n;
  int arr[n];
  cout << "Enter the Elements of array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "This is the orignal array: \n:  ";
  printArr(arr, n);
  reverse(arr, n);
  cout << "This is the reversed array: \n:  ";
  printArr(arr, n);
}