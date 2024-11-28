class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board, string word,
               int ind) {
        int n = board.size();
        int m = board[0].size();
        if (ind == word.length())
            return true;
        if (row < 0 || row >= n || col < 0 || col >= m ||
            board[row][col] != word[ind])
            return false;

        char temp = board[row][col];
        board[row][col] = '#'; 
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        if (row >= 0 and row < n and col >= 0 and col < m) {
            for (int i = 0; i < 4; i++) {
                int nRow = row + drow[i];
                int nCol = col + dcol[i];
                if (solve(nRow, nCol, board, word, ind + 1)) {
                    board[row][col] = temp;
                    return true;
                }
            }
        }
        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};