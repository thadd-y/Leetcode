#include <vector>
using namespace std;

class Solution {
    
    bool rowUsed[9][10] = {}, colUsed[9][10] = {}, boxUsed[9][10] = {};
    vector<pair<int, int>> empties; 

    bool dfs(vector<vector<char>>& board, int idx) {
        if (idx == empties.size()) return true; 

        auto [r, c] = empties[idx];
        int b = (r / 3) * 3 + c / 3; 

        for (int d = 1; d <= 9; d++) {
            if (rowUsed[r][d] || colUsed[c][d] || boxUsed[b][d]) continue;

            
            rowUsed[r][d] = colUsed[c][d] = boxUsed[b][d] = true;
            board[r][c] = '0' + d;

            if (dfs(board, idx + 1)) return true;

            
            rowUsed[r][d] = colUsed[c][d] = boxUsed[b][d] = false;
        }
        board[r][c] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    empties.push_back({r, c});
                } else {
                    int d = board[r][c] - '0';
                    rowUsed[r][d] = colUsed[c][d] = boxUsed[(r / 3) * 3 + c / 3][d] = true;
                }
            }
        }
        dfs(board, 0);
    }
};