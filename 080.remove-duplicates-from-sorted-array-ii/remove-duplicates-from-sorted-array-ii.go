func removeDuplicates(nums []int) int {
	n:=len(nums)
	pos:=0

	for i:=0;i<n;i++{
		if i+1 >= n {
			nums[pos] = nums[i]
			pos++
		}else {
			if nums[i]!=nums[i+1] {
				nums[pos] = nums[i]
				pos++
			}else {
				nums[pos] = nums[i]
				pos++
				nums[pos] = nums[i+1]
				pos++
				for i+1<n&&nums[i]==nums[i+1]{
					i++
				}
			}
		}

	}
	return pos

}