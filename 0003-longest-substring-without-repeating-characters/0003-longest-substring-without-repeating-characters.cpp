class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        
        int l = 0;
        int r = 0;
        
        int ans = 0;
        
        while(r < s.length()){
            char c = s[r];
            while(st.find(c) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(c);
            ans = max(ans, r - l + 1);
            r++;
        }
       
        
        return ans;
    }
};