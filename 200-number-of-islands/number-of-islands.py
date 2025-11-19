class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        visited = set()
        islands = 0

        def bfs(r, c):
            q = collections.deque()
            visited.add((r, c))
            q.append((r,c))

            while q:
                qr, qc = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for dr, dc in directions:
                    nr = qr + dr
                    nc = qc + dc
                    if nr in range(rows) and nc in range(cols) and (nr, nc) not in visited and grid[nr][nc] == "1":
                        q.append((nr,nc))
                        visited.add((nr,nc))

        for row in range(rows):
            for col in range(cols):
                if (row, col) not in visited and grid[row][col] == "1":
                    bfs(row, col)
                    islands += 1

        return islands                