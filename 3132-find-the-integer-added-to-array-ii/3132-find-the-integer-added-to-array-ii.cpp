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
                int l = 0;
                for(int i = 0; i < nums1.size(); i++){
                    if(nums1[i] == INT_MAX) continue;
                    s.insert(nums2[l] - nums1[i]);
                    l++;
                }
                cout<<s.size()<<"\t";
                if(s.size() == 1){
                    auto it = s.begin();
                    if(ans > *it){
                        ans = *it;
                    }
                }
                nums1[i] = temp1;
                nums1[j] = temp2;
            }
        }
        return ans;
    }
};