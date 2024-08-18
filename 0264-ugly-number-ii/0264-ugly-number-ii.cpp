class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        st.insert(1);
        int currentUgly = 1;
        for(int i = 0; i < n; i++){
            currentUgly = *st.begin();
            
            st.insert(currentUgly * 1LL * 2);
            st.insert(currentUgly * 1LL * 3);
            st.insert(currentUgly * 1LL * 5);
            
            st.erase(currentUgly);
        }
        
        return currentUgly;
    }
};