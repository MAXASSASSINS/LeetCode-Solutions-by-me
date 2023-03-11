class Solution {
public:
    int beautySum(string s) {
        // support variables
        int res = 0, chars[123] = {};
        multiset<int> ms, tmpMs;
        // computing the frequencies of all the characters in s
        for (char c: s) chars[c]++;
        // populating ms initially
        for (int i = 'a'; i <= 'z'; i++) if (chars[i]) ms.insert(chars[i]);
        for (int i = 0, currFreq, lmtI = s.size() - 2, ed = s.size() - 1; i < lmtI; i++) {
            // removing the character before i, if any
            if (i) {
                currFreq = --chars[s[i - 1]];
                ms.erase(ms.find(currFreq + 1));
                if (currFreq) ms.insert(currFreq);
            }
            tmpMs = ms;
            for (int j = ed, lmtJ = i + 1; j > lmtJ; j--) {
                // removing the character before i, if any
                if (j != ed) {  
                    currFreq = --chars[s[j + 1]];
                    ms.erase(ms.find(currFreq + 1));
                    if (currFreq) ms.insert(currFreq);
                }
                // increasing res with the difference of extreme frequencies
                res += *rbegin(ms) - *begin(ms);
            }
            // restoring chars and ms
            for (int j = ed - 1, lmtJ = i + 1; j > lmtJ; j--) ++chars[s[j + 1]];
            ms = tmpMs;
        }
        return res;
    }
};