// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
	    // Code here
	    int steps=0;
	    pair<int,int> start_pos = {KnightPos[0]-1,KnightPos[1]-1};
	    pair<int,int> end_pos = {TargetPos[0]-1,TargetPos[1]-1};
	    queue<pair<pair<int,int>,int>> bfsq;
	    bfsq.push({start_pos,0});
	    bool visited[N][N];
	    for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                visited[i][j] = false;
        visited[start_pos.first][start_pos.second] = true;
	   // set<pair<int,int>> visited;
	    while(!bfsq.empty()) {
            pair<pair<int,int>,int> qfront = bfsq.front();
            bfsq.pop();
            pair<int,int> cur_pos = qfront.first;
            int cur_level = qfront.second;
            // cout << "cp " << cur_level << "  qs " << bfsq.size() << endl;
            if(cur_pos == end_pos) {
                steps = cur_level;
                break;
            }
            int i = cur_pos.first;
            int j = cur_pos.second;
            // visited[i][j] = true;
            if(i+1<N && j+2<N && !visited[i+1][j+2]) {
                visited[i+1][j+2] = true;
                bfsq.push({{i+1,j+2},cur_level+1});
            }
            if(i+1<N && j-2>=0 && !visited[i+1][j-2]) {
                visited[i+1][j-2] = true;
                bfsq.push({{i+1,j-2},cur_level+1});
            }
            if(i-1>=0 && j+2<N && !visited[i-1][j+2]) {
                visited[i-1][j+2] = true;
                bfsq.push({{i-1,j+2},cur_level+1});
            }
            if(i-1>=0 && j-2>=0 && !visited[i-1][j-2]) {
                visited[i-1][j-2] = true;
                bfsq.push({{i-1,j-2},cur_level+1});
            }
            if(i+2<N && j+1<N && !visited[i+2][j+1]) {
                visited[i+2][j+1] = true;
	            bfsq.push({{i+2,j+1},cur_level+1});
            }
	        if(i+2<N && j-1>=0 && !visited[i+2][j-1]) {
	            visited[i+2][j-1] = true;
	            bfsq.push({{i+2,j-1},cur_level+1});
	        }
	        if(i-2>=0 && j+1<N && !visited[i-2][j+1]) {
	            visited[i-2][j+1] = true;
	            bfsq.push({{i-2,j+1},cur_level+1});
	        }
	        if(i-2>=0 && j-1>=0 && !visited[i-2][j-1]) {
	            visited[i-2][j-1] = true;
	            bfsq.push({{i-2,j-1},cur_level+1});
	        }
	    }
	    return steps;
	}
};
