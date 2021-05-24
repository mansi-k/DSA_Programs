// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
// Logic : Linked list cycle detection approach (as only constant space should be used)
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = nums.size();
        int p1 = nums[0];
        int p2 = nums[0];
        do {
            p1 = nums[p1]; // move 1 step
            p2 = nums[nums[p2]]; // move 2 step
        } while(p1 != p2); // stop when intersection is found
        p1 = nums[0];
        while(p1 != p2) { // to find the starting point of the cycle
            p1 = nums[p1]; // move both by 1 step
            p2 = nums[p2];
        }
        return p1;
    }
};
