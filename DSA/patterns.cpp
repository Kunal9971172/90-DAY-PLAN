#include <iostream>
using namespace std;

/*
// Q1 Square pattern (commented out)
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "*";
        }
        cout << endl;
    }
}
*/

/*
// Q2 Right‑angle triangle pattern (commented out)
void pattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
*/

/*
// Q3 Inverted right‑angle triangle pattern (stars) - currently not used
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n - i + 1;j++){
            cout << "* ";
        }
        cout << endl;
    }
}
*/

// Q4 Pyramid pattern (stars)
/*void pattern4(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      cout << "  ";
    }
    for (int j = 0; j < 2 * i + 1; j++) { // Mistake: i++ instead of j++
      cout << "* ";
    }
    for (int j = 0; j < n - i + 1; j++) { // Unnecessary trailing spaces
      cout << " ";
    }
    cout << endl;
  }
}
int main() {
  int n;
  cin >> n;
  pattern4(n);
  return 0;
}
*/

/* void pattern5(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << "  ";
    }
    for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
      cout << "* ";
    }
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    cout << endl;
  }
}
int main() {
  int n;
  cin >> n;
  pattern5(n);
  return 0;
} */

void pattern6(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      cout << "  ";
    }
    for (int j = 0; j < 2 * i + 1; j++) {
      cout << "* ";
    }
    for (int j = 0; j < n - i + 1; j++) {
      cout << " ";
    }
    cout << endl;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      cout << "  ";
    }
    for (int j = 0; j < 2 * n - (2 * i + 1); j++) {
      cout << "* ";
    }
    for (int j = 0; j < i; j++) {
      cout << " ";
    }
    cout << endl;
  }
}
int main() {
  int n;
  cout << "Enter value of n: ";
  cin >> n;
  pattern6(n);
  return 0;
}
