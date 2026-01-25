class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        rows = {}
        cols = {}
        grids = {}

        for i in range(9):
            rows[i] = set()
            cols[i] = set()
            grids[i] = set()

        for row in range(len(board)):
            vals = set()
            for col in range(len(board[0])):
                grid = int(row / 3) + 3 * int(col / 3)
                cell = board[row][col]
                
                if cell in rows[row] and cell != ".":
                    return False
                
                if cell in cols[col] and cell != ".":
                    return False
                
                if cell in grids[grid] and cell != ".":
                    return False

                rows[row].add(cell)
                cols[col].add(cell)
                grids[grid].add(cell)

        return True