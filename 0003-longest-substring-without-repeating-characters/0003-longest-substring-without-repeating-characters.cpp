class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        
        int ans = 0;
        int i = 0;
        for(int j = 0; j < s.length(); j++){
            auto it = set.find(s[j]);
            
            if(it != set.end()){
                while(s[i] != s[j]){
                    set.erase(s[i]);
                    i++;
                }
                set.erase(s[i]);
                i++;
            }
            set.insert(s[j]);
            ans = max(ans, (int)set.size());
        }
        
        return ans;
        
    }
};