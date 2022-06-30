class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(1001, 0);
        int townJudge = -1;
        int countJudge = 0;
        for (int i = 0; i < trust.size(); ++i) {
            arr[trust[i][0]] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if(arr[i]  == 0){
                countJudge++;
                townJudge = i;
            }
        }
        if(countJudge > 1){
            return -1;
        }
        int countTrustOnJudge  = 0;
        for (int i = 0; i < trust.size(); ++i) {
            if (trust[i][1] == townJudge) {
                countTrustOnJudge++;
            }
        }
        if (countTrustOnJudge < n - 1){
            return -1;
        }
        return townJudge;
    }
};