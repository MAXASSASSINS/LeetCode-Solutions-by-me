class Solution {
public:
    void solve(vector<int> &nums, set<vector<int>> &s, int index, vector<int> &temp){
        if(temp.size() > 1)
            s.insert(temp);
        if(index == nums.size()) return;
        
       
        
        // exclude
        solve(nums, s, index + 1, temp);
        
        // include
        if(temp.size() == 0){
            temp.push_back(nums[index]);
            solve(nums, s, index + 1, temp);
            temp.pop_back();   
        }
        else if(nums[index] >= temp[temp.size() - 1]){
            temp.push_back(nums[index]);
            solve(nums, s, index + 1, temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        solve(nums, s, 0, temp);
        
        vector<vector<int>> ans;
        for(auto vec: s){
            ans.push_back(vec);
        }
        return ans;
    }
};