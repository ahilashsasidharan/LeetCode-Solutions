class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        # Check Rows
        for row in board:
            vals = set()
            for cell in row:
                if cell in vals and cell != ".":
                    return False
                vals.add(cell)

        # Check Columns
        for col in range(len(board[0])):
            vals = set()
            for row in range(len(board)):
                cell = board[row][col]
                if cell in vals and cell != ".":
                    return False
                vals.add(cell)

        # Check 3 x 3 Grids
        for hgrid in range(int((len(board[0]) + 1) / 3)):
            for vgrid in range(int((len(board) + 1) / 3)):
                vals = set()
                for hind in range(hgrid * 3, hgrid * 3 + 3):
                    for vind in range(vgrid * 3, vgrid * 3 + 3):
                        cell = board[vind][hind]
                        if cell in vals and cell != ".":
                            return False
                        vals.add(cell)
                        
        return True