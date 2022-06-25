class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alphabets = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
                                    "-..-", "-.--", "--.."};
        set<string> s;
        for (int i = 0; i < words.size(); ++i) {
            string temp;
            for (int j = 0; j < words.at(i).length(); ++j) {
                temp += alphabets.at(words.at(i).at(j) - 'a');
            }
            s.insert(temp);
        }
        return s.size();
    }
};