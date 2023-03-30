class Solution {
public:
    vector<string> dialPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(string digits, string processed, vector<string> &ans){
        if(digits.empty()){
            ans.push_back(processed);
            return;
        }
        int digit = digits.at(0) - '0';
        string s = dialPad[digit];
        for (int i = 0; i < s.length(); ++i) {
            char c = s.at(i);
            helper(digits.substr(1), processed + c, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        helper(digits, "", ans);
        return ans;
    }
};