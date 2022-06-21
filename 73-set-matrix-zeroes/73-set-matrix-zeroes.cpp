class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        int n = matrix.size();
        int m = matrix.at(0).size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(matrix.at(i).at(j) == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto i = rows.begin(); i != rows.end(); ++i) {
            for (int j = 0; j < m; ++j) {
                matrix[*i][j] = 0;
            }
        }
        for (auto i = cols.begin(); i != cols.end(); ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[j][*i] = 0;
            }
        }
        
    }
};