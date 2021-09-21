// Apply DFS on from the boundary cells which have 'O' n them. In DFS, change the value of the current cell to 'Y' 
// and recurse whenever the adjacent cell has 'O'. Here 'Y' represents and the cell contained 'O' and is reachable from a boundary cell.
// When DFS on all boundary cells is done, parse through the matrix again and change 'O' to 'X' and 'Y' to 'O'.

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size(), c=board[0].size();
        if(r<=2 || c<=2)
            return;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(i==0 || j==0 || i==r-1 || j==c-1) {
                    if(board[i][j]=='O') {
                        dfs(board,i,j,r,c);
                    }
                }
            }
        }
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(board[i][j]=='O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int r, int c) {
        board[i][j] = 'Y';
        if(i+1 < r && board[i+1][j] == 'O')
            dfs(board,i+1,j,r,c);
        if(i-1>=0 && board[i-1][j] == 'O')
            dfs(board,i-1,j,r,c);
        if(j+1<c && board[i][j+1] == 'O')
            dfs(board,i,j+1,r,c);
        if(j-1>=0 && board[i][j-1] == 'O')
            dfs(board,i,j-1,r,c);
        return;
    }
};
