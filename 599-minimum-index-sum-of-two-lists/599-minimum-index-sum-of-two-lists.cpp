class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int leastIndexSum = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < list1.size(); ++i) {
            for (int j = 0; j < list2.size(); ++j) {
                if(list1.at(i) == list2.at(j)){
                    int sum = i + j;
                    if(sum == leastIndexSum){
                        ans.push_back(list1.at(i));
                    }
                    else if(sum < leastIndexSum){
                        leastIndexSum = sum;
                        ans = {list1.at(i)};
                    }
                }
            }
        }
        return ans;
    }
};