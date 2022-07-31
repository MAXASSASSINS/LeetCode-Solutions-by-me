class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for (int i = 0; i < s.length(); ++i) {
            if(s.at(i) == '#'){
                if(a.empty())
                    continue;
                a.pop();
            }
            else{
                a.push(s.at(i));
            }
        }
        for (int i = 0; i < t.length(); ++i) {
            if(t.at(i) == '#'){
                if (b.empty())
                    continue;
                b.pop();
            }
            else{
                b.push(t.at(i));
            }
        }
        if(a.size() != b.size()){
            return false;
        }
        while (!a.empty() && !b.empty()){
            if (a.top() != b.top()){
                return false;
            }
            a.pop();
            b.pop();
        }
        return true;
    }
};