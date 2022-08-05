class Solution {
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int count = 0;
            int h = queries.at(i).at(0);
            int k = queries.at(i).at(1);
            int r = queries.at(i).at(2);
            for (int j = 0; j < points.size(); ++j) {
                int x = points.at(j).at(0);
                int y = points.at(j).at(1);
                if(pow(x - h, 2) + pow(y - k, 2) <= pow(r,2)){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};