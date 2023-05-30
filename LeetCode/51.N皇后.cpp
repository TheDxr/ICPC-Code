class Solution {
  public:
    vector<vector<string>> solveNQueens(int n) {
        this->N = n;
        init_board();
        dfs(0);
        return ans;
    }

  private:
    vector<string> board;
    vector<vector<string>> ans;
    int N;
    void dfs(int row) {
        if(row == N) 
            ans.emplace_back(board); 
        if(row >= N)return;
        for(int col = 0; col < N; col++) {
            if(check(row, col)) {
                board[row][col] = 'Q';                                      
                dfs(row + 1);
                board[row][col] = '.';  
            }
        }
    }
    bool check(int row, int col) {
        for(int i = 0; i <= row; i++) {
            if(board[row - i][col] == 'Q') return false;
        }
        for(int i = 0; i <= col; i++) {
            if(board[row][col - i] == 'Q') return false;
        }
        for(int i = 0; i <= min(row, col); i++) {
            if(board[row - i][col - i] == 'Q') return false;
        }
        for(int i = 0; row - i >= 0 && col + i <= N; i++) {
            if(board[row - i][col + i] == 'Q') 
                return false;
        }
        return true;
    }
    void init_board() {
        board.resize(N);
        for(int i = 0; i < N; i++) {
            board[i].resize(N);
            for(int j = 0; j < N; j++) {
                board[i][j] = '.';
            }
        }
    }
};