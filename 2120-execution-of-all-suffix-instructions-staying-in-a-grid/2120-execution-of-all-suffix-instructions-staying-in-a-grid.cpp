class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int i = 0;
        while (i < s.length()) {
            int row = startPos[0];
            int col = startPos[1];
            int count = 0;
            int j = i;
            while (j < s.length() && row < n && col < n && row >= 0 && col >= 0) {
                if(s.at(j) == 'U')
                    row--;
                if(s.at(j) == 'D')
                    row++;
                if(s.at(j) == 'L')
                    col--;
                if(s.at(j) == 'R')
                    col++;
                count++;
                if(row == n || row < 0 || col == n || col < 0){
                    count--;
                    break;
                }
                j++;
            }
            ans.push_back(count);
            i++;
        }
        return ans;
    }
};