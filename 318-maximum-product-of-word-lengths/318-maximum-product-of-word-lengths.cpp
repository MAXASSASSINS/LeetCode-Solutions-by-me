class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                long int l = 0;
                for (int k = 0; k < words.at(i).length(); ++k) {
                    char c = words.at(i).at(k);
                    int bitsToShift = c - 97;
                    int x = 1 << bitsToShift;
                    if((x & l) == 0) {
                        l = l | x;
                    }
                }

                bool foundCommonLetter = false;
                for (int k = 0; k < words.at(j).length(); ++k) {
                    int n = words.at(j).at(k) - 97;
                    int x = 1 << n;
                    if ((x & l) > 0) {
                        foundCommonLetter = true;
                        break;
                    }
                }
                if (!foundCommonLetter) {
                    int length = words.at(i).length() * words.at(j).length();
                    ans = max(ans, length);
                }
            }
        }
        return ans;
    }

};