class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string t = s + s;
        // cout<<t<<endl;
        int i = 0;
        while(i < t.length()){
            if(t[i] == goal[0]){
                // cout<<i<<endl;
                int j = 0;
                while(i < t.length() && j < goal.length() && t[i] == goal[j]){
                    i++;
                    j++;
                }
                cout<<j<<endl;
                if(j >= goal.length()){
                    return true;
                }
                i -= j;
            }
            i++;
        }
        
        return false;
    }
};