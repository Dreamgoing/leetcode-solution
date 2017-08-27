func permute(nums []int) [][]int  {
	sort.Ints(nums)
	n:=len(nums)
	res:=make([][]int,0)
	src:=make([]int,n)
	copy(src,nums)
	res = append(res,src)
	for nextPermute(nums,0,n-1) {
		tmp:=make([]int,n)
		copy(tmp,nums)
		res = append(res,tmp)
	}
	//fmt.Printf("%v\n",nums)
	return res
}

func nextPermute(nums []int,first,last int) bool {
	if first==last {
		return false
	}
	r:=last

	it:=r
	itt:=r
	it--
	for it>=0{

		if nums[it] <nums[itt] {
			for nums[r]<=nums[it] {
				r--
			}
			nums[it],nums[r] = nums[r],nums[it]
			//fmt.Printf("ok")
			reverse(nums,itt,last)
			return true
		}
		it--
		itt--
	}


	reverse(nums,first,last)
	return false

}

func reverse(nums []int,first,last int)  {
	for first<last{
		nums[first],nums[last] = nums[last],nums[first]
		first++
		last--
	}
}