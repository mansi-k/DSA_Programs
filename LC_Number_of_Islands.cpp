// Apply DFS on the cells containing 1s to group the adjacent 1s into 1 island. 
// Simultaneously in DFS keep track of visited nodes by updating the values of the visited cells to prevent double counting.
// Increment the island count after each DFS completion

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int number_islands = 0;
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                if(grid[row][column] == '1'){
                    number_islands++;
                    dfs(row, column, grid);
                }
            }
        }
        return number_islands;
    }
    
    void dfs(int row, int column, vector<vector<char>>& grid){
        if(row < 0 or column < 0 or row >= grid.size() or column >= grid[0].size()
          or grid[row][column] == '0' or grid[row][column] == 'V') 
            return ;
        grid[row][column] = 'V';
        dfs(row + 1, column, grid); //down
        dfs(row - 1, column, grid); //up
        dfs(row, column + 1, grid); //right
        dfs(row, column - 1, grid); //left
    }
    
};
