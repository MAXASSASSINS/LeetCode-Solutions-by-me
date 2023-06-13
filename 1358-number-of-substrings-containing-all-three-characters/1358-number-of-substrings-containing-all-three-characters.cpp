class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0; 
        int j = 0;
        int ans = 0;
        
        vector<int> vec(3, 0);
        for(j = 0; j < s.length(); j++){
            vec[s[j] - 'a']++;
            while(vec[0] > 0 && vec[1] > 0 && vec[2] > 0 && i <= j){
                vec[s[i] - 'a']--;
                ans += s.length() - j;
                i++;
            }
        }
        
        return ans;
    }
};