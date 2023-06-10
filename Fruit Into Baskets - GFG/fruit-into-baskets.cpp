//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        pair<int,int> p1 = {-1, 0};
        pair<int, int> p2 = {-1, 0};
        
        
        int j = -1;
        int ans = 0;
        
        for(int i = 0; i < N; i++){
            int f = fruits[i];
            if(p1.first == -1){
                p1.first = f;
                p1.second++;
            }
            else if(p2.first == -1 && f != p1.first){
                p2.first = f;
                p2.second++;
            }
            else if(f != p1.first && f != p2.first){
                while(p1.second != 0 && p2.second != 0){
                    j++;
                    if(fruits[j] == p1.first) p1.second--;
                    if(fruits[j] == p2.first) p2.second--;
                }
                if(!p1.second) {
                    p1.first = f;
                    p1.second++;
                }
                if(!p2.second){
                    p2.first = f;    
                    p2.second++;
                } 
                
            }
            else if(f == p1.first){
                p1.second++;
            }
            else{
                p2.second++;
            }
            ans = max(ans, i - j);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends