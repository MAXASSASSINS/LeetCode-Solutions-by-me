class Solution {
public:
    
    int solve(string &s, unordered_set<string> &st, int index, unordered_map<int,int> &m){
        if(index >= s.length()){
            return 0;
        }
        
        if(m.find(index) != m.end()){
            return m[index];
        }
        
        int found = 1e9, notFound = 1e9;
        
        int ans = INT_MAX;
        
        for(int i = index; i < s.length(); i++){
            string str = s.substr(index, i - index + 1);
            if(st.find(str) != st.end()){
                ans = min(ans,solve(s, st, i + 1, m));
            }
        }
        
        ans = min(ans, 1 + solve(s, st, index + 1, m));
        
        return m[index] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<int, int> m;
        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        return solve(s, st, 0, m);
        // return m[0];

    }
};