func grayCode(n int) []int {
	res:=make([]int,0)
	for i := 0; i < 1<<uint(n); i++ {
		res = append(res,i^(i>>1))
	}
	return res

}