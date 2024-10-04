class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long ans = 0;
        
        int i = 0;
        int j = n - 1;
        
        int sum = skill[i] + skill[j];
        i++;
        j--;
        while(i < j){
            if(skill[i] + skill[j] != sum) return -1;
            i++;
            j--;
        }
        
        for(int i = 0; i < n / 2; i++){
            ans += (skill[i] * skill[n - 1 - i]);
        }
        
        return ans;
    }
};