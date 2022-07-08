class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (int i = 0; i < columnTitle.length(); ++i) {
            int n = columnTitle[i] - 'A' + 1;
            ans *= 26;
            ans += n;
        }
        return ans;
    }
};