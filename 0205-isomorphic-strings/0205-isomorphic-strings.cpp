class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m, m2;
        int n = s.length();
        for(int i = 0; i < n; i++){
            auto it = m.find(s[i]);
            auto it2 = m2.find(t[i]);
            if(it != m.end() && it->second != t[i]){
                return false;
            }
            if(it2 != m2.end() && it2->second != s[i]){
                return false;
            }
            m.insert(make_pair(s[i], t[i]));
            m2.insert(make_pair(t[i], s[i]));
        }

        for(int i = 0; i < n; i++){
            s[i] = m[s[i]];
        }

        return s == t;
        
    }
};