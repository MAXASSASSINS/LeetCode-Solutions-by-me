class Solution {
public:
    bool isPossible(vector<int> &position, int m, int gap){
        int prev = position[0];
        m--;
        for(int i = 1; i < position.size(); i++){
            int curr = position[i];
            if(curr - prev >= gap){
                prev = curr;
                m--;
            }
            if(m == 0) return true;
        }    
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        
        int low = 1;
        int high = position[n - 1];
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            bool possible = isPossible(position, m, mid);
            
            if(possible){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return high;
        
    }
};