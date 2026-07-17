#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val = min(rowSum[i], colSum[j]);
            matrix[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
        }
    }
    return matrix;
}

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<int> rowSum(m);
    for (int i = 0; i < m; i++) {
        cin >> rowSum[i];
    }
    vector<int> colSum(n);
    for (int i = 0; i < n; i++) {
        cin >> colSum[i];
    }
    vector<vector<int>> result = restoreMatrix(rowSum, colSum);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
