class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> ans;
        set<pair<int,int>> s;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            int mini = 0;
            for(int j = 1; j < n; j++){
                if(mat[i][j] < mat[i][mini]){
                    mini = j;
                }
            }
            s.insert({i, mini});
        }
        
        for(int i = 0; i < n; i++){
            int maxi = 0;
            for(int j = 1; j < m; j++){
                if(mat[j][i] > mat[maxi][i]){
                    maxi = j;
                }
            }
            if(s.find({maxi, i}) != s.end()){
                ans.push_back(mat[maxi][i]);
            }
        }
        
        return ans;
    }
};