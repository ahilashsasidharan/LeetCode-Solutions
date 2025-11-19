class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])

        visited = set()

        def bfs(r, c):
            q = collections.deque()
            q.append((r, c))
            visited.add((r, c))

            while q:
                qr, qc = q.popleft()

                for rvals in range(rows):
                    if (rvals, qc) not in visited:
                        if matrix[rvals][qc] == 0:
                            q.append((rvals, qc))
                        else:
                            matrix[rvals][qc] = 0
                        visited.add((rvals, qc))

                for cvals in range(cols):
                    if (qr, cvals) not in visited:
                        if matrix[qr][cvals] == 0:
                            q.append((qr, cvals))   
                        else: 
                            matrix[qr][cvals] = 0
                    visited.add((qr, cvals))

        for row in range(rows):
            for col in range(cols):
                if (row, col) not in visited and matrix[row][col] == 0:
                    bfs(row, col)
                    visited.add((row, col))
