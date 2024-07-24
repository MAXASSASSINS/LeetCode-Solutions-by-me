class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            vector<int> counts(26, 0);
            string temp = "";
            
            for(int j = i; j < n; j++){
                char c = s[j];
                temp += c;
                counts[c - 'a']++;
                
                int maxi = INT_MIN, mini = INT_MAX;
                for(auto x: counts){
                    maxi = max(maxi, x);
                    if(x != 0){
                        mini = min(mini, x);
                    }
                }
                
                if(mini != INT_MIN){
                    ans += maxi - mini;
                }
                
            }
            
        }
        
        return ans;
    }
};