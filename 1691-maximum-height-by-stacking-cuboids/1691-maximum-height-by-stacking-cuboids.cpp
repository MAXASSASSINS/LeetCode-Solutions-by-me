class Solution {
public:

    bool check(vector<int> &a, vector<int> &b){
        if(a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]){
            return true;
        }
        else{
            return false;
        }
    }

    int solveSO(vector<vector<int>>& nums){
        int n = nums.size();

        vector<int> currentRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);


        for (int curr = n - 1; curr >= 0; --curr) {
            for (int prev = curr - 1; prev >= -1 ; --prev) {
                int include = 0;
                if(prev == -1 || check(nums[curr],nums[prev])){
                    include = nums[curr][2] + nextRow[curr + 1];
                }

                int exclude = 0 + nextRow[prev + 1];
                currentRow[prev + 1] = max(include, exclude);
            }
            nextRow = currentRow;
        }

        return currentRow[0];
    }


    int maxHeight(vector<vector<int>>& cuboids) {
        for (int i = 0; i < cuboids.size(); ++i) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        sort(cuboids.begin(), cuboids.end());

        return solveSO(cuboids);
    }
};