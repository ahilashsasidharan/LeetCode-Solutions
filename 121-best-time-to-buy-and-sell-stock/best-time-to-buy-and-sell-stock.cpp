class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int lowP = prices[0];

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] - lowP > maxP)
                maxP = prices[i] - lowP;
            if(prices[i] < lowP)
                lowP = prices[i];
        }

        return maxP;
    }
};