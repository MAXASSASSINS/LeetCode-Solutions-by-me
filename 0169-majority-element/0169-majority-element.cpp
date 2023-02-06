class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count == 0){
                elem = nums[i];
                count++;
            }
            else if(elem == nums[i]){
                count += 1;
            }
            else{
                count -= 1;
            }
        }
        return elem;
    }
};