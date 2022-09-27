class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        map<int, int, greater<>> m;
        int i = 0;
        while (i < nums.size()) {
            m[nums[i]]++;
            i++;
        }
        vector<pair<int,int>> vec(m.begin(), m.end());

        sort(vec.begin(), vec.end(), cmp);

        auto it = vec.begin();

        for (int j = 0; j < k; ++j) {
            ans.push_back(it->first);
            it++;
        }
        return ans;
    }
};