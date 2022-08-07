class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
        vector<bool> ans;
        for (int i = 0; i < r.size(); ++i) {
            vector<int> temp;
            std::copy(nums.begin() + l.at(i), nums.begin() + r.at(i) + 1, back_inserter(temp));
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            bool arithmetic = true;
            for (int j = 2; j < temp.size(); ++j) {
                if (temp[j] - temp[j - 1] != diff) {
                    arithmetic = false;
                    break;
                }
            }
            ans.push_back(arithmetic);
        }
        return ans;
    }
};