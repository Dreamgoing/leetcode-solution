func subsets(nums []int) [][]int {

	reversel(nums,0,len(nums)-1)
	tmp:=make([]int,0)
	res:=make([][]int,0)
	dfsSubset(&res,nums,0,tmp)
	return res
}

func dfsSubset(res *[][]int, nums []int, step int,tmp []int) {
	if step==len(nums) {
		//sort.Ints(tmp)
		dst:=make([]int,len(tmp))
		copy(dst,tmp)
		sort.Ints(dst)
		*res = append(*res,dst)

		return
	}
	dfsSubset(res,nums,step+1,tmp)
	dfsSubset(res,nums,step+1,append(tmp,nums[step]))

}
func reversel(nums []int,first,last int)  {
	for first<last{
		nums[first],nums[last] = nums[last],nums[first]
		first++
		last--
	}
}