// https://leetcode.com/problems/find-the-town-judge/

class Solution {
// Logic : Each person is a graph node. We need to find a single sink node which has incoming edges from all other nodes except itself.
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int who[N+1]; // 2 arrays which will be indexed using person's label. Size N+1 as labels start from 1
        int whom[N+1]; // these 2 arrays will store who trusts whom
        for(int i=0;i<N+1;i++) {
            who[i] = 0;
            whom[i] = 0;
        }
        for(int i=0;i<trust.size();i++) {
            who[trust[i][0]] += 1; // if a trusts b then who[a]++
            whom[trust[i][1]] += 1; // if a trusts b then whom[b]++
        }
        for(int i=1;i<N+1;i++) {
            if(who[i]==0 && whom[i]==N-1) { // if a trusts nobody and everyone else trusts a, then a is the judge
                return i; // as question mentions that there is exactly 1 judge, so we directly return the first judge found
            }      
        }
        return -1;
    }
};
