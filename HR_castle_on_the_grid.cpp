// https://www.hackerrank.com/challenges/castle-on-the-grid/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.

//Logic: Consider this as a graph problem where each cell in the grid is a node of the graph. BFS on a graph gives us the shortest path from root to any node.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int rn = grid.size(); // no of rows
    int cn = grid[0].length(); // no of cols
    int color[rn][cn]; // 0:not-visisted  1:in-queue  2:explored
    for(int i=0;i<rn;i++) {
        for(int j=0;j<cn;j++) {
            color[i][j] = 0;  // initialize all to 0
        }
    }
    pair<int,int> parent[rn][cn]; // grid to store parent of each node
    queue<pair<int,int>> q; // BFS queue
    q.push(make_pair(startX,startY)); // push first node into the queue (main root)
    parent[startX][startY] = make_pair(startX,startY); // parent of the main root is itself
    color[startX][startY] = 1; // as main root is in queue
    bool flag = false;
    while(!q.empty() && !flag) { // repeat until all nodes are traversed (queue empty) or goal node is reached
        pair<int,int> curnode = q.front();  // get node from the start of the queue
        color[curnode.first][curnode.second] = 2; // set the status of the node as explored
        q.pop(); // remove the node from queue
        // traverse to right of the current node until columns end or X is found
        for(int i=curnode.second+1;i<cn && grid[curnode.first][i]!='X';i++) {
            if(color[curnode.first][i]==0) { // if the new node is not visited yet
                color[curnode.first][i] = 1; // mark its status as in-queue
                parent[curnode.first][i] = make_pair(curnode.first,curnode.second);
                q.push(make_pair(curnode.first,i)); // push it into queue
            }
            if(curnode.first==goalX && i==goalY) { // if it is the goal node
                flag = true; // mark goal node reached
                break; // stop traversing
            }
        }
        // traverse downwards from the current node until columns end or X is found
        for(int i=curnode.first+1;i<rn && grid[i][curnode.second]!='X';i++) {
            if(color[i][curnode.second]==0) { // if the new node is not visited yet
                color[i][curnode.second] = 1; // mark its status as in-queue
                parent[i][curnode.second] = make_pair(curnode.first,curnode.second);
                q.push(make_pair(i,curnode.second)); // push it into queue
            }
            if(i==goalX && curnode.second==goalY) { // if it is the goal node
                flag = true; // mark goal node reached
                break; // stop traversing
            }
        }
        // traverse to left of the current node until columns end or X is found
        for(int i=curnode.second-1;i>=0 && grid[curnode.first][i]!='X';i--) {
            if(color[curnode.first][i]==0) { // if the new node is not visited yet
                color[curnode.first][i] = 1; // mark its status as in-queue
                parent[curnode.first][i] = make_pair(curnode.first,curnode.second);
                q.push(make_pair(curnode.first,i)); // push it into queue
            }
            if(curnode.first==goalX && i==goalY) { // if it is the goal node
                flag = true; // mark goal node reached
                break; // stop traversing
            } 
        }
        // traverse downwards from the current node until columns end or X is found
        for(int i=curnode.first-1;i>=0 && grid[i][curnode.second]!='X';i--) {
            if(color[i][curnode.second]==0) { // if the new node is not visited yet
                color[i][curnode.second] = 1; // mark its status as in-queue
                parent[i][curnode.second] = make_pair(curnode.first,curnode.second);
                q.push(make_pair(i,curnode.second)); // push it into queue
            }
            if(i==goalX && curnode.second==goalY) { // if it is the goal node
                flag = true; // mark goal node reached
                break; // stop traversing
            }
        }
    }
    int moves=0;
    int i=goalX, j=goalY;
    if(flag) { // if goal node was reached
        while(i!=startX || j!=startY) { // reverse traversal - from goal node to start node by accessing parent nodes
            int x = parent[i][j].first; 
            j = parent[i][j].second;
            i = x;
            moves++; // count number of nodes in the path
        }
    }
    return moves; // return number of nodes in the shortest path
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
