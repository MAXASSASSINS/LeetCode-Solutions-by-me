class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rs = 0, cs = 0, re = n - 1, ce = n - 1;
        int count = 1;
        vector<vector<int>> m(n, vector<int>(n, 0));
        while(count <= n * n){
            for(int i = cs; i <= ce; i++){
                m[rs][i] = count;
                count++;
            }
            rs++;
            for(int i = rs; i <= re; i++){
                m[i][ce] = count;
                count++;
            }
            ce--;
            for(int i = ce; i >= cs; i--){
                m[re][i] = count;
                count++;
            }
            re--;
            for(int i = re; i >= rs; i--){
                m[i][cs] = count;
                count++;
            }
            cs++;
        }
        return m;
        
    }
};