class Solution {
public:
    
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first == p2.first) return p1.second > p2.second;    
        return p1.first < p2.first;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto it = m.begin(); it != m.end(); it++){
            vec.push_back({it->second,it->first});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> ans;
        
        for(auto it = vec.begin(); it != vec.end(); it++){
            for(int i = 0; i < it->first; i++){
                ans.push_back(it->second);
            }
        }
        
        return ans;
        
    }
};