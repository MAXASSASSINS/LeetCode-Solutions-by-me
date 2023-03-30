class Solution {
public:
    void solve(vector<int> &arr, int n, vector<int> &temp, int index, set<vector<int>> &ans){
        if(index >= n){
            ans.insert(temp);
            return;    
        }
        // exclude
        solve(arr, n, temp, index + 1, ans);

        // include
        temp.push_back(arr[index]);
        solve(arr, n, temp, index + 1, ans);
        temp.pop_back();

        
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> temp;
        solve(nums, nums.size(), temp, 0, ans);
        vector<vector<int>> result;
        for(auto it: ans){
            result.push_back(it);
        }
        return result;
        
    }
};