class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // checking rows
        for (int i = 0; i < board.size(); ++i) {
            int bit = 0;
            for (int j = 0; j < board.size(); ++j) {
                if(board[i][j] != '.'){
                    int bitsToShift = board[i][j] - 48;
                    int l = 1 << bitsToShift;
                    if((l & bit) == 0){
                        bit |= l;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // checking columns
        for (int i = 0; i < board.size(); ++i) {
            int bit = 0;
            for (int j = 0; j < board.size(); ++j) {
                if(board[j][i] != '.'){
                    int bitsToShift = board[j][i] - 48;
                    int l = 1 << bitsToShift;
                    if((l & bit) == 0){
                        bit |= l;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // checking 3 * 3 matrix
        int x = 0,y = 0;
        while(x + 3 <= board.size()){
            y  = 0;
            while(y + 3 <= board.size()){
                int bit = 0;
                for (int i = x; i < x + 3; ++i) {
                    for (int j = y; j < y + 3; ++j) {
                        if (board[i][j] != '.'){
                            int bitsToShift = board[i][j] - 48;
                            int l = 1 << bitsToShift;
                            if((l & bit) == 0){
                                bit |= l;
                            }
                            else{
                                return false;
                            }
                        }
                    }
                }
                y = y+3;
            }
            x = x+3;
        }

        return true;
    }
};