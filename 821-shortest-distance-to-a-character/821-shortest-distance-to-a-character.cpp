class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> occurences;
        vector<int> ans;
        for (int i = 0; i < s.length(); ++i) {
            if(s.at(i) == c){
                occurences.push_back(i);
            }
        }

        int index = 0;
        for (int i = 0; i < s.length(); ++i) {
            if(i > occurences[index] && index  != occurences.size() - 1){
                index++;
            }
            int dis = 0;
            if(index > 0){
                dis = min(abs(i - occurences[index]), abs(i - occurences[index - 1]));
            }
            else{
                dis = abs(i - occurences[index]);
            }
            ans.push_back(dis);
        }
        return ans;
    }
};