func climbStairs(n int) int {
	dp:=make([][2]int,n+3)
	dp[0][0]=0
	dp[1][0]=1
	dp[2][0]=1
	dp[2][1]=1

	for i := 3;i<=n;i++ {
		dp[i][0] = dp[i-1][0]+dp[i-1][1]
		dp[i][1] = dp[i-2][0]+dp[i-2][1]
	}
	return dp[n][0]+dp[n][1]
}