class Solution {
public:
    void solve(vector<int> &candidates, int target, int index, vector<vector<int>> &ans,  vector<int>  &temp){
        if(index == candidates.size()){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        // exclude
        solve(candidates,  target, index + 1, ans, temp);

        // include
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            solve(candidates, target - candidates[index], index, ans, temp);
            temp.pop_back();
        }

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, ans, temp);

        return ans;
    }
};