// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> resvec;
    int target;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        target = n;
        vector<int> v;
        getcombos(k,v,0,1);
        return resvec;
    }
    
    void getcombos(int k, vector<int>& v, int sum, int pos) {
        if(sum > target) {
            return;
        }
        if(v.size()==k && sum == target) {
            resvec.push_back(v);
            return;
        }
        if(v.size() > k)
            return;
        for(;pos<10;pos++) {
            v.push_back(pos);
            getcombos(k,v,sum+pos,pos+1);
            v.pop_back();
        }
        return;
    }
};
