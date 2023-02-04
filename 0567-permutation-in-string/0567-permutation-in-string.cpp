class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        map<char,int> m;
        for(auto c: s1){
            m[c]++;
        }
        int l = s1.length();
        queue<char> q;
        for(int i = 0; i < l; i++){
            q.push(s2[i]);
            m[s2[i]]--;
        }
        bool allZero = true;
        for(auto it: m){
            if(it.second != 0)
                allZero = false;
        }
        if(allZero) return true;
        allZero = true;
        int j = l;
        while(j < s2.length()){
            char c = q.front();
            m[c]++;
            q.pop();
            q.push(s2[j]);
            m[s2[j]]--;
            for(auto it: m){
                if(it.second != 0)
                    allZero = false;
            }
            if(allZero) return true;
            allZero = true;
            j++;
        }
        
        return false;
        
    }
};