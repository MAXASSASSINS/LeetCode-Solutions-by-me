class Solution {
public:
    int getLucky(string s, int k) {
        string res;
        for(auto c: s){
            int val = c - 'a' + 1;
            res += to_string(val);
        }
        
        for(int i = 0; i < k; i++){
            int val = 0;
            for(auto c: res){
                val += c - '0';
            }
            res = to_string(val);
        }
        
        return stoi(res);
    }
};