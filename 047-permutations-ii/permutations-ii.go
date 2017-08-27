func permuteUnique(nums []int) [][]int {
	res:=make([][]int,0)
	sort.Ints(nums)
	tmp:=make([]int,len(nums))
	copy(tmp,nums)
	res=append(res,tmp)
	for nextPermuteUnique(nums){
		//fmt.Printf("%v\n",nums)
		tmp = make([]int,len(nums))
		copy(tmp,nums)
		res=append(res,tmp)
	}
	return res
}

func nextPermuteUnique(nums []int)bool {
	n:=len(nums)
	it:=n-1
	itt:=it-1
	r:=n-1
	for itt>=0{
		if nums[itt]<nums[it] {
			for nums[r]<=nums[itt] {
				r--
			}
			nums[itt],nums[r]=nums[r],nums[itt]
			reverseArray(nums,it,len(nums)-1)
			return true
		}
		itt--
		it--
	}
	reverseArray(nums,0,len(nums)-1)
	return false
}

///将区间[l,r]翻转
func reverseArray(nums []int,first,last int)  {
	for first<last{
		nums[first],nums[last] = nums[last],nums[first]
		first++
		last--
	}
}