func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	n:=len(nums)
	var res [][]int

	for i := 0; i < n-2; i++ {
		if i>0 &&nums[i]==nums[i-1]{
			continue
		}
		j,k:=i+1,n-1
		for j<k{
			if j > i+1 && nums[j] == nums[j-1] {
				j++
				continue
			}
			tmpsum:=nums[j]+nums[k]+nums[i]
			if tmpsum==0{
				res=append(res,[]int{nums[i],nums[j],nums[k]})
				j++
				k--
			}else if tmpsum<0{
				j++
			}else {
				k--
			}
		}
	}
	return res
}