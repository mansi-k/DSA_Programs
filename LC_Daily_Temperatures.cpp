// https://leetcode.com/problems/daily-temperatures/

class Solution {
// Logic : Push the last temperature into stack and parse input from end. If current temperature is greater than stack top, then pop from stack until stack is empty (update no. of days as 0) or stack top is greater (update no. of days as position - current position) and then push the currect temperature. Otherwise just push the current temperature and update the no. of days as top position - current position. 
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        int n = temperatures.size();
        vector<int> warmtemp(n,0);
        stack<int> maxtemps;
        maxtemps.push(n-1);
        int toppos = n-1;
        for(int i=n-2;i>=0;i--) {
            toppos = maxtemps.top();
            // cout << temperatures[toppos] << endl;
            if(temperatures[i] < temperatures[toppos]) {
                warmtemp[i] = toppos - i;
                maxtemps.push(i);
            }
            else {
                while(!maxtemps.empty() && temperatures[toppos] <= temperatures[i]) {
                    maxtemps.pop();
                    if(!maxtemps.empty())
                        toppos = maxtemps.top();
                }
                if(maxtemps.empty()) {
                    warmtemp[i] = 0;
                }
                else {
                    warmtemp[i] = toppos - i;
                }
                maxtemps.push(i);
            }
        }
        return warmtemp;
    }
};
