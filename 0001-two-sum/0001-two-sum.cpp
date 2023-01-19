class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int low = 0, high = temp.size() - 1;
        int index1 = -1;
        int index2 = -1;
        while (low < high){
            if(temp[high] + temp[low] > target){
                high--;
            }
            if(temp[low] + temp[high] < target){
                low++;
            }
            if (temp[high] + temp[low] == target) {
                high = temp[high];
                low = temp[low];
                break;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == low){
                index1 = i;
                break;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == high){
                index2 = i;
                if(index1 == index2)
                    continue;
                else
                    break;
            }
        }
        vector<int>  ans = {index1, index2};
        return ans;
    }
};