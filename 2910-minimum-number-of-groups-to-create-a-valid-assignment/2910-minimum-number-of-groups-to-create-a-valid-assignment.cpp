class Solution {
public:
    int check(vector<int> &counts, int g1, int g) {
    int groups = 0;
    for (int cnt : counts) {
        bool found = false;
        for (int p = cnt / g1; p >= 0 && !found; --p)
            if ((cnt - p * g1) % g == 0) {
                groups += p + (cnt - p * g1) / g;
                found = true;
            }
        if (!found)
            return INT_MAX;
    }
    return groups;
}
int minGroupsForValidAssignment(vector<int>& nums) {
    unordered_map<int, int> counter;
    for (auto n : nums)
        ++counter[n];
    vector<int> counts;
    for (auto [_, cnt] : counter)
        counts.push_back(cnt);
    sort(begin(counts), end(counts));
    for (int div = 1; counts[0] / div > 1; ++div) {
        int g = counts[0] / div;
        int res = min(check(counts, g + 1, g), check(counts, g, g - 1));
        if (res != INT_MAX)
            return res;
    }
    return check(counts, 2, 1);
}
};