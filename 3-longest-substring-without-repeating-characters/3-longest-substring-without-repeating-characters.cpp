class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans  = INT_MIN;
        vector<int> temp(128, 0);
        string substring = "";
        for (int i = 0; i < s.length(); ++i) {
            int index = s.at(i);
            if (temp[index] == 0){
                temp[index] = 1;
                substring += s.at(i);
            }
            else{
                ans = max(ans, int(substring.length()));
                int indexToRemove = int(substring.find(s.at(i)));
                substring = substring.substr(indexToRemove + 1, substring.length() - 1 - indexToRemove);
                substring += s.at(i);
            }
        }
        ans = max(ans, (int)substring.length());
        return ans;
    }
};