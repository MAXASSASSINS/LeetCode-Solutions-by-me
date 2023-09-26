class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        
        vector<int> vec(26);
        vector<bool> seen(26, false);
        
        for(auto c: s){
            vec[c - 'a']++;
        }
        
        
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            
            if(seen[c - 'a']){
                vec[c - 'a']--;
                continue;
            }
            
            while(!st.empty() && c < st.top() && vec[st.top() - 'a'] > 0){
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(c);
            vec[c - 'a']--;
            seen[c - 'a'] = true;

        }
        
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};