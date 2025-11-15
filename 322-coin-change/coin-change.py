class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        DP = [0] * (amount + 1)
        DP[0] = 0

        for i in range (1, amount + 1):
            # if i in coins: 
            #     coins[i] = 1
            #     continue

            nCoins = amount + 1

            for coin in coins:
                if i - coin < 0 or DP[i - coin] == amount + 1:
                    continue

                tCoins = 1 + DP[i - coin]
                
                if tCoins < nCoins:
                    nCoins = tCoins

            DP[i] = nCoins

        if DP[amount] == amount + 1:
            return -1 
        else:
            return DP[amount]
                    
