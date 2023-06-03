class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        
        for(auto num: nums1){
            bool found = false;
            int ng = -1;
            for(auto x: nums2){
                if(found && x > num) {
                    ng = x;
                    break;
                }
                if(x == num) found = true;
            }
            ans.push_back(ng);   
        }
        
        return ans;
    }
};