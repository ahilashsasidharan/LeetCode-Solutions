class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        dictOfBalls = {}
        mostBalls = 0

        for i in range(lowLimit, highLimit + 1):
            
            # Retrieve 
            digitSum = 0
            n = i
            while n:
                digitSum += n % 10
                n //= 10
            
            # Add and get value from dictionary
            dictOfBalls[digitSum] = dictOfBalls.get(digitSum, 0) + 1

            # Update mostBalls Value 
            if mostBalls < dictOfBalls[digitSum] :
                mostBalls = dictOfBalls[digitSum] 

        return mostBalls