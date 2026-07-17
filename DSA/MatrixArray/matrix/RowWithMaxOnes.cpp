#include <iostream>
#include <vector>

using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int maxRow = 0;
    int maxOnes = 0;
    for (int i = 0; i < mat.size(); i++) {
        int currentOnes = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                currentOnes++;
            }
        }
        if (currentOnes > maxOnes) {
            maxOnes = currentOnes;
            maxRow = i;
        }
    }
    return {maxRow, maxOnes};
}

int main() {
    int rows, cols;
    if (!(cin >> rows >> cols)) return 0;
    vector<vector<int>> mat(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
    vector<int> result = rowAndMaximumOnes(mat);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
