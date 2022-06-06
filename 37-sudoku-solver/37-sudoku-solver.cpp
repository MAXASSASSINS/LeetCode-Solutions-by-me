class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board, int row, int col, int target) {

        // checking row
        for (int i = 0; i < board.size(); ++i) {
            if(board[row][i] == char(target + '0')){
                return false;
            }
        }
        // checking columns
        for (int i = 0; i < board.size(); ++i) {
            if(board[i][col] == char(target + '0')){
                return false;
            }

        }
        // checking 3 * 3 matrix
        int rowst = row - row % 3;
        int colst = col - col % 3;
        for (int i = rowst; i < rowst + 3; ++i) {
            for (int j = colst; j < colst + 3; ++j) {
               if(board[i][j] == char(target + '0')){
                   return false;
               }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        int numToFill = 1;
        int row = -1;
        int col = -1;
        int emptyLeft =  false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board.at(i).at(j) == '.'){
                    row = i;
                    col = j;
                    emptyLeft = true;
                    break;
                }
            }
            if (emptyLeft)
                break;
        }

        // Sudoku is already solved as no empty places are found
        if (!emptyLeft){
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board.size(); ++j) {
                    cout<<board.at(i).at(j)<<" ";
                }
                cout<<endl;
            }
            return true;
        }

        for (int i = 1; i <= 9 ; ++i) {
            if(isValidSudoku(board, row, col, i)){
                board.at(row).at(col) = char(i + '0');
                if(solve(board)){
                    //found the answer
                    return true;
                }
                else{
                    board.at(row).at(col) = '.';
                }
            }
        }

        return false;
    }
};