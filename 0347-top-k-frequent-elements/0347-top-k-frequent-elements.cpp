class Solution {
public:
    static bool func(pair<int,int> p1, pair<int,int> p2){
        return p1.second > p2.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        
        vector<pair<int,int>> vec(m.begin(), m.end());
        
        sort(vec.begin(), vec.end(), func);
        
        vector<int> ans;
        
        for(int i = 0; i < k; i++){
            auto p = vec[i];
            ans.push_back(p.first);
        }
        
        return ans;   
    }
};