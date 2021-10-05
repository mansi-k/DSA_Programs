// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int curmaxi=0, i=0, n=nums.size();
        k = min(n,k);
        deque<int> dq;
        dq.push_back(0);
        for(i=1;i<k;i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> maxes;
        maxes.push_back(nums[dq.front()]);
        for(i=k;i<n;i++) {
            while(!dq.empty() && dq.front() <= i-k) {  // remove indexes out of range of curr window
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {  // remove lesser elements
                dq.pop_back();
            }
            dq.push_back(i);
            maxes.push_back(nums[dq.front()]);  // max element in curr window will always be in the front
        }
        return maxes;
    }
};
