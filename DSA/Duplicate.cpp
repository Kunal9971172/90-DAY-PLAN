#include <iostream>
using namespace std;

int Duplicate(int arr[], int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = arr[i] ^ ans;
  }
  for (int i = 1; i < n; i++) {
    ans = ans ^ i;
  }
  return ans;
}
int main() {
  int arr[5] = {1, 2, 3, 4, 4};
  cout << Duplicate(arr, 5) << endl;
  return 0;
}