class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int f = nums1[0];
        int s = nums2[0];
        
        int n = nums1.size();
        int m = nums2.size();
        
        int i = 0, j = 0;
        int ans = -1;
        while(i < n && j < m){
            while(j < m && nums1[i] > nums2[j]){
                j++;
            }
            if(j == m) return -1;
            while(i < n && nums1[i] < nums2[j]){
                i++;
            }
            if(i == n) return -1;
            if(nums1[i] == nums2[j]) return nums1[i];
        }
        
        return -1;
    }
};