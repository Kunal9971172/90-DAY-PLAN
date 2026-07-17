#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty() || matrix[0].empty()) return ans;
    int rowStart = 0;
    int rowEnd = matrix.size() - 1;
    int colStart = 0;
    int colEnd = matrix[0].size() - 1;
    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int j = colStart; j <= colEnd; j++) {
            ans.push_back(matrix[rowStart][j]);
        }
        rowStart++;
        for (int i = rowStart; i <= rowEnd; i++) {
            ans.push_back(matrix[i][colEnd]);
        }
        colEnd--;
        if (rowStart <= rowEnd) {
            for (int j = colEnd; j >= colStart; j--) {
                ans.push_back(matrix[rowEnd][j]);
            }
            rowEnd--;
        }
        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                ans.push_back(matrix[i][colStart]);
            }
            colStart++;
        }
    }
    return ans;
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
    vector<int> result = spiralOrder(matrix);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
