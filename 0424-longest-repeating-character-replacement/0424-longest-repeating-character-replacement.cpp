class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> m;
        int maxFreq = 0;
        int ans = 0;
        
        int st = 0;
        for(int en = 0; en < n; en++){
            m[s[en]]++;
            maxFreq = max(maxFreq, m[s[en]]);
            
            while((en - st + 1) - maxFreq > k){
                m[s[st]]--;
                st++;
            }
            
            ans = max(ans, en - st + 1);
        }
        
        return ans;
    }
};