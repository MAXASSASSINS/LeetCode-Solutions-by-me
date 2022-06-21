class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int countUniqueCandies = 0;
        int size = candyType.size();
        sort(candyType.begin(), candyType.end());
        for (int i = 1; i < size; ++i) {
            if(candyType[i] != candyType[i - 1]){
                countUniqueCandies++;
            }
        }
        countUniqueCandies++;
        int ans = min(countUniqueCandies, size/2);
        return ans;
    }
};