class Solution {
public:
    // bool min(long int a, long int b){
    //     return a <= b;
    // }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        sort(primes.begin(), primes.end());
        
        vector<int> indices(primes.size(), 0);
        vector<int>temp = {1};
        
        
        while(temp.size() <= n){
            int mini = INT_MAX;
            for(int i = 0; i < primes.size(); i++){
                if(temp[indices[i]] > INT_MAX / primes[i]){
                    continue;
                }
                mini = min(mini, primes[i] * temp[indices[i]]);
            }
            for(int i = 0; i < primes.size(); i++){
                if(temp[indices[i]] > INT_MAX / primes[i]){
                    continue;
                }
                if(mini == temp[indices[i]] * primes[i]){
                    indices[i]++;
                }
            }
            temp.push_back(mini);
        }
        
        for(auto n: indices){
            cout<<n<<" ";
        }
        
        return temp[n - 1];
        
    }
};