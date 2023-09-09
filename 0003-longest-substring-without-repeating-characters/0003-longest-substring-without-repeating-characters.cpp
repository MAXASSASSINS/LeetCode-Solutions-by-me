class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int ans = 0;
        
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(st.find(s[i]) != st.end()){
                while(s[j] != s[i]){
                    st.erase(s[j]);
                    j++;
                }
                j++;
            }
            else{
                st.insert(s[i]);                
            }
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};