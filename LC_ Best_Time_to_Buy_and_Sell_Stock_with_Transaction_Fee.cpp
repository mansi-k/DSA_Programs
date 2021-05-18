// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee); // profit I will have if I sell current stock
            hold = max(hold, cash - prices[i]); // remaining profit I will have if I buy current stock
        }
        return cash;
    }
};
