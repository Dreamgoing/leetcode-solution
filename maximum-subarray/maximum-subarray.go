func maxSubArray(nums []int) int {
	res:=-math.MaxInt64
	sum:=0
	for i:=range nums{
		sum+=nums[i]
		res = maxInt(res,sum)
		if sum<0 {
			sum = 0
		}
	}


	return res
}

func maxInt(a int,b int) int  {
	if a<b {
		return b
	}else {
		return a
	}
}