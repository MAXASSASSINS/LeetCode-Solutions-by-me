class Solution {
public:
    int minDeletions(string s) {
        vector<int> vec(26);
        
        for(auto c: s){
            vec[c - 'a']++;
        }
        
        sort(vec.begin(), vec.end(), greater<int>());
        
        // for(auto c: vec){
        //     cout<<c<<"\t";
        // }
        for(auto c: vec){
            cout<<c<<"\t";
        }
        cout<<endl<<endl;
        
        int i = 0;
        int ans = 0;
        bool foundZero = false;
        while(i < 25){
            if(vec[i] == 0){
                foundZero = true;
                break;
            }
            else if(vec[i] == vec[i + 1]){
                ans++;
                vec[i + 1]--;
            }
            else if(vec[i] < vec[i + 1]){
                ans += (vec[i + 1] - vec[i] + 1);
                vec[i + 1] = vec[i] - 1 > 0 ? vec[i] - 1 : 0;
            }
            i++;
        }
        
        while(i < 26 && foundZero){
            ans += vec[i];
            i++;
        }
        return ans;   
    }
};