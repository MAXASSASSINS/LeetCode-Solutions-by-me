class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1(1001), v2(1001);
        for(auto x: nums1){
            v1[x]++;
        }
        for(auto x: nums2){
            v2[x]++;
        }
        
        for(int i = 0; i < 1001; i++){
            v1[i] = min(v1[i], v2[i]);
        }
        
        vector<int> res;
        for(int i = 0; i < 1001; i++){
            for(int j = 0; j < v1[i]; j++){
                res.push_back(i);
            }
        }
        
        return res;
        
        
    }
};