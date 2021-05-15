// https://leetcode.com/problems/single-number/

class Solution {
// Logic :  XOR of 2 same numbers is 0 and XOR of any number with 0 is that number itself and XOR is associative. When all duplicates will be XORed the remaining number will be found.
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++) {
            x ^= nums[i];
        }
        return x;
    }
};
