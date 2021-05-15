// https://leetcode.com/problems/counting-bits/submissions/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ones(num+1);
        ones[0] = 0;
        for(int i=1;i<=num;i++) {
            ones[i] = i%2 + ones[i/2];
        }
        return ones;
    }
};
