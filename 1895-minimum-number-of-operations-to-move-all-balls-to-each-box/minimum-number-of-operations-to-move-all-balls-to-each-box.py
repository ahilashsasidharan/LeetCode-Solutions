class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        result = []
        currBalls = 0
        prev = 0

        # Forward pass through the boxes
        # Populate result array with # of operations to move all balls left of the current box into the current box
        for balls in boxes:
            prev += currBalls
            result.append(prev)
            currBalls += int(balls)

        # Reset variables in preperation for backward pass
        currBalls = 0
        prev = 0


        for i in range(len(boxes) - 1, -1, -1):
            prev += currBalls
            result[i] += prev
            currBalls += int(boxes[i])

        return result