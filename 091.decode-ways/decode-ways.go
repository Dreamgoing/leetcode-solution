func numDecodings(s string) int {
	n:=len(s)
	///
	if n==0 || s[0]=='0'{
		return 0
	}
	dp:=make([][2]int,n+1)

	///dp初始化条件
	dp[0][0] = 1
	dp[0][1] = 0

	val:=0
	if n>1 {
		val=int(byte(s[1])-'0')+10*int(byte(s[0]-'0'))
		if val<=26&&val>0 {
			dp[1][1] = 1
		}
		if s[1]>'0'&&s[1]<='9' {
			dp[1][0] = 1
		}
	}

	for i := 2; i < n; i++ {
		if s[i]>'0'&&s[i]<='9' {
			dp[i][0] = dp[i-1][0]+dp[i-1][1]
		}else {
			dp[i][0] = 0
		}
		val=int(byte(s[i])-'0')+10*int(byte(s[i-1]-'0'))
		if val>=10&&val<=26 {
			dp[i][1]=dp[i-2][0]+dp[i-2][1]
		}else {
			dp[i][1] = 0
		}
	}
	return dp[n-1][0]+dp[n-1][1]

}