class Solution {
    void helper(vector<int>& candidates, int target, vector<int> &currComb, int currSum, int currIndex, vector<vector<int>>& ans){
        if(currSum>target) return; 
        if(currSum==target){
            ans.push_back(currComb); 
            return;
        }

        for(int i=currIndex; i<candidates.size(); i++){
            if(i != currIndex && candidates[i] == candidates[i - 1]){
                continue;
            }
            currComb.push_back(candidates[i]);
            currSum+=candidates[i];
            helper(candidates, target, currComb, currSum, i + 1, ans);
            currComb.pop_back();
            currSum-=candidates[i];
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, temp, 0, 0, ans);
        return ans;
    }
};