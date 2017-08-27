///想如何使用快排的方法
func sortColors(nums []int)  {
	n:=len(nums)
	l,r:=0,n-1
	for l < r {
		//fmt.Printf("%v %v\n",l,r)
		if nums[l] == 0{
			l++
		}else if nums[l]==2 {
			tmpr:=r
			for tmpr>l{
				if nums[tmpr]<nums[l]{
					nums[l],nums[tmpr] = nums[tmpr],nums[l]
					break
				}
				tmpr--
			}
		}else {
			tmpr:=r
			found := false
			for tmpr>l{
				if nums[tmpr]<nums[l] {
					nums[l],nums[tmpr] = nums[tmpr],nums[l]
					found = true
					break
				}
				tmpr--
			}
			if !found{
				l++
			}

		}

		for nums[r]==2&&r>l{
			r--
		}
	}
}