class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = INT_MAX;
        for (int i = 0; i < strs.size(); ++i) {
            index = min(index, (int)strs.at(i).length());
        }
        if(index == 0){
            return "";
        }
        if(strs.size() == 1){
            return strs.at(0);
        }
        string temp;
        bool foundFault = false;
        for (int i = 0; i < index; ++i) {
            char c = strs.at(0).at(i);
            for (int j = 1; j < strs.size(); ++j) {
                if(strs.at(j).at(i) != c){
                    foundFault = true;
                    break;
                }
            }
            if(foundFault){
                break;
            }
            temp.push_back(c);
        }
        return temp;
    }
};