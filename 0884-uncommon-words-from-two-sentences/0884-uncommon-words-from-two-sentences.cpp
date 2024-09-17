class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> m;
        string t = s1 + " " +  s2;
        string temp;
        for (int i = 0; i < t.length(); ++i) {
            if (t.at(i) == ' '){
                m[temp]++;
                temp.clear();
                continue;
            }
            temp += t.at(i);
        }
        m[temp]++;
        temp.clear();
        for(auto [str, count] : m){
            if(count == 1){
                ans.push_back(str);
            }
        }
        return ans;
    }
};