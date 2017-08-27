func removeDuplicates(nums []int) int {
	pos:=-1
	for _,v:=range nums{
		if pos==-1||v!=nums[pos]{
			pos++
			nums[pos]=v
		}

	}
	return pos+1
}