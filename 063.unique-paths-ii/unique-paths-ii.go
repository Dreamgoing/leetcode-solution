func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	//fmt.Printf("%v\n",len(obstacleGrid))
	dp:=make([][]int,len(obstacleGrid))
	n:=len(obstacleGrid)
	m:=len(obstacleGrid[0])
	for i := 0; i < len(dp); i++ {
		dp[i]=make([]int,len(obstacleGrid[0]))
	}

	for i := 0; i<n; i++{
		if obstacleGrid[i][0] ==1{
			break
		}else {
			dp[i][0] = 1
		}
	}

	for j := 0; j <m; j++ {
		if obstacleGrid[0][j] ==1{
			break
		}
		dp[0][j] = 1
	}

	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			if obstacleGrid[i][j]!=1{
				dp[i][j] = dp[i-1][j]+dp[i][j-1]
			}
		}
	}
	return dp[n-1][m-1]

	return 0
}