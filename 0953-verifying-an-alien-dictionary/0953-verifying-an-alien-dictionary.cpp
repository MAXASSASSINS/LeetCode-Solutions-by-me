class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() <= 1){
            return true;
        }
        int first = 0;
        int second = 1;
        while(second < words.size()) {
            if (words[first] == words[second]){
                first++;
                second++;
                continue;
            }
            int c1,c2;
            int j = 0;
            bool lexicographicallySmaller = false;
            while(j < min(words[first].size(), words[second].size())) {
                if(words[first][j] == words[second][j]){
                    j++;
                    continue;
                }
                auto it = find(order.begin(), order.end(), words.at(first).at(j));
                c1 = distance(order.begin(), it);
                it = find(order.begin(), order.end(), words.at(second).at(j));
                c2 = distance(order.begin(), it);
                if(c1 < c2){
                    lexicographicallySmaller = true;
                    break;
                }
                if(c1 > c2){
                    return false;
                }
                j++;
            }
            if(j != words[first].size() && !lexicographicallySmaller){
                return false;
            }
            lexicographicallySmaller = false;
            first++;
            second++;
        }
        return true;
    }
};