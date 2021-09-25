// https://leetcode.com/problems/combination-sum/

class Solution 
{
    vector<vector<int>> result;
    int target;
    void check_eq(vector<int>& candidates, vector<int> &v,int sum, int next)
    {
        if (sum > target) return;
        if (sum == target)
        {
            result.push_back(v);
            return;
        }
        for (; next < candidates.size(); next++)
        {
            int t = candidates[next];
            v.push_back(t);
            check_eq(candidates, v, sum + t, next);
            v.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int _target) 
    {
        target = _target;
        vector<int> v;
        check_eq(candidates, v, 0, 0);
        return result;
    }
};
