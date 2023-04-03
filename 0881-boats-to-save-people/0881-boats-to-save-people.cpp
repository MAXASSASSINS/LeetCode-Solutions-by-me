class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int l = 0;
        int h = people.size() -1;
        while(l < h){
            int sum = people[l] + people[h];
            if(sum > limit){
                h--;
            }
            else{
                l++;
                h--;
            }
            ans++;
        }
        if(l == h) ans++;
        return ans;
    }
};