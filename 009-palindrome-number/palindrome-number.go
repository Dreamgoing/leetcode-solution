func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	rx:=0
	tmpx:=x
	for tmpx>0{
		rx*=10
		rx += tmpx%10
		tmpx/=10
	}
	return rx==x
}