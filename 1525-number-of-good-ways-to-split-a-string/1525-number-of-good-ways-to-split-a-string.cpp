class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> pre, suff;
        unordered_set<char> st;
        for(auto c: s){
            st.insert(c);
            pre.push_back(st.size());
        }
        
        st = {};
        
        for(int i = n - 1; i >= 0; i--){
            st.insert(s[i]);
            suff.push_back(st.size());
        }
        
        for(auto c: pre){
            cout<<c<<"\t";
        }
        
        cout<<endl;
        
        for(auto c: suff){
            cout<<c<<"\t";
        }
        
        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            if(pre[i] == suff[n - 1 - i - 1]){
                cnt++;
            }
        }
        
        return cnt;
        
        
    }
};