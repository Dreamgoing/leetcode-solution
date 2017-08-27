func minPathSum(grid [][]int) int {
	dp:=make([][]int,len(grid))
	for i:=range dp{
		dp[i] = make([]int,len(grid[i]))
	}
	n:=len(dp)
	m:=len(dp[0])
	dp[0][0] = grid[0][0]
	for i := 1; i < n; i++ {
		dp[i][0] = dp[i-1][0]+grid[i][0]
	}
	for j := 1; j < m; j++ {
		dp[0][j] = dp[0][j-1]+grid[0][j]
	}
	for i := 1; i < n;i++ {
		for j := 1; j < m; j++ {
			dp[i][j] = minInt(dp[i][j-1],dp[i-1][j])+grid[i][j]
		}
	}
	return dp[n-1][m-1]
}

func minInt(a,b int)int  {
	if a > b {
		return b
	}else {
		return a
	}
}