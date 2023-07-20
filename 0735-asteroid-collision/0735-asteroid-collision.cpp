class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            int ast = asteroids[i];
            
            if(st.empty() || st.top() < 0 || ast > 0) st.push(ast);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(ast)){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(ast)){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0) st.push(ast);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};