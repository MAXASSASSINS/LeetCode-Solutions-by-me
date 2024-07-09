class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time = 0;
        double totalWaitingTime = 0;
        for(auto customer: customers){
            if(customer[0] > time){
                totalWaitingTime += customer[1];
                time = customer[0] + customer[1];
            }
            else{
                totalWaitingTime += (time - customer[0]) + customer[1];
                time += customer[1];
            }
        }
        
        return totalWaitingTime / customers.size();
    }
};