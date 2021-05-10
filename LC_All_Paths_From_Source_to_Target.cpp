// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
// Logic : Apply DFS on all the adjacent nodes of the source node 0 until the goal node n-1 is found on all adjacent nodes are explored.
public:
    vector<vector<int>> all_paths; // to store all paths
    vector<int> temp_path; // to store current path in th recursive dfs()
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0); 
        return all_paths;
    }
    
    void dfs(vector<vector<int>>& graph, int cnode) {
        temp_path.push_back(cnode); // append current node value to the current path
        if(cnode==graph.size()-1) { // is current node is the goal node n-1
            all_paths.push_back(temp_path); // push current path to all_paths
            temp_path.pop_back(); // remove last node from the path and return
            return;
        }
        for(int i=0;i<graph[cnode].size();i++) { // for all outgoing edges from the current node
            dfs(graph,graph[cnode][i]); // call dfs on the adjacent node
            if(cnode==0) { // if current node is the source node 0
                temp_path.clear(); // clear path
                temp_path.push_back(cnode); // start new path
            }
        }
        temp_path.pop_back(); // remove current node from the path as all its outgoing edges are checked and return
    }
};
