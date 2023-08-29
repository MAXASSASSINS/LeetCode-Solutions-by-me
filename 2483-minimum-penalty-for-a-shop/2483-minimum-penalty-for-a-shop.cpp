class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        vector<int> prefix(n);
        vector<int> suffix(n + 1);
        
        int cs = 0;
        int ce = 0;
        
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y') cs++;
            if(customers[n - 1 - i] == 'Y') ce++;
            
            prefix[i] = cs;
            suffix[n - 1 - i] = ce;
        }
        
        for(auto c: prefix){
            cout<<c<<"\t";
        }
        cout<<endl;
        for(auto x: suffix){
            cout<<x<<"\t";
        }
        
        int mini = suffix[0];
        int minHour = 0;
        
        for(int i = 1; i <= n; i++){
            int p = (i - prefix[i - 1]) + suffix[i];
            if(mini > p){
                mini = p;
                minHour = i;
            }
        }
        
        return minHour;
    }
};