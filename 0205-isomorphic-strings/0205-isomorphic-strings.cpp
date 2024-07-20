class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        int n = s.length();
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(m.find(c) != m.end()){
                if(m[c] != t[i]) return false;
            }
            else{
                m[c] = t[i];
            }
        }
        
        unordered_set<char> st;
        for(auto it = m.begin(); it != m.end(); it++){
            st.insert(it->second);
        }
        
        
        
        return st.size() == m.size();
    }
};