func canJump(nums []int) bool {
	now:=-1
	maxpos:=0
	target:=len(nums)-1
	for maxpos>now {
		if maxpos>=target {
			return true
		}
		nextpos:=-1
		for i := maxpos; i > now; i-- {
			nextpos = maxInt1(nextpos,nums[i]+i)
		}
		now=maxpos
		maxpos=nextpos
		//fmt.Printf("%v\n",nextpos)

	}
	return false
}

func maxInt1(a int,b int) int  {
	if a<b {
		return b
	}else {
		return a
	}
}