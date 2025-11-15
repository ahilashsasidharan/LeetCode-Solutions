class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        profit = 0
        # for buyday, buyprice in enumerate(prices):
        #     if buyday == len(prices) - 1:
        #         break
        #     for sellday in range(buyday + 1, len(prices)):
        #         profit = (prices[sellday] - buyprice) if (prices[sellday] - buyprice) > profit else profit

        # O(n) solution using the idea that setting min_price will always be a price you can buy befor current so keep track of lowest previous price which you can buy before future sell prices
        for price in prices:
            if min_price > price:
                min_price = price

            if price - min_price > profit:
                profit = price - min_price 

        return profit
        