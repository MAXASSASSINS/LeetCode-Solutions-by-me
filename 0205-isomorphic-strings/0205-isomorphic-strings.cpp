class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        for(int i = 0; i < s.length(); i++){
            auto it = m.find(s[i]);
            
            if(it == m.end()){
                m[s[i]] = t[i];
            }
            else{
                if(m[s[i]] != t[i]) return false;
            }
        }
        
        
        unordered_map<char, char> reverseM;
        auto it = m.begin();
        
        while(it != m.end()){
            auto it2 = reverseM.find(it->second);
            
            if(it2 == reverseM.end()){
                reverseM[it->second] = it->first;
            }
            else{
                if(reverseM[it->second] != it->first) return false;
            }
            it++;
        }
        
        return true;
    }
};