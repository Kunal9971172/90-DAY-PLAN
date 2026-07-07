#include <iostream>
using namespace std;
// Q1 Print the pattern  SQAURE PATTERN

/*void pattern1(int n){
    for (int i=0;i<n;i++){
        for (int j= 0;j<n;j++){
            cout<<"*";

        }
        cout <<endl;
}
}
int main(){
    int n;
    cin>>n;
    pattern1(n);
    return 0;
}*/

// Q2 Print the pattern  RIGHT ANGLE TRIANGLE PATTERN
void pattern2(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << i << " ";
    }
    cout << endl;
  }
}
int main() {
  int n;
  cin >> n;
  pattern2(n);
  return 0;
}