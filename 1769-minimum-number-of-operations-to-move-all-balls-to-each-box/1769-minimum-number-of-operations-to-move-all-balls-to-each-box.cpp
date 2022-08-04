class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> allOneIndices;
        vector<int> ans(boxes.size());
        for (int i = 0; i < boxes.length(); ++i) {
            if(boxes.at(i) == '1'){
                allOneIndices.push_back(i);
            }
        }
        for (int i = 0; i < boxes.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < allOneIndices.size(); ++j) {
                sum += abs(i - allOneIndices[j]);
            }
            ans.at(i) = sum;
        }
        return ans;
    }
};