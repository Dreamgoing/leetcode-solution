func fourSum(nums []int, target int) [][]int {
	var res [][]int
	sort.Ints(nums)
	n:=len(nums)
	for i := 0; i<n;i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i+1; j < n; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			l,r:=j+1,n-1
			twosum:=nums[i]+nums[j]
			for l<r{
				tmpsum:=twosum+nums[r]+nums[l]
				if l>j+1&&nums[l] ==nums[l-1]{
					l++
					continue
				}
				if tmpsum == target{
					res = append(res,[]int{nums[i],nums[j],nums[l],nums[r]})
					l++
					r--

				}else if tmpsum <target{
					l++
				}else {
					r--
				}
			}

		}
	}
	return res

}