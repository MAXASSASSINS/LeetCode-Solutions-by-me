class Solution {
public:
    int solve(vector<int> &nums, int i, int j){
        if(i > j) return 0;
        
        int left = nums[i] + min(solve(nums, i + 2, j), solve(nums, i + 1, j - 1));
        int right = nums[j] + min(solve(nums, i, j - 2), solve(nums, i + 1, j - 1));
        
        return max(left, right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int p1 = solve(nums, 0, n - 1);
        
        int total = 0;
        for(auto x: nums) total += x;
        
        int p2 = total - p1;
        
        return p1 >= p2;
        
    }
};