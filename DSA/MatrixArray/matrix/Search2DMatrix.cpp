#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m * n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int r = mid / n;
        int c = mid % n;
        if (matrix[r][c] == target) {
            return true;
        } else if (matrix[r][c] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int rows, cols;
    if (!(cin >> rows >> cols)) return 0;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    int target;
    cin >> target;
    if (searchMatrix(matrix, target)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
