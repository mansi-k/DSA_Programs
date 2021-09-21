class Solution {
public:
    int minX = INT_MAX, minY=INT_MAX, maxX=INT_MIN, maxY=INT_MIN;

    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here
        int R = image.size();
        int C = image[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, 0));
        dfs(image, x, y, visited);
        int area = ((maxX-minX)+1) * ((maxY-minY)+1);
        return area;
    }

    void dfs(vector<vector<char>>& image, int x, int y, vector<vector<bool>>& visited){
        if(image[x][y]=='1'){
            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
            visited[x][y] = true;
        }
        int R = image.size();
        int C = image[0].size();

        if(x-1>=0 && image[x-1][y] == '1' && !visited[x-1][y])  dfs(image, x-1, y, visited);
        if(x+1<R && image[x+1][y] == '1' && !visited[x+1][y])   dfs(image, x+1, y, visited);
        if(y-1>=0 && image[x][y-1] == '1' && !visited[x][y-1])  dfs(image, x, y-1, visited);
        if(y+1<C && image[x][y+1] == '1' && !visited[x][y+1])   dfs(image, x, y+1, visited);
    }
};
