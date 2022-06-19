class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals.at(0));
        int index = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] >= ans[index][0] && intervals[i][0] <= ans[index][1]){
                if(intervals[i][1] > ans[index][1]){
                    ans[index][1] = intervals[i][1];
                }
            }
            else{
                ans.push_back(intervals.at(i));
                index++;
            }
        }

        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        intervals.push_back(newInterval);
        intervals = merge(intervals);
        return intervals;
    }
};