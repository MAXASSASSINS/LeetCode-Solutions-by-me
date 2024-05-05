class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MAX;
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums1.size(); j++){
                if(i == j) continue;
                
                int temp1 = nums1[i];
                int temp2 = nums1[j];
                
                nums1[i] = nums1[j] = INT_MAX;
                
                unordered_set<int> s;
                int x = INT_MIN;
                int l = 0;
                for(int i = 0; i < nums1.size(); i++){
                    if(nums1[i] == INT_MAX) continue;
                    int temp = nums2[l] - nums1[i];
                    if(x == INT_MIN) x = temp;
                    else if(x != temp){
                        x = INT_MIN;
                        break;
                    }
                    l++;
                }
                if(x != INT_MIN && ans > x){
                    ans = x;
                }
                nums1[i] = temp1;
                nums1[j] = temp2;
            }
        }
        return ans;
    }
};