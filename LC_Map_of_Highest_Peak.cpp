// https://leetcode.com/problems/map-of-highest-peak/

class Solution {
// Logic : Consider each cell as a node of a graph and 4 adjacent cells as its children. Starting with water cells, apply BFS on unvisited nodes and assign value to the child nodes as p+1 where p is the peak value of the current node.
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        bool isvisited[r][c];
        vector<vector<int>> peaks(r,vector<int>(c,0));
        queue<pair<pair<int,int>,int>> bfsq;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                isvisited[i][j] = false;
                if(isWater[i][j]==1) {
                    bfsq.push(make_pair(make_pair(i,j),0));
                    isvisited[i][j] = true;
                }
            }
        }
        while(!bfsq.empty()) {
            pair<pair<int,int>,int> cell = bfsq.front();
            bfsq.pop();
            int x = cell.first.first;
            int y = cell.first.second;
            int p = cell.second;
            peaks[x][y] = p;
            // cout << x << ',' << y << " --> " << p << endl;
            p += 1;
            if(x < r-1) {
                if(!isvisited[x+1][y]) { // bottom
                    bfsq.push(make_pair(make_pair(x+1,y),p));
                    isvisited[x+1][y] = true;
                }
            }
            if(x > 0) {
                if(!isvisited[x-1][y]) { // top
                    bfsq.push(make_pair(make_pair(x-1,y),p));
                    isvisited[x-1][y] = true;
                }
            }
            if(y < c-1) {
                if(!isvisited[x][y+1]) { // right
                    bfsq.push(make_pair(make_pair(x,y+1),p));
                    isvisited[x][y+1] = true;
                }
            }
            if(y > 0) {
                if(!isvisited[x][y-1]) { // left
                    bfsq.push(make_pair(make_pair(x,y-1),p));
                    isvisited[x][y-1] = true;
                }
            }
        }
        return peaks;
    }
};
