class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int,int> m;
        for(int x: hand){
            m[x]++;
        }
        
        while(!m.empty()){
            auto it = m.begin();
            vector<int> temp;
            for(int i = 0; i < groupSize && it != m.end(); i++){
                if(temp.size() == 0 || it->first - temp.back() == 1){
                    temp.push_back(it->first);
                    it->second--;
                    if(it->second == 0){
                        m.erase(it->first);
                    }
                }
                else{
                    return false;
                }
                it++;
            }
            if(temp.size() != groupSize) return false;
        }
        
        return true;
    }
};