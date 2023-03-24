//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(const string &s, vector<string> &ans, int index, string &temp){
	        if(index >= s.length()) return;
	        
	        // exlcude
	        solve(s, ans, index + 1, temp);
	        temp += s[index];
	        solve(s, ans, index + 1, temp);
	        ans.push_back(temp);
	        temp.pop_back();
	        
	
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string temp;
		    solve(s, ans, 0, temp);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends