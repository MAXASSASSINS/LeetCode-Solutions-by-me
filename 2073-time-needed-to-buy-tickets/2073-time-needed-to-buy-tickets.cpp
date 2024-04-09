class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t = 0;
        while(tickets[k] != 1){
            for(int i = 0; i < tickets.size(); i++){
                if(tickets[i] > 0){
                    tickets[i]--;
                    t++;
                }
            }
        }
        for(int i = 0; i <= k; i++){
            if(tickets[i] > 0){
                tickets[i]--;
                t++;
            }
        }
        
        return t;
    }
};