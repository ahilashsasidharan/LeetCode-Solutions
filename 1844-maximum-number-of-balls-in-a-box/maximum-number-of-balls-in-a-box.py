class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        dictOfBalls = {}
        mostBalls = 0

        for i in range(lowLimit, highLimit + 1):
            dig = str(i)
            digSum = 0
            for c in dig:
                digSum += int(c)
            
            temp = dictOfBalls.get(digSum, 0) + 1
            dictOfBalls[digSum] = temp

            if mostBalls < temp:
                mostBalls = temp

        return mostBalls

        