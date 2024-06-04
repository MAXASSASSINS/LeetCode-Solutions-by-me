class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(auto c: s){
            m[c]++;
        }
        
        int len = 0;
        bool isOdd = false;
        for(auto it = m.begin(); it != m.end(); it++){
            int x = it->second;
            if(x % 2 == 1){
                len += x - 1;
                isOdd = true;
            }
            else{
                len += x;
            }
        }
        
        
        if(isOdd) len +=1;
        return len;
    }
};