class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            return;
        }
        if(m == 0){
            for (int i = 0; i < nums1.size(); ++i) {
                nums1.at(i) = nums2.at(i);
            }
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int count = m + n - 1;
        while (i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[count] = nums1[i];
                count--;
                i--;
            }
            else{
                nums1[count] = nums2[j];
                count--;
                j--;
            }
        }
        while (j >= 0){
            nums1[count] = nums2[j];
            count--;
            j--;
        }

    }
};