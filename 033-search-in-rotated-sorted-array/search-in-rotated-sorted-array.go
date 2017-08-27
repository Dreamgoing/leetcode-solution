
func search(nums []int, target int) int {
	n := len(nums)
	l,r:=0,n-1
	for l<r{
		m:=l+(r-l)/2
		if target>nums[m] {
			if nums[m]<=nums[r]{
				if target <=nums[r]{
					l = m+1
				}else {
					r = m
				}
			}else {
				l = m+1
			}
		}else {
			if nums[l]<=nums[m] {
				if target>=nums[l] {
					///
					r = m
				}else {
					///
					l = m+1
				}
			}else {
				r = m
			}
		}
	}
	if n>0&&l>=0&&nums[l]==target {
		return l
	}else {
		return -1
	}

}