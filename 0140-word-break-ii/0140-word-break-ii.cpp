class Solution {
public:
    void solve(const string &s, map<string, bool> &m, int index, string &temp, vector<string> &ans){
        if(index >= s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = index; i < s.length(); i++){
            string sub = s.substr(index, i - index + 1);
            if(m.find(sub) != m.end()){
                string temp2 = temp;
                if(temp.length() > 0) temp = temp + " " + sub;
                else temp = sub;
                solve(s, m, i + 1, temp, ans);
                temp = temp2;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp;
        map<string, bool> m;
        for(auto str: wordDict){
            m[str] = true;
        }
        
        solve(s, m, 0, temp, ans);
        return ans;            
    }
};