class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int f = INT_MIN, s = INT_MIN;
        int cnt1 = -1;
        int cnt2 = -1;
        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == -1 && nums[i] != s){
                f = nums[i];
                cnt1++;
            }
            else if(cnt2 == -1 && nums[i] != f){
                s = nums[i];
                cnt2++;
            }
            else if(f == nums[i]){
                cnt1++;
            }
            else if(s == nums[i]){
                cnt2++;
            }
            else{
                cnt2--;
                cnt1--;
            }
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(f == nums[i]) cnt1++;
            if(s == nums[i]) cnt2++;
        }
        if(cnt1 > n /3){
            ans.push_back(f);
        }
        if(cnt2 > n / 3){
            ans.push_back(s);
        }
        return ans;
    }
    
    
};