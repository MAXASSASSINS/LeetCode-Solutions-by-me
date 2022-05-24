class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() == 0 && nums2.size() == 0){
            return 0;
        }
        vector<int> ans(nums2.size() + nums1.size());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1.at(i) <= nums2.at(j)){
                ans.at(i + j) = nums1.at(i);
                i++;
            }
            else{
                ans.at(i + j) = nums2.at(j);
                j++;
            }
        }
        while(i < nums1.size()){
            ans.at(i + j) = nums1.at(i);
            i++;
        }
        while (j < nums2.size()){
            ans.at(i + j) = nums2.at(j);
            j++;
        }
//        for (auto num : ans ) {
//            cout<<num << " ";
//        }
        double median = 0;
        if (ans.size() % 2 == 0)
            median = double (ans[ans.size() / 2] + ans[(ans.size() - 1) / 2]) / 2;
        else
            median = double (ans[ans.size() / 2]);
        cout<<"\n" << median <<"\n";
        return  median;
    }
};
