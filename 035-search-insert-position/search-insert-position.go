func searchInsert(nums []int, target int) int {
	n:=len(nums)
	l,r:=0,n

	for l<r{
		m:=l+(r-l)/2
		if nums[m]<target {
			l = m+1
		}else{
			r = m
		}
	}
	return l

}