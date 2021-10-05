// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    int MinimumCost(vector<int> &sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int psum=0, p1, p2, cost=0;
        for(int i=0;i<sticks.size();i++) {
            pq.push(sticks[i]);
        }
        while(!pq.empty()) {
            if(psum>0)
                pq.push(psum);
            p1 = pq.top();
            pq.pop();
            if(!pq.empty()) {
                p2 = pq.top();
                pq.pop();
            } else {
                p2 = 0;
            }
            psum = p1+p2;
            cost += psum;
        }
        return cost;
    }
};
