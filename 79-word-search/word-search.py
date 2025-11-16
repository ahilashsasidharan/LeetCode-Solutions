class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # Find all starting letters for word

        def backtrack(x, y, index, path):
            if index == len(word):
                return True

            if x - 1 >= 0 and board[x-1][y] == word[index] and [x-1, y] not in path:
                path.append([x-1, y])
                if backtrack(x - 1, y, index + 1, path):
                    return True
                path.pop()
            if x + 1 < len(board) and board[x+1][y] == word[index] and [x+1, y] not in path:
                path.append([x+1, y])
                if backtrack(x + 1, y, index + 1, path):
                    return True
                path.pop()
            if  y - 1 >= 0 and board[x][y-1] == word[index] and [x, y-1] not in path:
                path.append([x, y-1])
                if backtrack(x, y - 1, index + 1, path):
                    return True
                path.pop()
            if y + 1 < len(board[0]) and board[x][y+1] == word[index] and [x, y+1] not in path:
                path.append([x, y+1])
                if backtrack(x, y + 1, index + 1, path):
                    return True
                path.pop()

            return False

        for x in range(len(board)):
            for y in range(len(board[0])):
                if board[x][y] == word[0]:
                    path = [[x, y]]
                    if backtrack(x, y, 1, path):
                        return True

        return False