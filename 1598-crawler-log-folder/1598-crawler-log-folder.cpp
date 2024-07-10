class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto log: logs){
            if(log == "../" && !st.empty()){
                st.pop();
            }
            else if(isalnum(log[0])){
                st.push(log);
            }
        }
        
        return (int)st.size();
    }
};