// https://leetcode.com/problems/regions-cut-by-slashes/

class Solution {
// Logic : Treat slashes and grid boundary as edges of a graph and count which edges form a cycle. Start from inner edges (given in input) and then boundary edges.
public:
    vector<vector<pair<int,int>>> edges;
    int regionsBySlashes(vector<string>& grid) {
        createGraph(grid); // Convert string grid to edges
        int cycles = 0; // to store number of cycles detected
        map<pair<int,int>,int> vrtx_grp; // map each vertex to a group
        map<int,vector<pair<int,int>>> grp_vrtx; // store list of vertices for each group
        int max_grpno = -1; // to assign unique group value for new nodes
        for(auto it=edges.begin();it!=edges.end();it++) {
            pair<int,int> a = *(it->begin()+0); 
            pair<int,int> b = *(it->begin()+1); 
            if(vrtx_grp.find(a)==vrtx_grp.end() && vrtx_grp.find(b)==vrtx_grp.end()) { // if both vertices are new
                max_grpno++; // assign them a new group number
                vrtx_grp[a] = max_grpno;
                vrtx_grp[b] = max_grpno; // assign group numbers to vertices
                grp_vrtx[max_grpno].push_back(a);
                grp_vrtx[max_grpno].push_back(b); // add vertices to their groups
            }
            else if(vrtx_grp.find(a)!=vrtx_grp.end() && vrtx_grp.find(b)==vrtx_grp.end()) { // if a is old but b is new vertex
                vrtx_grp[b] = vrtx_grp[a]; // assign a's group number to b
                grp_vrtx[vrtx_grp[a]].push_back(b); // add b to a's group list
            }
            else if(vrtx_grp.find(a)==vrtx_grp.end() && vrtx_grp.find(b)!=vrtx_grp.end()) { // if a is new but b is old vertex
                vrtx_grp[a] = vrtx_grp[b]; // assign b's group number to a
                grp_vrtx[vrtx_grp[b]].push_back(a); // add a to b's group list
            }
            else { // if both vertices are old
                int ag = vrtx_grp[a]; 
                int bg = vrtx_grp[b];
                if(ag == bg) { // if both are already in same group
                    cycles++;
                    cout << a.first << ',' << a.second << " --> " << b.first << ',' << b.second << endl;
                }
                else { // if both vertices are in different groups
                    if(grp_vrtx[ag] < grp_vrtx[bg]) { // if a's group has lesser number of nodes
                        for(auto jt=grp_vrtx[ag].begin();jt!=grp_vrtx[ag].end();jt++) { // get all nodes from a's group
                            vrtx_grp[*jt] = bg; // assign b's group to these nodes
                            grp_vrtx[bg].push_back(*jt); // merge a's group with b's group
                        }
                        grp_vrtx.erase(ag); // delete a's group number
                    }
                    else { // if a's group has equal or more number of nodes
                        for(auto jt=grp_vrtx[bg].begin();jt!=grp_vrtx[bg].end();jt++) { // get all nodes from b's group
                            vrtx_grp[*jt] = ag; // assign a's group to these nodes
                            grp_vrtx[ag].push_back(*jt); // merge b's group with a's group
                        }
                        grp_vrtx.erase(bg); // delete b's group number
                    }
                }
            }
        }
        return cycles; // return number of cycles detected
    }
    
    void createGraph(vector<string>& grid) {
        for(int i=0;i<grid.size();i++) { // create edges in the x,y format from the slashes
            for(int j=0;j<grid[i].length();j++) {
                char c = grid[i][j];
                vector<pair<int,int>> curedge;
                pair<int,int> a, b;
                if(c == '/') {
                    a = make_pair(i,j+1);
                    b = make_pair(i+1,j);
                    curedge.push_back(a);
                    curedge.push_back(b);
                    edges.push_back(curedge);
                }
                else if(c == '\\') {
                    a = make_pair(i,j);
                    b = make_pair(i+1,j+1);
                    curedge.push_back(a);
                    curedge.push_back(b);
                    edges.push_back(curedge);
                }
                cout << a.first << ',' << a.second << " --> " << b.first << ',' << b.second << endl;
            }
        }
        for(int i=0;i<=grid.size();i+=grid.size()) { // store grid boundary as edges
            for(int j=0;j<grid.size();j++) {
                vector<pair<int,int>> curedge;
                pair<int,int> a = make_pair(i,j);
                pair<int,int> b = make_pair(i,j+1);
                curedge.push_back(a);
                curedge.push_back(b);
                edges.push_back(curedge);
                curedge.clear();
                cout << a.first << ',' << a.second << " --> " << b.first << ',' << b.second << endl;
                a = make_pair(j,i);
                b = make_pair(j+1,i);
                curedge.push_back(a);
                curedge.push_back(b);
                edges.push_back(curedge);
                cout << a.first << ',' << a.second << " --> " << b.first << ',' << b.second << endl;
            }
        }
        cout << edges.size() << endl;
    }
};
