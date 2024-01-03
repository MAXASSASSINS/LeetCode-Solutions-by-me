class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> temp;
        
        for(auto row: bank){
            int cnt = 0;
            for(auto x: row){
                if(x == '1') cnt++;
            }
            if(cnt != 0) temp.push_back(cnt);
        }
        
        cout<<temp.size();
        int n = temp.size();
        
        int res = 0;
        for(int i = 0; i < n - 1 ; i++){
            res += temp[i] * temp[i + 1];
        }
        
        return res;
        

    }
};