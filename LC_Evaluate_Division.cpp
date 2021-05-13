// https://leetcode.com/problems/evaluate-division/
class Solution {
// Logic : Create a graph adjacency list from the equations with values as its weights. Also store the reverse edges (equations) with weights as reciprocal of the given values. Apply DFS starting from the source until destination is found or cycle is detected. Return the multiplication of egde weights if destination is found.
public:
    unordered_map<string,unordered_map<string,double>> graph;
    unordered_map<string,bool> isvisited;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> answers;
        for(int i=0;i<equations.size();i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        for(int i=0;i<queries.size();i++) {
            if(graph.find(queries[i][0])==graph.end() || graph.find(queries[i][1])==graph.end()) { // if the string given in the query does not exist in the graph
                answers.push_back(-1);
                continue;
            }
            // cout << "q " << queries[i][0] << ',' << queries[i][1] << endl;
            double a = dfs(queries[i][0],queries[i][1]);
            isvisited.clear();
            answers.push_back(a);
            isvisited.clear();
        }
        return answers;
    }
    
    double dfs(string src, string dest) {
        // cout << src << ',' << dest << endl;
        if(isvisited.find(src) != isvisited.end())
            return -1;
        double mul = -1;
        if(graph[src].find(dest) != graph[src].end()) {
            mul = graph[src][dest];
            return mul;
        }
        if(graph[dest].find(src) != graph[src].end()) {
            mul = (double) 1/graph[dest][src];
            return mul;
        }
        isvisited[src] = true;
        double x=0;
        for(auto it=graph[src].begin();it!=graph[src].end();it++) {
            // cout << "***" << it->first << endl;
            x = dfs(it->first, dest);
            if(x > -1) {
                mul = (double) it->second * x;
                return mul;
            }
        }
        return -1;
    }
};
