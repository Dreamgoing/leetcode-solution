func subsetsWithDup(nums []int) [][]int {
	res:=make([][]int,0)
	sort.Ints(nums)
	dfsSubsetWithDup(&res,nums,[]int{},0)
	return res
}

func dfsSubsetWithDup(res *[][]int,nums []int,now []int,first int)  {
	if first>=len(nums) {
		tmp:=make([]int,len(now))
		copy(tmp,now)
		*res = append(*res,tmp)
		return
	}

	for i := first;i <= len(nums);i++{

		if i==len(nums) {
			dfsSubsetWithDup(res,nums,now,i+1)
			break
		}
		///去重
		if i>first&&nums[i]==nums[i-1]{
			continue
		}


		now = append(now,nums[i])
		dfsSubsetWithDup(res,nums,now,i+1)
		now = now[:len(now)-1]

	}


}