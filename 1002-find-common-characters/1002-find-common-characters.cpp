class Solution {
public:
    vector<string> commonChars(vector<string> &words) {
        vector<string> ans;
        if (words.size() == 1){
            for (int i = 0; i < words[0].size(); ++i) {
                string temp;
                temp += words[0][i];
                ans.push_back(temp);
            }
            return ans;
        }
        string temp;
        sort(words[0].begin(), words[0].end());
        sort(words[1].begin(), words[1].end());
        set_intersection(words[0].begin(), words[0].end(), words[1].begin(), words[1].end(), back_inserter(temp));
        for (int i = 2; i < words.size(); ++i) {
            sort(words[i].begin(), words[i].end());
            string temp2 = temp;
            temp = "";
            set_intersection(temp2.begin(),temp2.end(), words[i].begin(), words[i].end(), back_inserter(temp));
        }
        for (int i = 0; i < temp.size(); ++i) {
            string temp2;
            temp2 += temp.at(i);
            ans.push_back(temp2);
        }
        return ans;
    }
};