class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> vec;
        for(int i = 0; i < names.size(); i++){
            vec.push_back({heights[i], names[i]});
        }
        
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        
        vector<string> res;
        for(auto p: vec){
            res.push_back(p.second);
        }
        
        return res;
    }
};