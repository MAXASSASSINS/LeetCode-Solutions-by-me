class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i = 0; i < 32; i++){
            int cbit = c & 1;
            int abit = a & 1;
            int bbit = b & 1;
            
            c = c >> 1;
            a = a >> 1;
            b = b >> 1;
            
            if(cbit){
                if(!abit && !bbit){
                    flips++;
                }    
            }
            else{
                if(abit) flips++;
                if(bbit) flips++;
            }
        }
        
        return flips;
    }
};