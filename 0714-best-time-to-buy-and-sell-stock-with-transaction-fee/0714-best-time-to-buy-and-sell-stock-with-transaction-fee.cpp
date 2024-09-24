class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0; 
        int hold = -prices[0];
        for (int i = 0; i < prices.size(); i++) {
            int prevCash = cash;
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, prevCash - prices[i]);
        }
        return cash;
    }
};