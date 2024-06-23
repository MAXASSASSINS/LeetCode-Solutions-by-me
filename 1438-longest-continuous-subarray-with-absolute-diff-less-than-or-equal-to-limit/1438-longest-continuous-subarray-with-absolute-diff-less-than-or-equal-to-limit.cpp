class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int longestLen = 0;
        int i = 0, j = 0;
        map<int, int> asc;
        map<int, int, greater<int>> desc;
        while(j < nums.size()){
            asc[nums[j]]++;
            desc[nums[j]]++;
            
            auto it1 = asc.begin();
            auto it2 = desc.begin();              
            
            while(abs(it1->first - it2->first) > limit){
                cout<<abs(it1->first - it2->first)<<endl;
                asc[nums[i]]--;
                desc[nums[i]]--;
                if(asc[nums[i]] <= 0){
                    asc.erase(nums[i]);                    
                }
                if(desc[nums[i]] <= 0)
                    desc.erase(nums[i]);
                i++;
                it1 = asc.begin();
                it2 = desc.begin();
            }
            j++;
            
            longestLen = max(longestLen, j - i);
        }
        return longestLen;
    }
};