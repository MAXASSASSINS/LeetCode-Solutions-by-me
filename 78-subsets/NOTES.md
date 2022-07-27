Recursion
```
class Solution {
public:
void helper(const vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int index) {
ans.push_back(temp);
if(index == nums.size()){
return;
}
temp.push_back(nums[index]);
helper(nums, ans, temp, index + 1);
}
​
vector<vector<int>> subsets(vector<int>& nums) {
vector<vector<int>> ans;
vector<int> temp;
int index = 0;
helper(nums, ans, temp, index);
return ans;
}
};
```