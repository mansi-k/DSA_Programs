// https://leetcode.com/problems/subsets/

class Solution {
// Logic : Generate binary bitmaps of 0 to 2^n where n=nums.length. If the ith position in the bitmap is 1, then include ith number from nums to the current subset.
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int total = 1<<nums.size();
        vector<vector<int>> allsubsets(total);
        for(int i=0;i<total;i++) {
            for(int j=0;j<nums.size();j++) {
                if(i & 1<<j) {
                    allsubsets[i].push_back(nums[j]);
                }
            }
        }
        return allsubsets;
    }
};

// Code2:
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         ios_base::sync_with_stdio(false); 
//         cin.tie(NULL);
//         int total = pow(2,nums.size());
//         vector<string> binary(total);
//         vector<vector<int>> subsets(total);
//         binary[0] = "0";
//         for(int i=1;i<total;i++) {
//             binary[i] = binary[i/2] + to_string(i%2);
//             for(int j=binary[i].length()-1;j>0;j--) {
//                 if(binary[i][j]=='1') {
//                     subsets[i].push_back(nums[binary[i].length()-j-1]);
//                 }
//             }
//         }
//         return subsets;
//     }
// };
