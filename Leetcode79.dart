class Solution {
  bool exist(List<List<String>> board, String word) {
    int m = board.length;
    int n = board[0].length;

    List<List<bool>> visited = List.generate(m, (index) => List.filled(n, false));
    bool result = false;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == word[0]) {
          result = _backtrack(board, word, visited, i, j, 0);
          if (result) return true;
        }
      }
    }

    return false;
  }

  bool _backtrack(List<List<String>> board, String word, List<List<bool>> visited, int i, int j, int index) {
    if (index == word.length) {
      return true;
    }

    if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || visited[i][j] || board[i][j] != word[index]) {
      return false;
    }

    visited[i][j] = true;

    if (_backtrack(board, word, visited, i + 1, j, index + 1) ||
        _backtrack(board, word, visited, i - 1, j, index + 1) ||
        _backtrack(board, word, visited, i, j + 1, index + 1) ||
        _backtrack(board, word, visited, i, j - 1, index + 1)) {
      return true;
    }

    visited[i][j] = false;
    return false;
  }
}
