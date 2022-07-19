class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        while (i < s.size()) {
            string temp;
            while (i < s.size() && s.at(i) != ' '){
                temp += s.at(i);
                i++;
            }
            words.push_back(temp);
            i++;
        }
        s = "";
        for (int j = 0; j < words.size(); ++j) {
            std::reverse(words.at(j).begin(), words.at(j).end());
            s += words.at(j);
            s += " ";
        }
        s = s.substr(0, s.length() - 1);
        return s;
    }
};