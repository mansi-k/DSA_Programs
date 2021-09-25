// https://leetcode.com/problems/combination-sum-ii/

// DFS on recursion tree

class Solution {
public:
    vector<vector<int>> resvec;
    int target;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int tgt) {
        target = tgt;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        getcombos(candidates,v,0,0);
        return resvec;
    }
    
    void getcombos(vector<int>& candidates, vector<int>& v, int sum, int pos) {
        if(sum > target) {
            return;
        }
        if(sum == target) {
            resvec.push_back(v);
            return;
        }
        if(pos >= candidates.size()) {
            return;
        }
        int idx = pos;
        for(;pos<candidates.size();pos++) {
            if(pos>idx && candidates[pos]==candidates[pos-1]) // to avoid duplicate consideration
                continue;
            int t = candidates[pos];
            v.push_back(t);
            getcombos(candidates,v,sum+t,pos+1);
            v.pop_back();
        }
        return;
    }
};
