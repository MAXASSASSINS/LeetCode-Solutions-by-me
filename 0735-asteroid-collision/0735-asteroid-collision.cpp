class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        
        
        for(int i = 0; i < asteroids.size(); i++){   
            int ast = asteroids[i];
            
            if(st.empty() || ast > 0 || (st.top() < 0 && ast < 0)){
                st.push(ast);
                continue;
            }  
            
            while(!st.empty() && st.top() > 0 && st.top() < ast * -1){
                st.pop();
            }
            
            
            if(!st.empty() && st.top() > 0 && st.top() == ast * -1){
                st.pop();
            }            
            else if(st.empty() || (st.top() < 0 && ast < 0)){
                st.push(ast);
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