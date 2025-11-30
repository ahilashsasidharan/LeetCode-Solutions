class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        Grid = [[0 for _ in range(n + 1)] for _ in range(m)]

        Grid[m-1] = [1] * n

        for i in range(m - 2, -1, -1):
            for j in range(n - 1, -1, -1):
                Grid[i][j] = Grid[i][j + 1] + Grid[i + 1][j]

        return Grid[0][0]