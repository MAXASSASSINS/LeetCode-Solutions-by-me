class Solution {
public:
    string convertToString(int val, int len){
        string res(len, '0');
        int i = 0;
        while(val != 0){
            res[i] = (val % 2) + '0';
            val /= 2;
            i++;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    int convertToInt(string s){
        int len = s.length();
        int val = 0;
        for(int i = len - 1; i >= 0; i--){
            val += int(s[i] - '0') * pow(2, len - 1 - i);
        }
        cout<<val<<endl;
        return val;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> ints;
        
        for(int i = 0; i < n; i++){
            int val = convertToInt(nums[i]);
            ints.push_back(val);
        }
        
        sort(ints.begin(), ints.end());
        
        int ans = -1;
        for(int i = 0; i < n - 1; i++){
            if(ints[i + 1] - ints[i] != 1){
                ans = ints[i] + 1;
                break;
            }
        }
        if(ans == -1){
            if(ints[0] == 0){
                return convertToString(ints[n - 1] + 1, n);                
            }
            else{
                string s(n, '0');
                return s;
            }
        }
        string res = convertToString(ans, n);
        
        return res;
        
    }
};