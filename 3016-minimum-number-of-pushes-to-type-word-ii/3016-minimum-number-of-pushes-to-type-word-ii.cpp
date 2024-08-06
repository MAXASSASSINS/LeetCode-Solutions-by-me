class Solution {
public:
    static bool cmp(pair<char,int> p1, pair<char,int> p2){
        return p1.second > p2.second;
    }
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for(char c: word){
            m[c]++;
        }
        
        vector<pair<char,int>> vec(m.begin(), m.end());
        
        sort(vec.begin(), vec.end(), cmp);
        
        int ans = 0;
        for(int i = 0; i < vec.size(); i++){
            ans += vec[i].second * ceil(double(i + 1) / 8);
        }
        
        return ans;  
    }
};