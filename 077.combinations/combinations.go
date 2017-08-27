
func combine(n int, k int) [][]int {
	res:=make([][]int,0)
	dfsCombine(&res,[]int{},n,k,1,0)
	return res
}

func dfsCombine(res *[][]int,now []int,n int,k int,v int,step int)  {

	if step == k {
		tmp:=make([]int,len(now))
		copy(tmp,now)
		*res = append(*res,tmp)
		return
	}
	if v>n {
		return
	}
	now = append(now,v)
	dfsCombine(res,now,n,k,v+1,step+1)
	now = now[:len(now)-1]
	dfsCombine(res,now,n,k,v+1,step)
}