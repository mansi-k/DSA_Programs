// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
// Logic : find minimum number of nodes which aren't rechable by simply calculating nodes whose indegree is zero and return those nodes
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bool has_indegree[n];
        vector<int> min_vertices;
        for(int i=0;i<n;i++) {
            has_indegree[i] = false;
        }
        for(int i=0;i<edges.size();i++) {
            has_indegree[edges[i][1]] = true;
        }
        for(int i=0;i<n;i++) {
            if(!has_indegree[i]) 
                min_vertices.push_back(i);
        }
        return min_vertices;
    }
};
