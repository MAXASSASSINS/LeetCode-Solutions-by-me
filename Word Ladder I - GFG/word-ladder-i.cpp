//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        
        
        while(!q.empty()){
            string word = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(word == endWord) return dis;
            
            for(int i = 0; i < word.length(); i++){
                char currChar = word[i];
                for(char j = 'a'; j < 'z'; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, dis + 1});
                    }
                }
                word[i] = currChar;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends