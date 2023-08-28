class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> m;
        
        int maxi = 0;
        
        int ans = 0;
        
        int i = 0;
        for(int j = 0; j < s.length(); j++){
            m[s[j]]++;
            
            maxi = max(maxi, m[s[j]]);
            
            while(j - i + 1 - maxi > k){
                m[s[i]]--;
                i++;
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};