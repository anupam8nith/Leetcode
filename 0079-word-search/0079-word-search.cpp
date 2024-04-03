class Solution {
public:
    int rows, cols;
    
    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int p, vector<vector<bool>>& visited) {
        // Base case: if the current position is out of bounds or the character doesn't match
        if (!isValid(i, j) || board[i][j] != word[p] || visited[i][j]) return false;
        
        // If we have matched all characters of the word
        if (p == word.length() - 1) return true;
        
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Explore in all four directions
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (dfs(board, word, ni, nj, p + 1, visited)) return true;
        }
        
        // Backtrack: unmark the current cell as visited
        visited[i][j] = false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        // Create a visited array to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Iterate through the board to find the starting point for DFS
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0, visited))
                    return true;
            }
        }
        
        return false;
    }
};
