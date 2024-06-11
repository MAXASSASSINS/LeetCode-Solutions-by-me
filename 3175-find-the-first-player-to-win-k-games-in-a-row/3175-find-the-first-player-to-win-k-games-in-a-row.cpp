class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if(k >= n){
            auto it =  max_element(skills.begin(), skills.end());
            return it - skills.begin();
        }   
        
        int maxi = skills[0];
        int beats = 0;
        
        for(int i = 1; i < n; i++){
            if(skills[i] > maxi){
                maxi = skills[i];
                beats = 1;
            }
            else{
                beats++;
            }
            if(beats >= k){
                for(int j = 0; j < n; j++){
                    if(maxi == skills[j]){
                        return j;
                    }
                }
            }
        }
        auto it =  max_element(skills.begin(), skills.end());
        return it - skills.begin();
    }
    
};