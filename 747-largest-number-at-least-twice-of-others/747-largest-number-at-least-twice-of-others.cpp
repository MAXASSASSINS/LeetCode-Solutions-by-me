class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int largest = INT_MIN;
        int index = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] > largest){
                largest = nums[i];
                index = i;
            }
        }
        int secondLargest = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] < largest && nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }
        if(secondLargest * 2 <= largest){
            return index;
        }
        else{
            return -1;
        }
    }
};