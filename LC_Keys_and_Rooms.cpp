// https://leetcode.com/problems/keys-and-rooms/

class Solution {
// Logic : Treat rooms as graph nodes and keys as edges. Apply BFS on unvisited nodes, keep track of visited nodes and check if any room remains unvisited after BFS is done. Can be done with DFS too.
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool isvisited[rooms.size()];
        for(int i=0; i<rooms.size();i++) {
            isvisited[i] = false;
        }
        queue<int> bfsq;
        bfsq.push(0);
        while(!bfsq.empty()) {
            int croom = bfsq.front();
            bfsq.pop();
            isvisited[croom] = true;
            for(int j=0;j<rooms[croom].size();j++) {
                if(!isvisited[rooms[croom][j]])
                    bfsq.push(rooms[croom][j]);
            }
        }
        bool allvisited=true;
        for(int i=0; i<rooms.size();i++) {
            if(!isvisited[i]) {
                allvisited = false;
            }
        }
        return allvisited;
    }
};
