class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int st = 1;
        while(ans.size() < n){
            while(st * 10 <= n){
                ans.push_back(st);
                st *= 10;
            }
            if(st <= n)
                ans.push_back(st);
            int i = st + 1;
            while(i % 10 != 0 && i <= n){
                ans.push_back(i);
                i++;
            }
            int en = i; 
            while(en % 10 == 0){
                en /= 10;
            }
            st = en;
        }
        return ans;
    }
};