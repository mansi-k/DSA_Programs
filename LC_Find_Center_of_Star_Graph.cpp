// https://leetcode.com/problems/find-center-of-star-graph/

class Solution {
// Logic : As the input is a valid star graph, just count the occurences of each vertex and return vertex with max count >= n-1. But since it is given that the vector of edges is of length n-1 (no edges repeat), we can just check which vertex repeats in the first 2 edges and return it.
public:
    int findCenter(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a = edges[0][0];
        int b = edges[0][1];
        if(a==edges[1][0] || a==edges[1][1])
            return a;
        return b;
        // for(int i=1;i<edges.size();i++) {
        //     int a = edges[i][0];
        //     int b = edges[i][1];
        // }
        // map<int,int> vrtx_counts;
        // for(int i=0;i<edges.size();i++) {
        //     int a = edges[i][0];
        //     int b = edges[i][1];
        //     vrtx_counts[a]+=1;
        //     vrtx_counts[b]+=1;
        // }
        // int cv;
        // for(auto it=vrtx_counts.begin();it!=vrtx_counts.end();it++) {
        //     if(it->second >= vrtx_counts.size()-1) {
        //         cv = it->first; 
        //     }
        // }
        // return cv;
    }
};
