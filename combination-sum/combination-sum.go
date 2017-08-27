func combinationSum(candidates []int, target int) [][]int {
	res := make([][] int,0)
	dfsCombination(&res,candidates,[]int{},0,0,target)
	return res
}

func dfsCombination(res *[][]int,cand []int,now []int,step int,sum int,target int)  {

	if sum>target||step>=len(cand) {
		return
	}
	if sum==target{
		//fmt.Printf("now :%v  %v\n",now,sum)
		
		///内存问题
		tmp:=make([]int,len(now))
		copy(tmp,now)
		*res = append(*res,tmp)
		return
	}
	//fmt.Printf("%v\n",step)
	//print(now)

	dfsCombination(res,cand,append(now,cand[step]),step,sum+cand[step],target)
	dfsCombination(res,cand,now,step+1,sum,target)
}