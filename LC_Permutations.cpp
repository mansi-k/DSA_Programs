// https://leetcode.com/problems/permutations/

class Solution {
// Logic : Remove 1 element at a time from the list and permute other elements recursively. Then append the removed element to all the permutations obtained. Append these permutations to the result list.
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result = getpermutes(nums);
        return result;
    }
    
    vector<vector<int>> getpermutes(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()==1) {
            result.push_back(nums);
            return result;
        }
        for(int i=0;i<nums.size();i++) {
            vector<int> tmp1 = nums;
            tmp1.erase(tmp1.begin()+i);
            vector<vector<int>> tmp2 = getpermutes(tmp1);
            for(int j=0;j<tmp2.size();j++) {
                tmp2[j].push_back(nums[i]);
            }
            result.insert(result.end(),tmp2.begin(),tmp2.end());
        }
        return result;
    }
};
