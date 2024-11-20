class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(i >= 0 && j >= 0){
            int x = nums1[i];
            int y = nums2[j];
            
            if(x >= y){
                nums1[k] = x;
                i--;
            }
            else{
                nums1[k] = y;
                j--;
            }
            k--;
        }
        
        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};