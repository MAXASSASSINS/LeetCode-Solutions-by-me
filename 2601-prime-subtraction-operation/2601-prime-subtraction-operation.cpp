class Solution {
public:
    vector<int> fillPrimes(int maxi){
        vector<bool> vec(maxi + 1, true);
        vec[0] = false;
        vec[1] = false;
        
        for(int i = 2; i < vec.size(); i++){
            if(vec[i]){
                for(int j = 2 *i ; j < vec.size(); j+= i){
                    vec[j] = false;
                }
            }
        }
        
        vector<int> primes;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i]) primes.push_back(i);
        }
        
        return primes;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = fillPrimes(1000);
        cout<<primes.size()<<endl;
        int n = nums.size();
        
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] >= nums[i + 1]){
                int index = lower_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1] + 1) - primes.begin();
                if(primes[index] >= nums[i]) return false;
                nums[i] -= primes[index];
                if(nums[i] > nums[i + 1]) return false;
            }
        }
        
        return true;
    }
};