class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++){
            res.push_back(to_string(i));
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for(auto s: res){
            ans.push_back(stoi(s));
        }
        return ans;
    }
};