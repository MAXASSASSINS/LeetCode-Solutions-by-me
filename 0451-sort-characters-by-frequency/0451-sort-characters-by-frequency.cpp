class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> hash(128, {0,0});
        
        for(char c: s){
            hash[c] = {hash[c].first + 1, c};
        }
        
        sort(hash.begin(), hash.end());
        string res;
        for(int i = 0; i < 128; i++){
            res = string(hash[i].first, hash[i].second) + res;
        }
        
        return res;
        
    }
};