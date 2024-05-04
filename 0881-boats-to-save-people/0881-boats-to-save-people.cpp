class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        
        int boats = 0;
        int ptsf = 0; // peopleTravelledSoFar --> ptsf
        while(ptsf < people.size()){
            if(people[i] + people[j] <= limit){
                i++;
                j--;
                ptsf+=2;
            }
            else{
                j--;
                ptsf++;
            }
            boats++;
        }
        
        return boats;
    }
};