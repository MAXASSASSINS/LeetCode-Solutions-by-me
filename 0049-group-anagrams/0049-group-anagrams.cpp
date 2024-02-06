class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); i++){
            string str = strs[i];
            string temp = str;
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }
        
        vector<vector<string>> ans;
        auto it = m.begin();
        while(it != m.end()){
            ans.push_back(it->second);
            it++;
        }
        
        return ans;
        
    }
};