class Solution {
public:
    void sortColors(vector<int> &nums) {
        vector<int> arr(3);
        for (int i = 0; i < nums.size(); ++i) {
            ++arr[nums[i]];
        }
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (arr[temp] == 0 && temp < 3) {
                temp++;
            }
            nums[i] = temp;
            --arr[temp];
        }
    }
};