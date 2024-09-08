class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        int n = beginWord.length();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        
        int res = INT_MAX;
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string s = p.first;
            int level = p.second;
            if(s == endWord){
                res = min(res, level);
            }
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < 26; j++){
                    char temp = s[i];
                    s[i] = 'a' + j;
                    if(words.find(s) != words.end()){
                        words.erase(s);
                        q.push({s, level + 1});
                    }
                    s[i] = temp;
                }
            }
        }
        
        if(res == INT_MAX) return 0;
        return res;
        
    }
};