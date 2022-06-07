class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Taking transpose of a matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if(i == j)
                    continue;
                else{
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        // flipping left to right
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[j][i], matrix[j][n - i - 1]);
            }
        }

    }
};