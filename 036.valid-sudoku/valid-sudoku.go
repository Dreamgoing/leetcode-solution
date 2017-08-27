
func isValidSudoku(board [][]byte) bool {
	rowVis,colVis,subVis := [9][9]bool{},[9][9]bool{},[9][9]bool{}
	for i:= range board{
		for j:= range board[i]{
			if board[i][j]=='.' {
				continue
			}
			num:= board[i][j]-'0'-1
			subPos:= 3*(i/3)+j/3
			if rowVis[i][num] || colVis[j][num] || subVis[subPos][num] {
				return false
			}
			rowVis[i][num] = true
			colVis[j][num] = true
			subVis[subPos][num] = true
		}
	}

	return true
}