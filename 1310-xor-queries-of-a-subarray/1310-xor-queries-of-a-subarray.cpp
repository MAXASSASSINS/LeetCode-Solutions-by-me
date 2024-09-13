class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto query: queries){
            int st = query[0];
            int en = query[1];
            int res = 0;
            for(int i = st; i <= en; i++){
                res ^= arr[i];
            }
            ans.push_back(res);
        }
        
        return ans;
    }
};