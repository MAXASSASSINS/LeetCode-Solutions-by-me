class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long time = 0;
        long long totalWaitingTime = 0;
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
        
        return double(totalWaitingTime) / customers.size();
    }
};