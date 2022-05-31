class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k >= s.length())
            return false;

        bool ans = false;
        set<string> setOfString;
        for (int i = 0; i < s.length(); ++i) {
            if(i + k <= s.length()){
                string temp = s.substr(i, k);
                if(temp.length() == k)
                    setOfString.insert(temp);
            }
        }
        if(int(setOfString.size()) == int(pow(2, k)))
            ans = true;
        return ans;
    }
};