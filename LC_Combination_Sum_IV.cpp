// https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int dp[1000];
    int dfs(vector<int> & nums,int target){
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        if(target==0)
            return 1;
        int sum = 0;
        for(auto x : nums){
            if(target-x>=0)
                sum+=dfs(nums,target-x);
        }
        return dp[target] = sum;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return dfs(nums,target);
    }
};
