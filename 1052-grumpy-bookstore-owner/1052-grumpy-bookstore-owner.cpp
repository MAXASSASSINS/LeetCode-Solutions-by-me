class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int maxIndex = -1;
        int maxGrumpyMinutes = 0;
        int grumpyMinutes = 0;
        
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1){
                grumpyMinutes += customers[i];
                maxIndex = 0;
            }
        }
        
        maxGrumpyMinutes = max(maxGrumpyMinutes, grumpyMinutes);
        
        for(int i = minutes; i < n; i++){
            if(grumpy[i] == 1){
                grumpyMinutes += customers[i];
            }
            if(grumpy[i - minutes] == 1){
                grumpyMinutes -= customers[i - minutes];
            }
            if(grumpyMinutes > maxGrumpyMinutes){
                maxGrumpyMinutes = grumpyMinutes;
                maxIndex = i - minutes + 1;
            }
        }
        
        int maxCustomerSatifisfied = 0;
        
        if(maxIndex != -1){
            for(int i = maxIndex; i < maxIndex + minutes && i < n; i++){
                maxCustomerSatifisfied += customers[i];
            }
        }
        
        cout<<maxIndex;
        
        for(int i = 0; i < n; i++){
            if(maxIndex != -1 && i >= maxIndex && i < maxIndex + minutes) continue;
            
            if(grumpy[i] == 0){
                maxCustomerSatifisfied += customers[i];
            }
        }
        
        return maxCustomerSatifisfied;
        
        
        
    }
};