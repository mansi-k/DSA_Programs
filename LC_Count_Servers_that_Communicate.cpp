// https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
// Logic : store the count of the number of servers in each row and column. Parse through the grid and check if the count in the current server's row or column is greater than 1. If yes then increase the count.
public:
    int countServers(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();
        int rows[n];
        int cols[m];
        for(int i=0;i<n;i++) {
            rows[i] = 0;
        }
        for(int i=0;i<m;i++) {
            cols[i] = 0;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // cout << "rows " << rows[i] << " *** cols " << cols[j] << endl;
                if(grid[i][j]==1 && max(rows[i],cols[j])>1) {
                    count++;
                }
            }
        }
        return count;
    }
};
