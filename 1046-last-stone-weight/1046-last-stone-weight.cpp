class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1){
            return stones[0];
        }
        sort(stones.begin(), stones.end(), greater<int>());
        while (stones[1] != 0){
            int y = stones[0];
            int x = stones[1];
            stones[0] = y - x;
            stones[1] = 0;
            sort(stones.begin(), stones.end(), greater<int>());
        }



        return stones[0];

    }
};