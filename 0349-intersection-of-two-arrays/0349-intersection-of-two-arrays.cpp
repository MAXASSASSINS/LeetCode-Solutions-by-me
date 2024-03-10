class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums1.size(); i++){
            auto it = m.find(nums1[i]);
            if(it == m.end()){
                m[nums1[i]]++;
            }
        }
        
        for(int i = 0; i < nums2.size(); i++){
            auto it = m.find(nums2[i]);
            if(it != m.end()){
                m[nums2[i]] = 0;
            }
        }
        
        auto it = m.begin();
        vector<int> ans;
        while(it != m.end()){
            if(it->second == 0){
                ans.push_back(it->first);
            }
            it++;
        }
        
        return ans;
    }
};