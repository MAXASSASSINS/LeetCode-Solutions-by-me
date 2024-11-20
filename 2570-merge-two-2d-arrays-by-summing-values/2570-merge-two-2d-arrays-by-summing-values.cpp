class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> res;
        
        while(i < n && j < m){
            int id1 =  nums1[i][0];
            int id2 = nums2[j][0];
            
            int x1 = nums1[i][1];
            int x2 = nums2[j][1];
            
            if(id1 == id2){
                res.push_back({id1, x1 + x2});
                i++;
                j++;
            } 
            else if(id1 < id2){
                res.push_back({id1, x1});
                i++;
            }
            else{
                res.push_back({id2, x2});
                j++;
            }
        }
        
        while(i < n){
            res.push_back(nums1[i]);
            i++;
        }
        while(j < m){
            res.push_back(nums2[j]);
            j++;
        }
        
        return res;
    }
};