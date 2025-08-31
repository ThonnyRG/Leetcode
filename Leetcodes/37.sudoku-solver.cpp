/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
using vusc = std::vector<std::unordered_set<char>>;
using vvc = std::vector<std::vector<char>>;

class Solution {
public:
    bool backtrack(size_t r, size_t c, vvc &board, vusc &rowHash, vusc &colHash, vusc &squareHash, const size_t &n, const size_t &m) {
        if (r == n) return true;
        size_t nR = r, nC = c + 1;
        if (nC == m) {
            nC = 0;
            ++nR;
        }
        if (board[r][c] != '.') return backtrack(nR, nC, board, rowHash, colHash, squareHash, n, m);
        for (int k = 1; k < 10; ++k) {
            char ck = k + '0';
            if (rowHash[r].count(ck) || colHash[c].count(ck)) continue;
            size_t square = r / 3 * 3 + c / 3;
            if (squareHash[square].count(ck)) continue;
            board[r][c] = ck;
            rowHash[r].insert(ck);
            colHash[c].insert(ck);
            squareHash[square].insert(ck);
            if (backtrack(nR, nC, board, rowHash, colHash, squareHash, n, m)) return true;
            board[r][c] = '.';
            rowHash[r].erase(ck);
            colHash[c].erase(ck);
            squareHash[square].erase(ck);
        }
        return false; // there is not possible moves that form correct sudoku
    }

    void solveSudoku(vvc &board) {
        size_t n = 9, m = 9;
        vusc rowHash(n), colHash(m), squareHash(n * m);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (board[i][j] == '.') continue;
                size_t square = i / 3 * 3 + j / 3;
                rowHash[i].insert(board[i][j]);
                colHash[j].insert(board[i][j]);
                squareHash[square].insert(board[i][j]);
            }
        }
        backtrack(0, 0, board, rowHash, colHash, squareHash, n, m);
    }
};
// @lc code=end

