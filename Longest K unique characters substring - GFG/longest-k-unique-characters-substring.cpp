//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1;
        int j = -1;
        unordered_map<char, int> m;
        
        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
            while(m.size() > k){
                j++;
                m[s[j]]--;
                if(m[s[j]] == 0){
                    m.erase(s[j]);
                }
            }
            if(m.size() == k){
                ans = max(ans, i - j);    
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends