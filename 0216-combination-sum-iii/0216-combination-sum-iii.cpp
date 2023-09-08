class Solution {
public:
    void solve(int k, int n, int num,  vector<vector<int>> &ans, vector<int> &temp){
        if(n < 0) return;
        if(num > 9){
            if(temp.size() == k && n == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        // not take current number
        solve(k , n, num + 1, ans, temp);
        
        // take current number
        temp.push_back(num);
        solve(k , n - num, num + 1, ans, temp);
        temp.pop_back();
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k, n, 1, ans, temp);
        return ans;
    }
};