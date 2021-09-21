// Apply DFS from the cell which has first letter of the search word.

class Solution {
public:
    string search_word = "";
    bool exist(vector<vector<char>>& board, string word) {
        search_word = word;
        bool result=false;
        int r = board.size(), c=board[0].size();
        if(r*c < word.length())
            return result;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(board[i][j]==word[0]) {
                    result = dfs(board,i,j,r,c,0);
                    if(result)
                        return result;
                }
            }
        }
        return result;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int r, int c, int w) {
        bool res=false;
        // cout << i << " " << j << " " << search_word[w] << endl;
        if(w==search_word.length()-1) {
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '0';  // temporarily change the letter of the current cell so that it is not counted twice
        w += 1;
        if(i+1 < r && res==false && board[i+1][j]==search_word[w])
            res = dfs(board,i+1,j,r,c,w);
        if(res==false && i-1 >= 0 && board[i-1][j]==search_word[w])
            res = dfs(board,i-1,j,r,c,w);
        if(res==false && j+1 < c && board[i][j+1]==search_word[w])
            res = dfs(board,i,j+1,r,c,w);
        if(res==false && j-1 >= 0 && board[i][j-1]==search_word[w])
            res = dfs(board,i,j-1,r,c,w);
        board[i][j] = temp;  // reset the cell to its original letter
        return res; 
    }
};
