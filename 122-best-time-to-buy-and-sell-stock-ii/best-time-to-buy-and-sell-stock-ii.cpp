class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // carry the last minimum price of the stock and if you find a cheaper price replace it
        // if you have any opportunity to make profit you take it and record it

        int minPrice = prices[0];
        int profit = 0;

        for(int price : prices){
            if(price < minPrice){
                minPrice = price;
            }
            else{
                profit += price - minPrice;
                minPrice = price;
            }
        }

        return profit;
    }
};