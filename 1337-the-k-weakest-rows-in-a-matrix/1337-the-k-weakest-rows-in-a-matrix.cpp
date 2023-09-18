class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        int p = mat.size();
        int r = mat[0].size();
        for(int i = 0; i < p; i++){
            int j = 0;
            while(j < r && mat[i][j]){
                j++;
            }
            v.push_back({j + 1, i});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> ans;
        int i = 0;
        while(i < v.size() && k > 0){
            ans.push_back(v[i].second);
            i++;
            k--;
        }
        
        return ans;
    }
};