class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        int n = aliceSizes.size();
        int m = bobSizes.size();
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(), bobSizes.end());
        int aliceSum = 0;
        int bobSum = 0;
        for (int i = 0; i < n; ++i) {
            aliceSum += aliceSizes[i];
        }
        for (int i = 0; i < m; ++i) {
            bobSum += bobSizes[i];
        }
        int requiredSum = (aliceSum + bobSum) /2;
        int diffAlice = requiredSum - aliceSum;
        int diffBob = requiredSum - bobSum;
        if(diffAlice < 0){
            int stAlice = 0;
            int stBob = 0;
            while (stAlice < n && stBob < m){
                int diff = aliceSizes[stAlice] - bobSizes[stBob];
                if(diff == abs(diffAlice)){
                    ans.push_back(aliceSizes[stAlice]);
                    ans.push_back(bobSizes[stBob]);
                    break;
                }
                else if(diff < abs(diffAlice)){
                    stAlice++;
                }
                else{
                    stBob++;
                }
            }
        }
        else{
            int stAlice = 0;
            int stBob = 0;
            while (stAlice < n && stBob < m){
                int diff = bobSizes[stBob] - aliceSizes[stAlice];
                if(diff == abs(diffAlice)){
                    ans.push_back(aliceSizes[stAlice]);
                    ans.push_back(bobSizes[stBob]);
                    break;
                }
                else if(diff < abs(diffBob)){
                    stBob++;
                }
                else{
                    stAlice++;
                }
            }
        }
        return ans;

    }
};