class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[positions[i]] = {healths[i], directions[i], i};
        }
        
        stack<map<int, vector<int>>::iterator> st;
        
        
        for(auto it = m.begin(); it != m.end(); it++){
            int health = it->second[0];
            int direction = it->second[1];
            int position = it->first;
            // cout<<position<<endl;
            
            if(direction == 'R'){
                st.push(it);
                continue;
            }
            
            if(!st.empty() && st.top()->second[0] < health){
                while(!st.empty() && st.top()->second[0] < health){
                    healths[st.top()->second[2]] = 0;
                    st.top()->second[0] = 0;
                    st.pop();
                    health--;
                }
            }
            if(!st.empty() && st.top()->second[0] == health){
                // cout<<health<<endl;
                healths[st.top()->second[2]] = 0;
                st.top()->second[0] = 0;
                health = 0;
                st.pop();
                // for(auto x: healths){
                //     cout<<x<<"\t";
                // }
            }
            else if(!st.empty() && st.top()->second[0] > health){
                health = 0;
                healths[st.top()->second[2]]--;
                st.top()->second[0]--;
            }
            
            it->second[0] = health;
            it->second[1] = direction;
            // update the health list
            healths[it->second[2]] = health;
            // for(auto x: healths){
            //         cout<<x<<"\t";
            // }
            cout<<endl;
        }
        
        vector<int> ans;
        for(auto h: healths){
            if(h > 0) ans.push_back(h);
        }
        
        return ans;      
     }
};