class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        
        int l = 0;
        int h = 0;
        int ans = 0;
        while(h < s.length()){
            char c = s[h];
            if(m.find(c) != m.end()){
                l = max(l, m[c] + 1);
            }
            m[c] = h;
            ans = max(ans, h - l + 1);
            h++;
            
        }
        
        return ans;
    }
};