class Solution {
public:
    vector<string> dialPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string digits, vector<string> &ans, int digit, queue<string> q){
        string temp = dialPad.at(digit);
        for (int i = 0; i < temp.size(); ++i) {
            if(q.empty()){
                string s;
                s += temp.at(i);
               ans.push_back(s);
            }
            else{
                for (int j = 0; j < q.size(); ++j) {
                    string s = q.front();
                    string s2 = s +  temp.at(i);
                    ans.push_back(s2);
                    q.pop();
                    q.push(s);
                }
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int i = 0;
        while(i < digits.length()){
            queue<string> q;
            int digit = digits.at(i) - '0';
            for (int j = 0; j < ans.size(); ++j) {
                q.push(ans.at(j));
            }
            ans.clear();
            helper("", ans, digit, q);
            i++;
        }
        return ans;
    }
};