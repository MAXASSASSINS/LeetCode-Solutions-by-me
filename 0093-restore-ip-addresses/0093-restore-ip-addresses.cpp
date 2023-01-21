class Solution {
public:
    bool check(const string &s){
        int st = 0;
        int en = 0;
        vector<string> temp;
        int len = s.length();
        while(en < len){
            while(en < len && s[en] != '.'){
                en++;
            }
            string t = s.substr(st, en - st);
            en++;
            st = en;
            
            // checking string
            if(t[0] == '0' && t.length() > 1) return false;
            if(t.length() > 3 || t.length() == 0) return false;
            if(stoi(t) > 255) return false;
        }
        
        return true;
    }
    void solve(string s, vector<string> &ans, int index, int count){
        if(count == 3){
            if(check(s)) ans.push_back(s);
            return;
        }
        if(index >= s.length()){
            return;
        }

        // don't put dot        
        solve(s, ans, index + 1, count);

        
        // put dot
        s.insert(index, 1, '.');
        solve(s, ans, index + 2, count + 1);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length() < 4 && s.length() > 12) return ans;
        solve(s, ans, 0, 0);
        return ans;
    }
};