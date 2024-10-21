class Solution {
public:
    int solve(string s, set<string> &st, int index){
        if(index >= s.size()){
            return st.size();
        }
        
        string temp;
        int incl = 0;
        for(int i = index; i < s.length(); i++){
            temp += s[i];
            if(st.find(temp) == st.end()){
                st.insert(temp);
                incl = max(incl, solve(s, st, i + 1));
                st.erase(temp);
            }
        }
        
        return incl;
        
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        return solve(s, st, 0);
    }
};