class Solution {
    int getRes(vector<vector<int>> &items, int target, vector<int> &prefix){
        int l = 0;
        int h = items.size() - 1;
        
        if(target < items[0][0]) return 0;
        
        while(l <= h){
            int m = (l + h) / 2;
            int price = items[m][0];
            
            if(price > target){
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        
        return prefix[h];
    }
    
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        vector<int> prefix;
        int maxi = 0;
        for(auto item: items){
            maxi = max(maxi, item[1]);
            prefix.push_back(maxi);
        }
        
        vector<int> ans;
        
        for(auto q: queries){
            int val = getRes(items, q, prefix);
            ans.push_back(val);
        }
        
        return ans;
    }
};