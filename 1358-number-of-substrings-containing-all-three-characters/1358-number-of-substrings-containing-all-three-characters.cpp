class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        int j = 0;
        unordered_map<int,int> m;
        for(int i = 0; i < n; i++){
            m[s[i]]++;
            while(m.size() == 3){
                count += n - i;
                m[s[j]]--;
                if(m[s[j]] == 0){
                    m.erase(s[j]);
                }
                j++;
            }
        }
        
        return count;
    }
};