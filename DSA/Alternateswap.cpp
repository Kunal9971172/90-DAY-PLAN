#include <iostream>
using namespace std;

void Alternateswap(int arr[], int n) {
  for (int i = 0; i < n; i += 2) {
    if (i + 1 < n) {
      swap(arr[i], arr[i + 1]);
    }
  }
}
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
int main() {
  int n;
  cout << "Enter the size of Array : ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements of the array : ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "This is the orignal array: \n";
  printArray(arr, n);
  Alternateswap(arr, n);
  cout << "\n This is the swapped array: \n";
  printArray(arr, n);
  return 0;
}