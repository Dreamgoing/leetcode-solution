func searchRange(nums []int, target int) []int {
	
	l:=lowerBound(nums,target)
	r:=upperBound(nums,target)

	//fmt.Printf("%v %v\n",l,r)
	if l==len(nums){
		///lower_bound no found
		return []int{-1,-1}
	}else {
		if nums[l]==target&&nums[l]==nums[r-1] {
			return []int{l,r-1}
		}else {
			return []int{-1,-1}
		}
	}

}

func lowerBound(nums []int,target int) int{
	l,r:=0,len(nums)
	for l < r {
		m:=l+(r-l)/2
		if target>nums[m] {
			l = m+1
		}else {
			r = m
		}
	}
	return l
}

func upperBound(nums []int,target int) int  {
	l,r:=0,len(nums)
	for l<r{
		m:=l+(r-l)/2
		if target>=nums[m]{
			l = m+1
		}else {
			r = m
		}
		
	}
	return l
}