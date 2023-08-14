class StringComparator {
public:
    bool operator() (string &b, string &a) { // Please note, I swap position of `a` and `b` here!
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
public:
    bool static cmp(string s1, string s2){
        return s1 >= s2;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>,  StringComparator> pq;
        
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        
        return pq.top();   
    }
};