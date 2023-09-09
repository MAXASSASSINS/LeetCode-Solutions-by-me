class Solution {
public:
    bool isSafe(const vector<vector<char>> &board,const int &row,const int &col,const char &target){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == target) return false;
        }

        for(int j = 0; j < 9; j++){
            if(board[row][j] == target) return false;
        }

        int rst = row - (row % 3);
        int rend = rst + 3;
        int cst = col - col % 3;
        int cend = cst + 3;
        for(int i = rst; i < rend; i++){
            for(int j = cst; j < cend; j++){
                if(board[i][j] == target) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isSafe(board, i, j, c)){
                            board[i][j] = c;
                            if(solve(board) == true){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};