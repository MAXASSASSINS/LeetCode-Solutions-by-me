class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        if(nums.size() == 1){
            return 1;
        }
        vector<int> temp = nums;
        vector<int> maxCountElements;
        sort(temp.begin(), temp.end());
        int count = 1;
        int maxCount = -1;
        for (int i = 1; i < temp.size(); ++i) {
            if (temp[i - 1] == temp[i]) {
                count++;
            } else {
                if(count > maxCount){
                    maxCountElements.clear();
                    maxCountElements.push_back(temp[i - 1]);
                    maxCount = count;
                }
                else if(count == maxCount){
                    maxCountElements.push_back(temp[i - 1]);
                }
                count = 1;
            }
        }
        if(count > maxCount){
            maxCountElements.clear();
            maxCountElements.push_back(temp[temp.size() - 1]);
            maxCount = count;
        }
        else if(count == maxCount){
            maxCountElements.push_back(temp[temp.size() - 1]);
        }


        int st = 0;
        int en = nums.size() - 1;
        int i = 0;
        int minSize = INT_MAX;
        while (i < maxCountElements.size()){
            for (int j = 0; j < nums.size(); ++j) {
                if(nums[j] == maxCountElements.at(i)){
                    st = j;
                    break;
                }
            }
            for (int j = nums.size() - 1; j >= 0; --j) {
                if(nums[j] == maxCountElements.at(i)){
                    en = j;
                    break;
                }
            }
            i++;
            minSize = min(minSize, en - st + 1);

        }
        return minSize;
    }
};