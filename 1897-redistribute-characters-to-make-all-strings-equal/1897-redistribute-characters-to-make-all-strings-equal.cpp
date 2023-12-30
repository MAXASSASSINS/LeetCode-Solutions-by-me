class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> cnt(26, 0);
        for(auto s: words){
            for(auto c: s){
                cnt[c - 'a']++;
            }
        }
        

        for(auto x: cnt){
            if(x % n != 0){
                return false;
            }    
        }
        return true;
    }
};