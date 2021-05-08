// https://leetcode.com/problems/redundant-connection/

class Solution {
// Logic : Union find to search for redundant edge
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> red_edge; // to store redundant edge
        map<int,int> vrtx_grp; // map each vertex to a group
        map<int,vector<int>> grp_vrtx; // store list of vertices for each group (can use set, but it used more time to sort internally)
        int max_grpno = -1; // to assign unique group value for new nodes
        for(auto it=edges.begin();it<=edges.end();it++) {
            int a = *(it->begin()+0); 
            int b = *(it->begin()+1); 
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
                    red_edge.push_back(a); // this forms a cycle, hence it is a redundant edge
                    red_edge.push_back(b); // push these 2 vertices
                    return red_edge; // return redundant edge
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
        return red_edge; // return empty vectore if no redundant edge
    }
};
