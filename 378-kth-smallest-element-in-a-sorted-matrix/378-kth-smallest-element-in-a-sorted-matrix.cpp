class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> p;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                p.push_back(matrix[i][j]);
            }
        }
        sort(p.begin(), p.end());
        return p[k - 1];
    }
};