class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        st.insert(1);
        long currentUgly = 1;
        for(int i = 0; i < n; i++){
            currentUgly = *st.begin();
            
            st.insert(currentUgly * 1L * 2);
            st.insert(currentUgly * 1L * 3);
            st.insert(currentUgly * 1L * 5);
            
            st.erase(currentUgly);
        }
        
        return (int)currentUgly;
    }
};