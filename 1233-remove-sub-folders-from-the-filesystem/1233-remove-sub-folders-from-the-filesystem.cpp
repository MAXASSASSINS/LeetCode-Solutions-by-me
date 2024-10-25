class Solution {
public:
    bool isPrefix(string s, string pre){
        int n = s.length();
        int m = pre.length();
        if(n < m) return false;
        int i = 0;
        while(i < m){
            if(s[i] != pre[i]) return false;
            i++;
        }
        
        if(s[i] != '/') return false;
        
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        int n = folder.size();
        
        string prev = folder[0];
        vector<string> res;
        res.push_back(folder[0]);
        
        for(int i = 1; i < n; i++){
            if(isPrefix(folder[i], prev)){
                continue;
            }  
            else{
                res.push_back(folder[i]);
                prev = folder[i];
            }
        }
        
        return res;        
    }
};