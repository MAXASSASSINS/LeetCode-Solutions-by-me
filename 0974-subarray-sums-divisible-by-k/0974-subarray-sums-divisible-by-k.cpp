class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int pre_sum=0,count=0;
        for(int i=0;i<nums.size();i++){
            pre_sum+=nums[i];
            int rem = pre_sum % k;
            if(rem == 0) count++;
            if(rem < 0){
                rem += k;
            }
            if(m.find(rem) != m.end()){
                count+=m[rem];
            }
            m[rem]++;
        }
        return count;
    }
};