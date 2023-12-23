class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;
        int x = 0;
        int y = 0;
        s.insert({x, y});
        
        for(auto step: path){
            switch (step){
                case 'N':
                    y--;
                    break;
                case 'S':
                    y++;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
                default:
                    cout<<"hello";
                    break;
            }
            if(s.find({x, y}) != s.end()){
                return true;
            }
            s.insert({x,y});
        }
        
        return false;
        
    }
};