typedef pair<int,int> pa;
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x: nums){
            m[x]++;
        }
        
        priority_queue<pa, vector<pa>, greater<pa>> pq;
        
        for(auto it = m.begin(); it != m.end(); it++){
            pq.push({it->second, it->first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
         
    }
};